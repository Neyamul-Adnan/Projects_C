/*
Authors : Your Name Here
Project : Tic-Tac-Toe Multiplayer
Date    : 05/11/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_header(char title[]);
void main_menu();
void start_game();
void display_board();
void mark_position();
void check_winner();

char board[3][3];
int game_over = 0;
char current_player = 'X';

void initialize_board()
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
}

int main()
{
    main_menu();
    return 0;
}

void print_header(char title[])
{
    system("cls");
    printf("\n\t<><><><><><><><><><><><><><><><><><><><>\n");
    printf("\t              TIC TAC TOE               \n");
    printf("\t<><><><><><><><><><><><><><><><><><><><>\n");
    printf("\n\t-------------- %s ----------------\n\n", title);
}

void main_menu()
{
    int n;
    char temp[50];

    do
    {
        print_header("MAIN MENU");
        printf("1. Start Game\n");
        printf("2. Exit\n");
        printf("\nEnter choice: ");
        fgets(temp, 50, stdin);
        sscanf(temp, "%d", &n);

        system("cls");

        switch (n)
        {
        case 1:
            print_header("TIC TAC TOE");
            start_game();
            break;

        default:
            break;
        }

    } while (n != 2);
}

void start_game()
{
    char temp[50];

    initialize_board();
    game_over = 0;
    current_player = 'X';

    while (!game_over)
    {
        print_header("TIC TAC TOE");
        display_board();
        mark_position();
        check_winner();
    }

    printf("\nPress Enter to return to MAIN MENU...");
    fgets(temp, 50, stdin);
}

void display_board()
{
    printf("\n");
    printf("Current Player: %c\n\n", current_player);

    // Row 1
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("___|___|___\n");

    // Row 2
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("___|___|___\n");

    // Row 3
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("   |   |   \n\n");
}


void mark_position()
{
    int r, c;
    char temp[50];

    while (1)
    {
        printf("Enter Row (1-3): ");
        fgets(temp, 50, stdin);
        sscanf(temp, "%d", &r);

        printf("Enter Column (1-3): ");
        fgets(temp, 50, stdin);
        sscanf(temp, "%d", &c);

        if (r < 1 || r > 3 || c < 1 || c > 3)
        {
            printf("Invalid position! Try again.\n");
            continue;
        }

        if (board[r - 1][c - 1] != ' ')
        {
            printf("Position already taken! Try again.\n");
            continue;
        }

        board[r - 1][c - 1] = current_player;
        break;
    }
}

void check_winner()
{
    int i;

    // Row win
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == current_player &&
            board[i][1] == current_player &&
            board[i][2] == current_player)
        {
            display_board();
            printf("\nPlayer %c Wins!\n", current_player);
            game_over = 1;
            return;
        }
    }

    // Column win
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == current_player &&
            board[1][i] == current_player &&
            board[2][i] == current_player)
        {
            display_board();
            printf("\nPlayer %c Wins!\n", current_player);
            game_over = 1;
            return;
        }
    }

    // Diagonal win
    if (board[0][0] == current_player &&
        board[1][1] == current_player &&
        board[2][2] == current_player)
    {
        display_board();
        printf("\nPlayer %c Wins!\n", current_player);
        game_over = 1;
        return;
    }

    if (board[0][2] == current_player &&
        board[1][1] == current_player &&
        board[2][0] == current_player)
    {
        display_board();
        printf("\nPlayer %c Wins!\n", current_player);
        game_over = 1;
        return;
    }

    // Draw check
    int empty = 0;
    for (i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                empty = 1;

    if (!empty)
    {
        display_board();
        printf("\nGame Draw!\n");
        game_over = 1;
        return;
    }

    // Next turn
    current_player = (current_player == 'X') ? 'O' : 'X';
}
