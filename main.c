#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

void initialize_grid(int grid[HEIGHT][WIDTH]);
void print_grid(int grid[HEIGHT][WIDTH]);
int count_neighbors(int grid[HEIGHT][WIDTH], int x, int y);
void update_grid(int grid[HEIGHT][WIDTH], int new_grid[HEIGHT][WIDTH]);

int main() {
    int current_grid[HEIGHT][WIDTH];
    int next_grid[HEIGHT][WIDTH];
    
    srand(time(NULL));
    initialize_grid(current_grid);
    
    while (1) {
        printf("\033[H\033[J");
        print_grid(current_grid);
        
        update_grid(current_grid, next_grid);
        
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                current_grid[y][x] = next_grid[y][x];
            }
        }
        
        usleep(200000);
    }
    
    return 0;
}

void initialize_grid(int grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = rand() % 4 == 0 ? 1 : 0;
        }
    }
}

void print_grid(int grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf(grid[y][x] ? "#" : " ");
        }
        printf("\n");
    }
}

int count_neighbors(int grid[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            
            int nx = (x + dx + WIDTH) % WIDTH;
            int ny = (y + dy + HEIGHT) % HEIGHT;
            
            count += grid[ny][nx];
        }
    }
    return count;
}

void update_grid(int grid[HEIGHT][WIDTH], int new_grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = count_neighbors(grid, x, y);
            
            if (grid[y][x]) {
                new_grid[y][x] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                new_grid[y][x] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
}