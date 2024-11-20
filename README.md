# 🧩 Random 2D/3D Maze Generator and Solver

## 📜 Overview
This project is a **maze generator and solver** written in **C** that creates random mazes for both 2D and 3D spaces. The program ensures that every generated maze has at least one guaranteed path from the start (`S`) to the end (`E`). It also includes a maze-solving algorithm using **Depth First Search (DFS)**.

---

## ✨ Features
- ✅ **Random Maze Generation**:
  - Creates unique 2D mazes for every run.
  - Option to expand to 3D mazes with multiple layers.
- 🛠 **Guaranteed Solvability**:
  - Ensures there's always a path from the start (`S`) to the end (`E`).
- 🤖 **Maze Solver**:
  - Uses DFS to solve the maze and visualize the solution.
  - Displays the solved path in the terminal.
- 🖥 **Terminal Visualization**:
  - Prints the maze layout and solution directly in the terminal.

---

## 📂 Project Structure
├── maze_generator.c # Main C file

├── README.md # Documentation for the project

## 🚀 Getting Started
### 1. Prerequisites
- A **C compiler** (e.g., GCC).
- A Unix-based system or Windows with a compatible terminal.

### 2. Clone the Repository
``` git clone https://github.com/your-repo-name/random-maze-generator.git cd random-maze-generator```

### 3. Compile the Code
``` gcc -o maze_generator maze_generator.c```

### 4. Run the Program
``` ./maze_generator```

## 🔧 How It Works
1. Random Maze Generation
  The program generates a grid-based maze filled with walls (#).
  Uses recursive backtracking to carve out random paths in the maze.
  Ensures at least one direct path from the start (S) to the end (E).
2. Maze Solver
  Implements Depth First Search (DFS) to navigate the maze.
  Marks visited paths with . to visualize the solving process.
  Backtracks if a dead-end is reached.
3. 3D Maze Extension (Optional)
  A 3D maze uses a 3D array (maze[layer][row][col]).
  Includes vertical movements (up and down) between layers.


## 🖼 Example Outputs

### Random 2D Maze

```
# # # # # # # # # # # # # # # 
# S         #       #       # 
# #   # #   #   #   #   #   # 
#       #   #   #   #   #   # 
#   #       # # #   #   # # # 
#   #   #       #           # 
# # #   # #     # # # # #   # 
#       #       #           # 
#   # # #   # #     # # #   # 
#   #       #       #       # 
#   #   # # #   #     # # # # 
#       #       #           # 
# # #   # # # # # # # #     # 
# # #                     E # 
# # # # # # # # # # # # # # # 

Solving the maze...

Solution found:
# # # # # # # # # # # # # # # 
# . . . . . #       #       # 
# #   # # . #   #   #   #   # 
#       # . #   #   #   #   # 
#   # . . . # # #   #   # # # 
#   # . #       #           # 
# # # . # #     # # # # #   # 
# . . . #       #           # 
# . # # #   # #     # # #   # 
# . #       #       #       # 
# . #   # # #   #     # # # # 
# . . . #       #           # 
# # # . # # # # # # # #     # 
# # # . . . . . . . . . . E # 
# # # # # # # # # # # # # # # 
```
## 🛠 Customization
### Change Maze Dimensions
To change the maze size, modify the WIDTH and HEIGHT macros in the code:
```c 
#define WIDTH 20
#define HEIGHT 20
```

## Enable 3D Maze
Replace the 2D maze array with a 3D array:
  ```c char maze[LAYERS][HEIGHT][WIDTH];```

## 🤔 Troubleshooting
Maze is Unsolvable
This is a random maze generator and solver, so it is normal for some cases to have no solution due to the randomness of the maze generation process
Compilation Errors:
Verify that your compiler supports ANSI C.

## 📜 License 
This project is open-source and distributed under the MIT License.

## Feel free to customize or expand this program! ✨
