# Game of Life in C

This is a simple implementation of Conway's "Game of Life" written in C. It runs in a Linux terminal and displays the game's progression using ASCII characters.

## Compilation and Execution

To compile and run the program, follow these steps:

1. Clone the repository:
    ```bash
    git clone https://github.com/Azuremuzzlekit/life-game.git
    cd life-game
    ```

2. Compile the program using GCC:
    ```bash
    gcc main.c -o app
    ```

3. Run the program:
    ```bash
    ./app
    ```

## How it Works

The Game of Life is a cellular automaton devised by mathematician John Conway. It consists of a grid of cells that evolve through iterations based on simple rules:

- A live cell with fewer than two live neighbors dies (underpopulation).
- A live cell with two or three live neighbors stays alive (sustainable population).
- A live cell with more than three live neighbors dies (overpopulation).
- A dead cell with exactly three live neighbors becomes alive (reproduction).

## GIF Demonstration

Here is a quick demonstration of the game in action:

![Game of Life Demo](https://github.com/user-attachments/assets/9b6985b1-d90a-4fbd-a668-ed962ee01be5)


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
