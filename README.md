# 🚗 Car Dodge – 2D Computer Graphics Game

> A 2D Computer Graphics project developed to demonstrate fundamental graphics concepts through an interactive car-dodging game.

Project live on - " https://car-dodge-2d-game.vercel.app/ "

## 📌 About

This project is a simple **Car Dodge** game developed using **C and BGI `graphics.h`**.

The player controls a green car and moves it left or right to avoid incoming traffic. The game demonstrates important Computer Graphics concepts such as **2D coordinates, geometric shapes, object movement, animation, color, and collision detection**.

## ✨ Features

- 🚗 **Player Car** – Control the green car using keyboard input
- 🛣️ **Road Animation** – Moving lane markings create a driving effect
- 🚘 **Traffic Cars** – Random traffic cars appear on different lanes
- 🎮 **Keyboard Controls** – Use Left/Right Arrow keys or A/D
- 🏆 **Score System** – Score increases as the player survives
- 💥 **Collision Detection** – Detects when the player hits another car
- 🔄 **Restart Game** – Play again after a crash
- ⚡ **Increasing Difficulty** – Traffic speed increases as the game continues
- 🎨 **Graphics Drawing** – Cars and road are created using basic shapes

## 🧠 Computer Graphics Concepts

### 📍 2D Coordinates

The game uses **X and Y coordinates** to position the player car, traffic cars, road, and other objects on the screen.

- **X-axis** → Controls horizontal position
- **Y-axis** → Controls vertical position

### 🔷 Geometric Shapes

Cars and road elements are created using basic graphical shapes such as:

- Rectangles
- Lines
- Filled shapes

These simple shapes are combined to create the game objects.

### 🔄 Object Movement

The player's X-position changes when the user presses the control keys.

Traffic cars and road markings move vertically by changing their Y-position.

### 🎞️ Animation

The game continuously updates and redraws the scene to create movement.

```text
Keyboard Input
      ↓
Move Player
      ↓
Move Traffic
      ↓
Update Road
      ↓
Update Score
      ↓
Draw Scene
      ↓
Check Collision
      ↓
Continue / Game Over
```

### 💥 Collision Detection

The program checks whether the player's car overlaps with an incoming traffic car.

If the two cars overlap, a collision is detected and the game ends.

## 🎮 Game Controls

| Key | Action |
|---|---|
| ⬅️ Left Arrow / A | Move Left |
| ➡️ Right Arrow / D | Move Right |
| ⎋ ESC | Quit the Game |

## 🏆 Scoring

The score increases continuously while the player survives.

The longer the player avoids traffic, the higher the score becomes.

## 🛠️ Technologies

- **C** – Game programming
- **BGI `graphics.h`** – Computer graphics and drawing
- **conio.h** – Keyboard input
- **dos.h** – Timing and delay functions
- **Turbo C / WinBGIm** – Compatible environments for running the project

## 📁 Project Structure

```text
├── car_dodge.c
├── index.html
├── project-explanation.md
└── README.md
```

## 🔄 Project Workflow

```text
Start Game
     ↓
Control Player Car
     ↓
Avoid Traffic
     ↓
Traffic & Road Animation
     ↓
Increase Score
     ↓
Collision Detection
     ↓
Game Over
     ↓
Play Again / Exit
```

The project demonstrates how basic **Computer Graphics concepts** can be combined with programming logic to create an interactive 2D game.

## 👨‍💻 Team

| Member | GitHub |
|---|---|
| Devarsh | [@dp0503](https://github.com/dp0503) |
| Dhruv | [@dhruvkabra05](https://github.com/dhruvkabra05) |
| Krishna | [@krishnaa0212](https://github.com/krishnaa0212) |
| Prishi | [@Prishii17](https://github.com/Prishii17) |
| Vishesh | [@visheshjainz](https://github.com/visheshjainz) |

## 🎓 Academic Project

Developed as an academic **Computer Graphics project** to demonstrate:

**C Programming + Computer Graphics + Animation + Collision Detection**
