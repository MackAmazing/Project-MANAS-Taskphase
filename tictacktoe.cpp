#include <iostream>
#include <stdlib.h>
//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declaration
int choice;
int row,column;
char turn = 'X'; //Declaring the starting character
bool draw = false;

void display_board() //Function to render the board 
{
    std::cout << "Player 1 (X)  -  Player 2 (O)" << std::endl << std::endl;
    std::cout << std::endl;

    std::cout << "     |     |     " << std::endl;
    std::cout << "  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<< std::endl;

    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;

    std::cout << "  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<< std::endl;

    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;

    std::cout << "  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<< std::endl;

    std::cout << "     |     |     " << std::endl << std::endl;
}
//Function to get the player input and update the board
void player_turn(){
    if(turn == 'X'){
        std::cout<<"Player 1, enter a number:  "; //To select the player
    }
    else if(turn == 'O'){
        std::cout<<"Player 2, enter a number:  "; //To select the player
    }
    std::cin>> choice;
    //Switch case to get which row and column will be update
    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            std::cout<<"Invalid Move";
    }
    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){ //To check if the mark is already there
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){ //To check if the mark is already there
        board[row][column] = 'O';
        turn = 'X';
    }else {
        std::cout<<"Invalid Move ";
        player_turn();
    }
    display_board();
}

//Function to get the game status

bool gameover(){
    //Checking the win for simple rows and simple columns
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;
    //Checking the win for both the diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;
    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;
    //Checking the if game already draw
    draw = true;
    return false;
}
//Program Main Method
int main()
{
    std::cout<<"\n\n\tTic Tac Toe\n\n";
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false){
        std::cout<<"==>\aPlayer 2 Win "; //Declaring winner
    }
    else if(turn == 'O' && draw == false){
        std::cout<<"==>\aPlayer 1 Win "; //Declaring winner
    }
    else
    std::cout<<"==>\aGame Draw"; //Declaring game draw
}
