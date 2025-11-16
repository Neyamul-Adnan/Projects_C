/*
Authors : MD. Neyamul Adnan
Project : Ceremony Seat Management System
Date    : 15/11/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_header(char title[]);
void add_seat();
void remove_seat();
void update_seat();
void display_seats();
void main_menu();

typedef struct seat_details
{
    int row;
    int column;
    char status[20]; // Booked / Empty
} sd;

sd seats[200];   // max seats
int total_seats = 0;

int main()
{
    main_menu();
    return 0;
}

void print_header(char title[])
{
    system("cls");
    printf("\n\t<><><><><><><><><><><><><><><><><><><><><>\n");
    printf("\t       Ceremony Seat Management System       \n");
    printf("\t<><><><><><><><><><><><><><><><><><><><><>\n");
    printf("\n\t-------------- %s ----------------\n\n", title);
}

void main_menu()
{
    char temp[50];
    int choice;

    do
    {
        print_header("MAIN MENU");
        printf("1. Add a Seat\n");
        printf("2. Remove a Seat\n");
        printf("3. Update a Seat\n");
        printf("4. Display Seating Arrangement\n");
        printf("5. Save Seating Arrangement (Disabled)\n");
        printf("6. Load Seating Arrangement (Disabled)\n");
        printf("7. Exit\n");

        printf("\nEnter choice: ");
        fgets(temp, sizeof(temp), stdin);
        sscanf(temp, "%d", &choice);

        system("cls");

        switch (choice)
        {
        case 1:
            print_header("ADD SEAT");
            add_seat();
            break;

        case 2:
            print_header("REMOVE SEAT");
            remove_seat();
            break;

        case 3:
            print_header("UPDATE SEAT");
            update_seat();
            break;

        case 4:
            print_header("DISPLAY SEATING");
            display_seats();
            break;

        case 5:
        case 6:
            print_header("INFORMATION");
            printf("\nFile features are disabled as per instructions.\n\n");
            printf("Press Enter to return...");
            fgets(temp, sizeof(temp), stdin);
            break;

        default:
            break;
        }

    } while (choice != 7);
}

void add_seat()
{
    char temp[50];
    int again;

    do
    {
        printf("Enter Row Number: ");
        fgets(temp, 50, stdin);
        sscanf(temp, "%d", &seats[total_seats].row);

        printf("Enter Seat Number: ");
        fgets(temp, 50, stdin);
        sscanf(temp, "%d", &seats[total_seats].column);

        strcpy(seats[total_seats].status, "Occupied");
        total_seats++;

        printf("\nSeat Added Successfully!\n");
        printf("Enter 1 to add another seat or 0 to return: ");
        fgets(temp, 50, stdin);
        sscanf(temp, "%d", &again);

        if (again == 1)
            system("cls");

    } while (again == 1);
}

void remove_seat()
{
    char temp[50];
    int row, col, x, found = 0;

    printf("Enter Row Number: ");
    fgets(temp, 50, stdin);
    sscanf(temp, "%d", &row);

    printf("Enter Seat Number: ");
    fgets(temp, 50, stdin);
    sscanf(temp, "%d", &col);

    for (int i = 0; i < total_seats; i++)
    {
        if (seats[i].row == row && seats[i].column == col)
        {
            printf("\nSeat Found!\n");
            printf("Row: %d | Seat: %d | Status: %s\n",
                   seats[i].row, seats[i].column, seats[i].status);

            printf("\nConfirm Remove?\n1. YES\n2. NO\nChoice: ");
            fgets(temp, 50, stdin);
            sscanf(temp, "%d", &x);

            if (x == 1)
            {
                for (int j = i; j < total_seats - 1; j++)
                    seats[j] = seats[j + 1];

                total_seats--;
                printf("\nSeat Removed Successfully!\n");
            }
            else
            {
                printf("\nOperation Cancelled.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nSeat Not Found!\n");

    printf("\nPress Enter to return...");
    fgets(temp, 50, stdin);
}

void update_seat()
{
    char temp[50];
    int row, col, found = 0;
    int new_row, new_col;

    printf("Enter Current Row: ");
    fgets(temp, 50, stdin);
    sscanf(temp, "%d", &row);

    printf("Enter Current Seat: ");
    fgets(temp, 50, stdin);
    sscanf(temp, "%d", &col);

    for (int i = 0; i < total_seats; i++)
    {
        if (seats[i].row == row && seats[i].column == col)
        {
            printf("\nSeat Found!\n");

            printf("Enter NEW Row: ");
            fgets(temp, 50, stdin);
            sscanf(temp, "%d", &new_row);

            printf("Enter NEW Seat: ");
            fgets(temp, 50, stdin);
            sscanf(temp, "%d", &new_col);

            seats[i].row = new_row;
            seats[i].column = new_col;

            printf("\nSeat Updated Successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nSeat Not Found!\n");

    printf("\nPress Enter to return...");
    fgets(temp, 50, stdin);
}

void display_seats()
{
    char temp[10];

    if (total_seats == 0)
    {
        printf("No seats added yet!\n");
        printf("\nPress Enter to return...");
        fgets(temp, sizeof(temp), stdin);
        return;
    }

    printf("----- CURRENT SEATING ARRANGEMENT -----\n");

    for (int i = 0; i < total_seats; i++)
    {
        printf("Row: %d | Seat: %d | Status: %s\n",
               seats[i].row, seats[i].column, seats[i].status);
        printf("---------------------------------------\n");
    }

    printf("\nPress Enter to return...");
    fgets(temp, sizeof(temp), stdin);
}
