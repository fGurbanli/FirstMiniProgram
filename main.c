#include <stdio.h>
#include <stdlib.h>

#define LIMIT_FOR_MULT_TABLE 10

//Main Menu
void MainMenu();

//Programs
void MultiTable();

//Functions
int GetPosIntInput();
int GetIntInput();
float GetFloatInput();



int main(void) {
    while (1)
    {
        MainMenu();
    }
    MainMenu();
    return 0;
}

void MainMenu()
{
    //Printing Menu
    printf("\n"
"__        __   _                            _ \n"
"\\ \\      / /__| | ___ ___  _ __ ___   ___  | |\n"
" \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | |\n"
"  \\ V  V /  __/ | (_| (_) | | | | | |  __/ |_|\n"
"   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___| (_)\n"
"\n");
    printf("\nChoose a program to run!\n");
    printf("1 - Multiplication Tabel\n");
    printf("2 - Circle Area Calculator\n");
    printf("3 - Cash Register\n");
    printf("4 - Sum of Numbers\n");
    printf("5 - Electricity Price Calculator\n");
    printf("6 - Mario Tower\n");
    printf("7 - Sequence Generator\n");
    printf("8 - Finding Extreme Values\n");
    printf("\n0 - Exit\n");

    int option;
    scanf("%d", &option);

    switch (option) {
        case 0:
            printf("Shutting down the program...");
            exit(0);
        case 1:
            printf("Multiplication Table starting..\n\n");
            MultiTable();
            break;
        default:
            printf("Unknown option!\n");
    }
}

void MultiTable()
{
    printf("\033[H\033[J");
    int multiplier;
    printf("Please enter a number: ");
    multiplier = GetIntInput();

    for (int i = 0; i <= LIMIT_FOR_MULT_TABLE; i++)
    {
        int result = multiplier * i;
        printf("%d * %d = %d\n", multiplier, i, result);
    }
    printf("Do you want to continue?\n");
    printf("1 - Continue\n");
    printf("0 - Back to main menu\n");

    int option;
    scanf("%d", &option);

    switch (option) {
        case 0:
            printf("\nGoing back to main menu..");
            return;
        case 1:
            printf("\nMultiplication Table starting..\n\n");
            MultiTable();
            break;
        default:
            printf("Unknown option!\n");
    }
}

int GetPosIntInput()
{
    int input;
    while (1)
    {
        if (scanf("%d", &input) == 1 && input > 0)
        {
            break;
        }
        printf("Enter a valid value!\n");
        while (getchar() != '\n');
    }
    return input;
}

int GetIntInput()
{
    int input;
    while (1)
    {
        if (scanf("%d", &input) == 1)
        {
            break;
        }
        printf("Enter a valid value!\n");
        while (getchar() != '\n');
    }
    return input;
}

float GetFloatInput()
{
    float input;
    while (1)
    {
        if (scanf("%f", &input) == 1)
        {
            break;
        }
        printf("Enter a valid value!\n");
        while (getchar() != '\n');
    }
    return input;
}
