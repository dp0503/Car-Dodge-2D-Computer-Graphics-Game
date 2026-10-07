
*/
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>

#define ROAD_LEFT 120
#define ROAD_RIGHT 520
#define ROAD_WIDTH (ROAD_RIGHT - ROAD_LEFT)
#define MAX_TRAFFIC 8
#define CAR_W 34
#define CAR_H 54

struct Car { int x, y, active, color; };
int laneX[3] = {187, 320, 453};
struct Car traffic[MAX_TRAFFIC];
int playerX, playerY, roadOffset, frameCount, score, carSpeed;

void drawCar(int x, int y, int bodyColor)
{
    /* Draw the car's parts relative to its top-left corner. */
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x - 4, y + 7, x + 2, y + 19);
    bar(x + CAR_W - 2, y + 7, x + CAR_W + 4, y + 19);
    bar(x - 4, y + 35, x + 2, y + 47);
    bar(x + CAR_W - 2, y + 35, x + CAR_W + 4, y + 47);
    setcolor(bodyColor);
    setfillstyle(SOLID_FILL, bodyColor);
    bar(x + 3, y, x + CAR_W - 3, y + CAR_H);
    rectangle(x + 3, y, x + CAR_W - 3, y + CAR_H);
    setcolor(LIGHTCYAN);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(x + 8, y + 10, x + CAR_W - 8, y + 22);
    setcolor(WHITE);
    line(x + 8, y + 25, x + CAR_W - 8, y + 25);
    setcolor(YELLOW);
    putpixel(x + 8, y + 3, YELLOW);
    putpixel(x + CAR_W - 8, y + 3, YELLOW);
}

void drawRoad(void)
{
    int y;
    setfillstyle(SOLID_FILL, GREEN);
    bar(0, 0, getmaxx(), getmaxy());
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(ROAD_LEFT, 0, ROAD_RIGHT, getmaxy());
    setcolor(WHITE);
    line(ROAD_LEFT + 8, 0, ROAD_LEFT + 8, getmaxy());
    line(ROAD_RIGHT - 8, 0, ROAD_RIGHT - 8, getmaxy());
    setcolor(LIGHTGRAY);
    for (y = -60 + roadOffset; y < getmaxy(); y += 90) {
        line(ROAD_LEFT + ROAD_WIDTH / 3, y,
             ROAD_LEFT + ROAD_WIDTH / 3, y + 42);
        line(ROAD_LEFT + 2 * ROAD_WIDTH / 3, y,
             ROAD_LEFT + 2 * ROAD_WIDTH / 3, y + 42);
    }
}

void drawScene(void)
{
    int i;
    char scoreText[40];
    drawRoad();
    for (i = 0; i < MAX_TRAFFIC; i++)
        if (traffic[i].active)
            drawCar(traffic[i].x, traffic[i].y, traffic[i].color);
    drawCar(playerX, playerY, LIGHTGREEN);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    sprintf(scoreText, "Score: %d", score);
    outtextxy(15, 15, scoreText);
    outtextxy(15, 34, "Move: LEFT / RIGHT arrows or A / D");
}

void resetGame(void)
{
    int i;
    playerX = laneX[1] - CAR_W / 2;
    playerY = 390;
    roadOffset = frameCount = score = 0;
    carSpeed = 5;
    for (i = 0; i < MAX_TRAFFIC; i++) traffic[i].active = 0;
}

void addTraffic(void)
{
    int i, lane = random(3);
    for (i = 0; i < MAX_TRAFFIC; i++) {
        if (!traffic[i].active) {
            traffic[i].x = laneX[lane] - CAR_W / 2;
            traffic[i].y = -CAR_H;
            traffic[i].active = 1;
            traffic[i].color = 9 + random(6);
            return;
        }
    }
}

int hasCollided(void)
{
    int i;
    for (i = 0; i < MAX_TRAFFIC; i++) {
        if (traffic[i].active &&
            playerX < traffic[i].x + CAR_W - 5 &&
            playerX + CAR_W - 5 > traffic[i].x &&
            playerY < traffic[i].y + CAR_H - 5 &&
            playerY + CAR_H - 5 > traffic[i].y)
            return 1;
    }
    return 0;
}

void updateTraffic(void)
{
    int i;
    for (i = 0; i < MAX_TRAFFIC; i++) {
        if (traffic[i].active) {
            traffic[i].y += carSpeed;
            if (traffic[i].y > getmaxy()) traffic[i].active = 0;
        }
    }
}

int playGame(void)
{
    int key, crashed = 0;
    resetGame();
    while (!crashed) {
        if (kbhit()) {
            key = getch();
            if (key == 0 || key == 224) {
                key = getch();
                if (key == 75) playerX -= 12;
                if (key == 77) playerX += 12;
            } else {
                if (key == 'a' || key == 'A') playerX -= 12;
                if (key == 'd' || key == 'D') playerX += 12;
                if (key == 27) return 0;
            }
        }
        if (playerX < ROAD_LEFT + 15) playerX = ROAD_LEFT + 15;
        if (playerX > ROAD_RIGHT - CAR_W - 15)
            playerX = ROAD_RIGHT - CAR_W - 15;
        frameCount++;
        roadOffset = (roadOffset + carSpeed) % 90;
        if (frameCount % 35 == 0) addTraffic();
        if (frameCount % 300 == 0 && carSpeed < 9) carSpeed++;
        updateTraffic();
        score = frameCount / 3;
        drawScene();
        crashed = hasCollided();
        delay(30);
    }
    setfillstyle(SOLID_FILL, BLACK);
    bar(145, 185, 495, 285);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(225, 205, "CRASH!");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    {
        char finalScore[40];
        sprintf(finalScore, "Your score: %d", score);
        outtextxy(235, 245, finalScore);
    }
    outtextxy(170, 270, "Press a key to play again or ESC to quit");
    key = getch();
    return key != 27;
}

int main(void)
{
    int graphicsDriver = DETECT, graphicsMode, again = 1;
    /* Change this path to your BGI folder if needed (for example C:\\TC\\BGI). */
    initgraph(&graphicsDriver, &graphicsMode, "C:\\TC\\BGI");
    if (graphresult() != grOk) {
        printf("Could not start graphics.h. Check the BGI folder path.\n");
        printf("Change C:\\TC\\BGI in the source code to your BGI folder.\n");
        return 1;
    }
    randomize();
    while (again) again = playGame();
    closegraph();
    return 0;
}
