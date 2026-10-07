# Car Dodge — Computer Graphics Project

## What it does

Car Dodge is a small 2D game written in C. Move the green car left and right to avoid the other cars. The score rises as you survive. After a crash, press a key to play again or press Escape to quit.

## What you need to run it

The program uses the classic BGI `graphics.h` library, which is included with some Turbo C setups and is also available through WinBGIm. Open `car_dodge.c` in a compatible C environment. In `main`, change the BGI folder path (`C:\TC\BGI`) if the library is installed somewhere else, then compile and run it. The program also uses `conio.h` and `dos.h`, so a standard C compiler by itself is not enough.

## Short presentation script

> My project is called Car Dodge. I wrote it in C using the BGI graphics library. The screen is a two-dimensional coordinate plane: x controls left and right, and y controls up and down. I used graphics functions such as `bar`, `line`, and `rectangle` to draw the road, lane markings, and cars. A car is made from simple shapes like a body, windows, and wheels.
>
> The keyboard changes the x-position of the green car. Each time around the game loop, the other cars move down and the lane markings move too. That makes it look like the car is driving forward. I check whether the player's car overlaps another car by comparing their x and y positions. If they overlap, the game shows the score and stops that round.
>
> The computer graphics ideas I used are 2D coordinates, drawing with geometric shapes, moving objects by changing their coordinates, animation, and collision detection.

## Graphics concepts

1. **2D coordinates:** The screen uses x and y positions. The top-left is close to `(0, 0)`. x increases to the right, and y increases downward.
2. **Geometric shapes:** `bar` draws filled rectangles; `line` draws lane markings and details; `rectangle` outlines the body of a car. Combining simple shapes makes a recognizable car.
3. **Object movement:** The player's x-position changes when a key is pressed. Traffic and road markings move by changing their y-positions.
4. **Animation:** A loop updates and redraws the scene. `delay(30)` sets a short pause between frames.
5. **Collision detection:** `hasCollided` checks whether the rectangular areas occupied by two cars overlap.
6. **Color:** BGI color constants fill the road, cars, windows, and grass so the objects can be distinguished.

## How the game loop works

1. Read the keyboard and move the green car.
2. Keep the green car inside the road.
3. Move traffic and lane markings down the screen.
4. Occasionally add another traffic car and update the score.
5. Draw the road and cars again.
6. Check for a collision. If there is one, show the score.

## Questions you might be asked

**Why do the road markings move?**  
Moving the road gives the impression that the player's car is moving forward. It is simpler than moving the car up the screen.

**What is a coordinate in this program?**  
It is a pair of numbers that gives a point on the screen. For example, `playerX` and `playerY` locate the player's car.

**How did you draw a car?**  
I combined filled rectangles and lines. The body, window, and wheels are separate shapes drawn at positions relative to the car.

**How does the collision check work?**  
The program compares the left, right, top, and bottom positions of the two cars. If their rectangular areas overlap, it reports a collision.

**Which graphics library did you use?**  
I used BGI `graphics.h`, which provides functions such as `bar`, `line`, and `rectangle` for drawing on the screen.
