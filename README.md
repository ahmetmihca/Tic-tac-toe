# Tic-tac-toe #


I have simulated a simple Tic-Tac-Toe game which will involve accessing shared resources and working with threads. Tic-Tac-Toe is a turn-based game that can be played between two players on a board (N × N matrix). In each turn, a player marks a cell with an X or O and gives the turn to the other player. Having N consecutive diagonal, horizontal or vertical marks of the same type is accepted as a winning state. The first player reaching a winning state wins the game. If there are no cells left to mark on the board and the board is not winning, the result will be a tie. One can assume that square-shaped boards will be used for the game. In order to simulate this game, Linux PThreads will be used as players. 


# Locking Mechanism (Mutex lock)

In the implementation of the C file (tictactoe.c), I used mutex lock as the locking mechanism. Mutex lock for thread synchronization is defined as a mechanism that guarantees two or more threads do not execute the program simultaneously.


# Pseudocode of Locking Algorithm

      initialize lock
      WHILE three is no winner and no tie DO

         IF X's turn THEN
            lock the thread of player x
            mark random cell on the board with x unlock the thread of player x
         ELSE
            lock the thread of player x
            mark random cell on the board with o 
            unlock the thread of player x
         ENDIF 
      ENDWHILE 

      destroy lock

# Explanation

A mutex is initialized at the beginning of the main thread function. If it’s the turn of player x, the mutex will be locked in the child thread function of player x, and at the end of this function, the mutex is unlocked and the same way with the child thread function player o. At the end of the main function, when both the threads are executed, the mutex is destroyed.

# Diagram

![Screen Shot 2022-01-02 at 21 48 07](https://user-images.githubusercontent.com/58208924/147886204-4d614a9a-f9f8-4341-87a5-43d7e7a76202.png)


   # Sample Run 1 # 

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





