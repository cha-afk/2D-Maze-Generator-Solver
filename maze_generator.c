#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 15
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'
#define VISITED '.'

char maze[HEIGHT][WIDTH];

int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void generateMaze(int x, int y);
void guaranteePath();
void printMaze();
int solveMaze(int x, int y);

int main() {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = WALL;
        }
    }

    generateMaze(1, 1);

    guaranteePath();

    maze[1][1] = START;
    maze[HEIGHT - 2][WIDTH - 2] = END;

    printMaze();

    printf("\nSolving the maze...\n");
    if (solveMaze(1, 1)) {
        printf("\nSolution found:\n");
    } else {
        printf("\nNo solution exists.\n");
    }
    printMaze();

    return 0;
}

void generateMaze(int x, int y) {
    maze[y][x] = PATH;
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int tempX = directions[i][0];
        int tempY = directions[i][1];
        directions[i][0] = directions[r][0];
        directions[i][1] = directions[r][1];
        directions[r][0] = tempX;
        directions[r][1] = tempY;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0] * 2;
        int ny = y + directions[i][1] * 2;
        if (nx > 0 && nx < WIDTH - 1 && ny > 0 && ny < HEIGHT - 1 && maze[ny][nx] == WALL) {
            maze[y + directions[i][1]][x + directions[i][0]] = PATH;
            generateMaze(nx, ny);
        }
    }
}

void guaranteePath() {
    int x = 1, y = 1;
    while (x < WIDTH - 2 || y < HEIGHT - 2) {
        if (x < WIDTH - 2) x++;
        if (y < HEIGHT - 2) y++;
        maze[y][x] = PATH;
    }
}

void printMaze() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int solveMaze(int x, int y) {
    if (maze[y][x] == END) {
        return 1;
    }
    if (maze[y][x] != PATH && maze[y][x] != START) {
        return 0;
    }

    maze[y][x] = VISITED;

    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
            if (solveMaze(nx, ny)) {
                return 1;
            }
        }
    }
    if (maze[y][x] != START) {
        maze[y][x] = PATH;
    }
    return 0;
}
