#include "header.h"
GameManager::GameManager(){
    string t;
    board = new Board;
    players[0] = new Player('X',"Player 1");
    cout << "Would You Like to Play Against Computer or Another Player Local? " << endl;
    cout << "Press Any Number to Play Against Another Player or Press -1 to Play Against Computer: ";
    regex filter("-?[0-9]+");
    cin >> t;
    while(!regex_match(t,filter)){
        cout << "Please Enter a Valid Number: ";
        cin >> t;
    }
    if(t!="-1"){
        players[1] = new Player('O',"Player 2");
    }
    else{
        players[1] = new ComputerPlayer('O');
    }
}
GameManager::~GameManager(){
    delete board;
}
void GameManager::StartGame(){
    bool b = true;
    while(b){
        
        for (int i = 0; i < 2; i++)
        {
            cout << "=======" << endl;
            board->showBoard();
            if(board->isDraw()){
                cout << "Draw" << endl;
                b = false;
                break;
            }
            int x, y;
            players[i]->Move(x,y,*board);
            while(!board->isValidMove(x,y)){
                cout << "Please Enter a Valid Move" << endl;
                players[i]->Move(x,y,*board);
            }
            board->updateBoard(x, y, players[i]->getSymbol());
            if(board->isWin(players[i]->getSymbol())){
                cout << players[i]->name << " Is Winner Winner Chicken Dinner!" << endl;
                b = false;
                break;
            }
        }
    }
    system("pause");
}
bool Board::isDraw(){
    bool b = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j]=='0'){
                b = false;
                break;
            }
        }
    }
    return b;
}
bool Board::isWin(char c){
    if(board[0][0]==c&&board[0][1]==c&&board[0][2]==c){
        return true;
    }
    else if(board[1][0]==c&&board[1][1]==c&&board[1][2]==c){
        return true;
    }
    else if(board[2][0]==c&&board[2][1]==c&&board[2][2]==c){
        return true;
    }
    else if(board[0][0]==c&&board[1][0]==c&&board[2][0]==c){
        return true;
    }
    else if(board[0][1]==c&&board[1][1]==c&&board[2][1]==c){
        return true;
    }
    else if(board[0][2]==c&&board[1][2]==c&&board[2][2]==c){
        return true;
    }
    else if(board[0][0]==c&&board[1][1]==c&&board[2][2]==c){
        return true;
    }
    else if(board[0][2]==c&&board[1][1]==c&&board[2][0]==c){
        return true;
    }
    return false;
}
bool Board::isValidMove(int x,int y){
    if (board[x][y] != 'X' && board[x][y] != 'O' && x < 3 && y < 3)
    {
        return true;
    }
    return false;
}
void Board::updateBoard(int x,int y,char c){
    board[x][y] = c;
}
void Board::showBoard(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
}
Player::Player(char c,string name){
    regex nameFilter("[a-z]+");
    string player_name;
    this->symbol = c;
    cout << "Please Enter Your Name: ";
    cin >> player_name;
    if(!regex_match(player_name,nameFilter)){
        this->name = name;
    }
    else{
        this->name = player_name;
    }
}
Player::Player(char c){
    this->symbol = c;
}
void Player::Move(int &x, int &y, Board board){
    string r, c;
    regex moveFilter("[0-2]{2}");
    cout << "Please Enter Your Move: ";
    cin >> r >> c;
    while(!regex_match(r+c,moveFilter)){
        cout << "Please Enter a Valid Move: ";
        cin >> r >> c;
    }
    x = r[0] - 48;
    y = c[0] - 48;
}
char Player::getSymbol(){
    return this->symbol;
}
ComputerPlayer::ComputerPlayer(char c):Player(c){
    this->name = "Computer";
}
void ComputerPlayer::Move(int &x, int &y, Board b){
    int best = -1e9;
    int value;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(b.board[i][j]=='0'){
                b.board[i][j] = 'O';
                value = Minmax(b, true);
                b.board[i][j] = '0';
                if(value>best){
                    best = value;
                    x = i;
                    y = j;
                }
            }
        }
    }
}
int ComputerPlayer::Minmax(Board b,bool xTurn){
    if(b.isWin('X')){
        return -1;
    }
    if(b.isDraw()){
        return 0;
    }
    if(b.isWin('O')){
        return 1;
    }
    if(xTurn){
        int bestScore = 1e9;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(b.board[i][j]=='0'){
                    b.board[i][j] = 'X';
                    int result = Minmax(b, false);
                    b.board[i][j] = '0';
                    if(result<bestScore){
                        bestScore = result;
                    }
                }
            }
        }
        return bestScore;
    }
    else{
        int bestScore = -1e9;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(b.board[i][j]=='0'){
                    b.board[i][j] = 'O';
                    int result = Minmax(b, true);
                    b.board[i][j] = '0';
                    if(result>bestScore){
                        bestScore = result;
                    }
                }
            }
        }
        return bestScore;   
    }
}