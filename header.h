#ifndef HEADER_H
#define HEADER_H
#include <bits/stdc++.h>
using namespace std;
class Board{
    private:
        char board[3][3] = {'0','0','0','0','0','0','0','0','0'};
    public:
        friend class ComputerPlayer;
        bool isValidMove(int, int);
        void updateBoard(int, int, char);
        void showBoard();
        bool isDraw();
        bool isWin(char);
};
class Player{
    protected:
        char symbol;
    public:
        string name;
        virtual void Move(int &, int &, Board);
        char getSymbol();
        Player(char,string);
        Player(char);
};
class ComputerPlayer : public Player{
    public:
        void Move(int &, int &, Board);
        int Minmax(Board, bool);
        ComputerPlayer(char);
};
class GameManager{
    private:
        Player *players[2];
        Board *board;
    public:
        GameManager();
        ~GameManager();
        void StartGame();
};
#endif
