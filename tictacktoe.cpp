#include <iostream>
//Array for the board
char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
int checkwin();
void board();
//Program Main Method
int main()
{
    int player = 1,i,choice; //To start with Player 1

    char mark;
    do
    {
        board();
        player=(player%2)?1:2; //To select the player

        std::cout << "Player " << player << ", enter a number:  ";
        std::cin >> choice;

        mark=(player == 1) ? 'X' : 'O'; //To assign the mark to the player

        if (choice == 1 && square[1] == '1') 

            square[1] = mark; //To assign mark to the position selected
        else if (choice == 2 && square[2] == '2')

            square[2] = mark; //To assign mark to the position selected
        else if (choice == 3 && square[3] == '3')

            square[3] = mark; //To assign mark to the position selected
        else if (choice == 4 && square[4] == '4')

            square[4] = mark; //To assign mark to the position selected
        else if (choice == 5 && square[5] == '5')

            square[5] = mark; //To assign mark to the position selected
        else if (choice == 6 && square[6] == '6')

            square[6] = mark; //To assign mark to the position selected
        else if (choice == 7 && square[7] == '7')

            square[7] = mark; //To assign mark to the position selected
        else if (choice == 8 && square[8] == '8')

            square[8] = mark; //To assign mark to the position selected
        else if (choice == 9 && square[9] == '9')

            square[9] = mark;
        else //To check if the mark is already there
        {
            std::cout<<"Invalid move "; 

            player--;
            std::cin.ignore();
            std::cin.get();
        }
        i=checkwin();

        player++;
    }
    while(i==-1);
    board();
    if(i==1) //To check and tell the result

        std::cout<<"==>\aPlayer "<<--player<<" win ";
    else
        std::cout<<"==>\aGame draw";

    std::cin.ignore();
    std::cin.get();
    return 0;
}

//Function to get the game status e.g. 1 for game over with result, -1 for game in progress and 0 for game over with no result
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3]) //checking the win for Simple Rows

        return 1;
    else if (square[4] == square[5] && square[5] == square[6]) //checking the win for Simple Rows

        return 1;
    else if (square[7] == square[8] && square[8] == square[9]) //checking the win for Simple Rows

        return 1;
    else if (square[1] == square[4] && square[4] == square[7]) //checking the win for Simple Column

        return 1;
    else if (square[2] == square[5] && square[5] == square[8]) //checking the win for Simple Column

        return 1;
    else if (square[3] == square[6] && square[6] == square[9]) //checking the win for Simple Column

        return 1;
    else if (square[1] == square[5] && square[5] == square[9]) //checking the win for diagonal

        return 1;
    else if (square[3] == square[5] && square[5] == square[7]) //checking the win for diagonal

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9') //Checking if game is already a draw

        return 0;
    else
        return -1; //Checking the game is in continue mode or not
}

//Function to render the board everytime
void board()
{
    std::cout << "\n\n\tTic Tac Toe\n\n";

    std::cout << "Player 1 (X)  -  Player 2 (O)" << std::endl << std::endl;
    std::cout << std::endl;

    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << std::endl;

    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;

    std::cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << std::endl;

    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;

    std::cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << std::endl;

    std::cout << "     |     |     " << std::endl << std::endl;
}
