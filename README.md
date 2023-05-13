# Tic-Tac-Toe Game

This project is a complete implementation of the Tic-Tac-Toe game using object-oriented programming (OOP) concepts in C++. You can play the game either locally or against an AI player. The AI player is implemented using the Minimax algorithm, ensuring that it will either win or achieve a draw.

## Usage

To play the game, follow these steps:

1. Compile and run the code using a C++ compiler that supports C++11 or later.
2. You will be prompted to enter the names of the players.
3. The game board will be displayed, and players will take turns entering their moves.
4. Enter the row and column numbers to place your symbol (X or O) on the board.
5. The game will continue until a player wins or the game ends in a draw.
6. At the end of the game, you will be given the option to play again or exit.

## Classes

The project consists of the following classes:

1. **Board**: Represents the game board and provides methods for updating and displaying the board. It also checks for a win or draw condition.
2. **Player**: A base class that defines a player in the game. It stores the player's symbol (X or O) and provides a virtual method for making a move on the board.
3. **ComputerPlayer**: Inherits from the Player class and implements the AI player using the Minimax algorithm. It overrides the base class's move method to make intelligent moves.
4. **GameManager**: Manages the game flow and handles the initialization of players and the game board. It starts the game and controls the turns until a winner is determined.

## UML Diagram

The UML diagram below illustrates the relationships between the classes:
 
 ![image](https://user-images.githubusercontent.com/92688600/214952983-7e96981c-897f-404e-8053-b62f9c9f3333.png)
