#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void Print_Game_Board(char board[5][11]);
int Valid_Integer_Input(int min_value, int max_value, char statement[]);

int main()
{
    int choice, Player, Box=9;
    char statement[50];
    char sign;
    int choices[10][10];        // Reference 2D Array
    int k=1;        // Integer Track

    char Game_Board_Data[5][11];

    for(int i = 0; i<5; i++)
    {
        for(int j = 0; j<11; j++)
        {
            if((i==1 || i==3) && ((j>=0 && j<=2) || (j>=4 && j<=6) || j>=8 && j<=10))
            {
                Game_Board_Data[i][j] = '-';
            }
            else if((j==3 || j==7) && (i==0 || i==2 || i==4))
            {
                Game_Board_Data[i][j] = '|';
            }
            else if((i==1 || i==3) && (j==3 || j==7))
            {
                Game_Board_Data[i][j] = '+';
            }
            else
            {
                Game_Board_Data[i][j] = ' ';
            }
        }
    }

    for(int a=0; a<5; a+=2)
    {
        for(int b=1; b<10; b+=4)
        {
            choices[a][b] = k;
            k++;
        }
    }

    int position_X, position_Y;
    
    for(int i=0; ; i++)
    {
        if(i%2 == 0)
        {
            Player = 1;
            sign = 'X';
        }
        else if(i%2 == 1)
        {
            Player = 2;
            sign = 'O';
        }

        Print_Game_Board(Game_Board_Data);

        Again :

        if(Box!=0)
        {
            sprintf(statement, "Enter Choice of Player %d (%c)", Player, sign);
            choice = Valid_Integer_Input(1, 9, statement);

            if(choice == 0)
            {
                break;
            }

            for(int i=0; i<5; i+=2)
            {
                for(int j=1; j<11; j+=4)
                {
                    if(choices[i][j] == choice)
                    {
                        if(Game_Board_Data[i][j] == ' ')
                        {
                            Game_Board_Data[i][j] = sign;
                        }
                        else
                        {
                            printf("\nPlace Already Occupied..!!\n\n");
                            goto Again;
                        }
                    }
                }
            }

            Box--;
            system("cls");
        }

        if
        (
            (Game_Board_Data[0][1] == Game_Board_Data[0][5] && Game_Board_Data[0][5] == Game_Board_Data[0][9] && (Game_Board_Data[0][9] == 'X' || Game_Board_Data[0][9] == 'O')) ||
            (Game_Board_Data[2][1] == Game_Board_Data[2][5] && Game_Board_Data[2][5] == Game_Board_Data[2][9] && (Game_Board_Data[2][9] == 'X' || Game_Board_Data[2][9] == 'O')) ||
            (Game_Board_Data[4][1] == Game_Board_Data[4][5] && Game_Board_Data[4][5] == Game_Board_Data[4][9] && (Game_Board_Data[4][9] == 'X' || Game_Board_Data[4][9] == 'O')) ||
            (Game_Board_Data[0][1] == Game_Board_Data[2][1] && Game_Board_Data[2][1] == Game_Board_Data[4][1] && (Game_Board_Data[4][1] == 'X' || Game_Board_Data[4][1] == 'O')) ||
            (Game_Board_Data[0][5] == Game_Board_Data[2][5] && Game_Board_Data[2][5] == Game_Board_Data[4][5] && (Game_Board_Data[4][5] == 'X' || Game_Board_Data[4][5] == 'O')) ||
            (Game_Board_Data[0][9] == Game_Board_Data[2][9] && Game_Board_Data[2][9] == Game_Board_Data[4][9] && (Game_Board_Data[4][9] == 'X' || Game_Board_Data[4][9] == 'O')) ||
            (Game_Board_Data[0][1] == Game_Board_Data[2][5] && Game_Board_Data[2][5] == Game_Board_Data[4][9] && (Game_Board_Data[4][9] == 'X' || Game_Board_Data[4][9] == 'O')) ||
            (Game_Board_Data[0][9] == Game_Board_Data[2][5] && Game_Board_Data[2][5] == Game_Board_Data[4][1] && (Game_Board_Data[4][1] == 'X' || Game_Board_Data[4][1] == 'O'))
        )
        {
            Box=0;
            Print_Game_Board(Game_Board_Data);
            printf("\nPlayer %d is Winner..!!\n\nCongratulations...!!\n", Player);
            break;
        }
        else if(Box==0)
        {
            Box=0;
            Print_Game_Board(Game_Board_Data);
            printf("\nMatch is Draw..!!\n\nCollabration Of Equally Worthy Opponents..!!\n");
            break;
        }
    }

    getch();
    return 0;
}

void Print_Game_Board(char board[5][11])
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<11; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int Valid_Integer_Input(int min_value, int max_value, char statement[])
{
    int entered_value;
    printf("\n%s : ", statement);
    scanf("%d", &entered_value);
    while(!((entered_value >= min_value) && (entered_value <= max_value)))
    {
        printf("\nPlease Enter Valid Responce..!\n\n");
        printf("%s : ", statement);
        scanf("%d", &entered_value);
        if((entered_value >= min_value) && (entered_value <= max_value))
        {
            break;
        }
    }
    return entered_value;
}