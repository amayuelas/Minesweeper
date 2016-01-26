# Minesweeper
This is a porject form my first year at univesity. It is a minesweeper developed in c++ on Visual Studio. It is a console application.
The games is the minesweeper we all know and saves the score into a text file.

There are 5 different classes:
- Minesweeper (Cercamines): It manages the main game. It asks tha name and level to the user and then gives the control to the game class. When the game is over, it saves the score, asks how the user wants to see the results and you want to play again.
- Game (Partida): Manages the game, asking the user which box want to uncover. It says when to paint the board and sets when the game is over.
- Board (Tauler): Initializes the board, uncovers a box and determine wether there was a mine or not. And it paints the board when asked.
- Box (Casella): It manages a box. It has attributes to know if it has a mine and wether it is uncovered or not. It paints itself according to its attributes when required by the board.
- Score (Puntacions): It manages the text file with the scores. It saves a new games, loads the old games when it is open and orders the scores by name, level or score.
