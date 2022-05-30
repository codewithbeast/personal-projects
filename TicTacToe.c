#include <stdio.h>
#include<stdlib.h>


char board[3][3] = {{'.', '.', '.'}
                    ,{'.', '.', '.'}, 
                    {'.', '.', '.'}};
char b[3];
int PrintBoard(void);
int fetch(int row, char b[]);
int fetch2(int row, char b[]);
int draw(void);
int CheckWinner();

int main(void)
{
    PrintBoard();

    int row, colum;
    char turn;

    turn = 'O';
    
    while (1)
    {      
        
        
        CheckWinner();
        


        if (turn == 'O')
        {
            printf("%c%s\n", turn, "'s turn");
            printf("\n");
            printf("Row: ");
            scanf("%d", &row);

            printf("Colum: ");
            scanf("%d", &colum);
            printf("\n");

            if (board[row][colum] == '.')
            {
                board[row][colum] = 'O';
                PrintBoard();
                turn = 'X';
            }
            else
            {
                printf("That cell is occupied\n");
                PrintBoard();
                turn = 'O';
            }
        }

        CheckWinner();

        if (turn == 'X')
        {
            printf("%c%s\n", turn, "'s turn");

            printf("Row: ");
            scanf("%d", &row);

            printf("Colum: ");
            scanf("%d", &colum);
            printf("\n");
            if (board[row][colum] == '.')
            {
                board[row][colum] = 'X';
                PrintBoard();
                turn = 'O';
            }
            else
            {
                printf("That cell Is occupied\n");
                PrintBoard();
                turn = 'X';
            }
        }
        
        
        CheckWinner();
        
    }
    return 0;
}

int PrintBoard(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c\t", board[i][j]);
        }
        printf("\n\n");
    }

    
    return 0;
}

int fetch(int row, char b[])
{
    for (int i = 0; i < 3; i++)
    {
        b[i] = board[row][i];
    }

    if (b[0] != '.' || b[1] != '.' || b[2] != '.')
    {
        if (b[0] == b[1])
        {
            if (b[1] == b[2])
            {
                printf("%c%s\n", b[0], " is the winner");
                exit(0);
                return 1;
            }
        }
    }

}
int fetch2(int row, char b[])
{
    for (int i = 0; i < 3; i++)
    {
        b[i] = board[i][row];
    }

    if (b[0] != '.' || b[1] != '.' || b[2] != '.')
    {
        if (b[0] == b[1])
        {
            if (b[1] == b[2])
            {
                printf("%c%s\n", b[0], " is the winner");
                exit(0);
                
                return 1;
            }

        }
    }

}

int draw(void)
{   
    int counter = 0;
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (board[i][j] !='.')
            {
                counter++;
            }
        }
    }

    return counter;
}

int CheckWinner()
{      
    int check;
    for (int i = 0; i < 3; i++)
    {   
        check = fetch2(i, b);
        
    }

    for (int i = 0; i < 3; i++)
    {
        check = fetch(i, b);
    }

    if (check !=1 && draw() == 9)
    {
        printf("Draw\n");
        exit(0);
    }


    

   
}
