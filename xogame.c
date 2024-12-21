/*
    Author: Sopheap Thea
    Purpose : Create X O Game that have two Players 
    Date : 15-01-21
*/
// Header File
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
// Declear Global variable

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';
// Function Prototype
void resetBoard();
void printBoard();
void welcomeMessage();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

// Main Function

int main(){
    // declear variable
    char winner = ' ';
    char respones;

        do
        {
            // Welcome Message
            welcomeMessage();
            // Reassign Variable
            winner = ' ';
            respones = ' ';
            // Invoke Function
            resetBoard();
            // Use While loop to ask player to play

            while (winner == ' ' && checkFreeSpaces() != 0)
            {
            // Print board to the screen
                printBoard();
            // Player tend to move first
                playerMove();
                winner = checkWinner();
                if(winner != ' ' || checkFreeSpaces == 0)
                {
                    break;
                    
                }
            // Computer Move Function and check condition
                computerMove();
                winner = checkWinner();
                if(winner != ' ' || checkFreeSpaces == 0)
                {
                    break;
                }
            }
            printBoard();
            printWinner(winner);


            printf("\nWould you like to play again (Y/N): ");
            scanf("%c");
            scanf("%c", &respones);
            respones = toupper(respones);
        } while (respones == 'Y');
        

    printf("Thank you for playing!");
    return 0;
}

// Function Declearation

void resetBoard()
{
    //This Function is to reset all element 2d array caratter
    // Use nestead loop to reset all element in rows and columns
    for(int i = 0; i <3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard()
{
    printf(" %c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[2][0], board[2][1], board[2][2]);
    printf("\n");

} 
int checkFreeSpaces()
{
    int freeSpaces = 9;
    for(int i = 0; i <3; i++){
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
void playerMove()
{
    int x;
    int y;
    do
    {
        // Ask Player to put codordinator or row and column to player
        printf("\nEnter Rom Num(1 to 3): ");
        scanf("%d",&x);
        x--;
        printf("\nEnter Column Num(1 to 3): ");
        scanf("%d",&y);
        y--;
        if(board[x][y] != ' '){
            printf("\nInvalid Move!");
        }
        else{
            board[x][y] = PLAYER;
            break;
        }
    } while(board[x][y] != ' ');
}

char checkWinner()
{
    // Check Row Condition
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // Check Columns Condition
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // Check Diagonals 1 Row1 Columns1
    if(board[0][0] == board[1][1] && board[0][0]==board[2][2])
    {
        return board[0][0];
    }
    //Check Diagonals 2 Row 3 Columns 3
    if(board[2][0] == board[1][1] && board[2][0] == board[0][2])
    {
        return board[2][0];
    }
    return ' ';
}
void computerMove()
{
    // Generate a seed on current time
    srand(time(0));
    int x;
    int y;
    // Generate random number from 0 to 2

    if(checkFreeSpaces() > 0)
    {

        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while(board[x][y] !=' ');
        board[x][y] = COMPUTER;
    }
    else 
    {
        printWinner(' ');
    }
}

void printWinner(char winner)
{
    if(winner == PLAYER){
        printf("\nYOU ARE WIN!");
    }
    else if (winner == COMPUTER)
    {
        printf("\nYOU ARE LOSE!");
    }
    else{
        printf("\nIT'S A TIE!");
    }
}

void welcomeMessage()
{
    printf("\n");
    printf("Welcome To Tec Toc Teo Game :)\n");
    printf("Please Enjoy playing");
    printf("\n");
    printf("-----------------------");
    printf("\n");
}

    
