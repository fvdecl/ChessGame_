# ChessGame

ChessGame is a board game "Chess" implemented in C++ using the [SFML 2.5.1](https://www.sfml-dev.org/) library for the graphical interface. The project is built following the **Model-View-Controller (MVC)** pattern and developed in **Visual Studio 2019** with support for **C++14** and **ISO C11** for C compatibility.

---

## 📁 Project Structure

ChessGame/
├─ References/ # External dependencies (Boost, SFML 2.5.1)
├─ Header Files/ # Header files
│ ├─ Controller/
│ │ ├─ BoardController.h
│ │ ├─ Game.hpp
│ │ └─ GameSession.h
│ ├─ Model/
│ │ ├─ Board.hpp
│ │ ├─ Cell.hpp
│ │ ├─ Bishop.h
│ │ ├─ Horse.h
│ │ ├─ King.h
│ │ ├─ Pawn.h
│ │ ├─ Rook.h
│ │ └─ IPawnMovement.h
│ └─ View/
│ ├─ BoardView.hpp
│ ├─ CellView.hpp
│ ├─ GameView.h
│ ├─ PawnView.h
│ └─ TextView.h
├─ Source Files/ # Source files
│ ├─ Controller/
│ │ ├─ BoardController.cpp
│ │ ├─ Game.cpp
│ │ └─ GameSession.cpp
│ ├─ Model/
│ │ ├─ Board.cpp
│ │ ├─ Cell.cpp
│ │ ├─ Bishop.cpp
│ │ ├─ Horse.cpp
│ │ ├─ King.cpp
│ │ ├─ Pawn.cpp
│ │ ├─ Rook.cpp
│ │ └─ IPawnMovement.cpp
│ └─ View/
│ ├─ BoardView.cpp
│ ├─ CellView.cpp
│ ├─ GameView.cpp
│ ├─ PawnView.cpp
│ └─ TextView.cpp
├─ Resource Files/ # Icons
│ ├─ chess_pawn_logo.ico
│ ├─ Resource.rc
│ 
└─ README.md # This file

---

## 🏗 Technologies Used

- **C++14** and **ISO C11** for C components  
- **SFML 2.5.1** — for graphics and user interaction  
- **Visual Studio 2019** — development environment  
- **Boost** — auxiliary libraries (if needed)  

---

## 🧩 MVC Architecture

**Model** — game logic and state:  
- `Board`, `Cell`, pieces (`Bishop`, `Horse`, `King`, `Pawn`, `Rook`)  
- `IPawnMovement` interface implementing basic logic for other pieces  

**View** — game visualization:  
- `BoardView`, `CellView`, `GameView`, `PawnView`, `TextView`  
- Responsible for rendering the board, pieces, and interface  

**Controller** — game flow management:  
- `BoardController` — move handling  
- `Game` — manages game logic and turn sequence  
- `GameSession` — controls the game session and rules  

---

## 🖼 Resources

- **Assets/Texture/** — original piece textures (`r.png`)  
- **Assets/chess_figure/** — sliced piece sprites  
- **Assets/split.py** — Python script for sprite slicing  
- **Fonts/** — fonts for the interface  

---

## ⚡ Build and Run

1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/ChessGame.git
