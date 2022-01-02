# Tic-tac-toe #


I have simulated a simple Tic-Tac-Toe game which will involve accessing shared resources and working with threads. Tic-Tac-Toe is a turn-based game that can be played between two players on a board (N × N matrix). In each turn, a player marks a cell with an X or O and gives the turn to the other player. Having N consecutive diagonal, horizontal or vertical marks of the same type is accepted as a winning state. The first player reaching a winning state wins the game. If there are no cells left to mark on the board and the board is not winning, the result will be a tie. One can assume that square-shaped boards will be used for the game. In order to simulate this game, Linux PThreads will be used as players. 


# Sample Outputs #

   # Sample Run 1 #. 

    Board Size: 3x3
    Player x played on: (0,1)
    Player o played on: (0,2)
    Player x played on: (2,2)
    Player o played on: (1,1)
    Player x played on: (1,2)
    Player o played on: (1,0)
    Player x played on: (2,1)
    Player o played on: (0,0)
    Player x played on: (2,0)
    Game end
    Winner is X
    [o][x][o]
    [o][o][x]
    [x][x][x]

   # Sample Run 2 #

    Board Size: 4x4
    Player x played on: (0,0)
    Player o played on: (1,3)
    Player x played on: (2,1)
    Player o played on: (3,0)
    Player x played on: (0,2)
    Player o played on: (0,3)
    Player x played on: (3,3)
    Player o played on: (1,2)
    Player x played on: (2,0)
    Player o played on: (0,1)
    Player x played on: (3,2)
    Player o played on: (2,3)
    Player x played on: (1,1)
    Player o played on: (1,0)
    Player x played on: (3,1)
    Player o played on: (2,2)
    Game end
    It is a tie
    [x][o][x][o]
    [o][x][o][o]
    [x][x][o][o]
    [o][x][x][x]

   # Sample Run 3 #

    Board Size: 3x3
    Player x played on: (0,0)
    Player o played on: (0,2)
    Player x played on: (1,1)
    Player o played on: (1,2)
    Player x played on: (2,0)
    Player o played on: (2,2)
    Game end
    Winner is O
    [x][ ][o]
    [ ][x][o]
    [x][ ][o]





