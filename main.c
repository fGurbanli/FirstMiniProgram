#include <stdio.h>
#include <stdlib.h>

#define LIMIT_FOR_MULT_TABLE 10

//Main Menu
void MainMenu();

//Programs
void MultiTable();
void CircleAreaCal();
void CashRegister();
void SumOfNumbers();

//Functions
int GetPosIntInput();
int GetIntInput();
float GetFloatInput();
int AskUserOut();





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
            printf("Multiplication Table is starting..\n\n");
            MultiTable();
            break;
        case 2:
            printf("Circle Area Calculator is starting..\n\n");
            CircleAreaCal();
            break;
        case 3:
            printf("Cash Register is starting..\n\n");
            CashRegister();
            break;
        case 4:
            printf("Sum of Numbers is starting..\n\n");
            SumOfNumbers();
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
    if (AskUserOut() == 1) {
        MultiTable();
    }
}

void CircleAreaCal()
{
    double Pi = 3.14159265358979323846;
    printf("Enter the radius of the circle: ");
    double radius = GetPosIntInput();
    double area = Pi * radius * radius;
    double perimeter = 2 * Pi * radius;
    printf("The area of the circle is %.2f\n", area);
    printf("The perimeter of the circle is %.2f\n", perimeter);

    if (AskUserOut() == 1){
        CircleAreaCal();
    }
}

void CashRegister()
{
    float accountBalance = 100.00f;         // Current account balance
    const int pinCodeDebitCard = 1234;      // PIN of the card


    /* Read the purchase total. */

    printf("Enter purchase total: ");
    float purchaseTotal = GetFloatInput();

    /* Read whether the client presented their loyalty card */

    printf("Did client present loyalty card?\n1 - yes\n0 - no\n");
    int isLoyaltyCardPresented = GetIntInput();

    /* Read whether the client will get an extra discount */

    printf("Apply extra discount?\n1 - yes\n0 - no\n");
    int applyExtraDiscount = GetIntInput();


    if (applyExtraDiscount)
    {
        // Reduce the price by 20%
        purchaseTotal *= 0.8f;
        printf("20%% discount applied\n");
    }
    else if (isLoyaltyCardPresented)
    {
        // Reduce price by 10%
        purchaseTotal *= 0.9f;
        printf("10%% discount applied\n");
    }

    printf("Invoice total: %.2f\n", purchaseTotal);

    // Ask the user for their PIN code

    printf("Please enter your PIN code:");
    int userEnteredPinCode = GetIntInput();


    if (userEnteredPinCode == pinCodeDebitCard)
    {
        if (accountBalance >= purchaseTotal)
        {
            accountBalance -= purchaseTotal;
            printf("Payment succeeded!\nYour current balance is %.2f\n", accountBalance);
        }
        else
        {
            printf("Insufficient balance!\n");
            return;
        }
    }
    else
    {
        printf("Your pin code is incorrect!");
        return;
    }
    if (AskUserOut() == 1) {
        CashRegister();
    }
}

void SumOfNumbers()
{
    printf("Enter how many numbers do you want to insert.\n");
    int totalSum = GetPosIntInput();
    printf("This program will take %d numbers from user and calculate sum of these numbers\n", totalSum);

    for (int i = 1; i <= totalSum; i++)
    {
        //Creating a temporary variable which helps to calculate current totalSum
        int temp;
        printf("Enter a number %d / 5\n", i);
        scanf("%d", &temp);
        totalSum += temp;
        if (i < totalSum)
        {
            printf("Subtotal is %d\n", totalSum);
        }
        //The last output
        else
        {
            printf("The final sum is %d", totalSum);
        }
    }
    if (AskUserOut() == 1){
        SumOfNumbers();
    }
}



int AskUserOut()
{
    printf("\nDo you want to continue?\n");
    printf("1 - Continue\n");
    printf("0 - Back to main menu\n");

    int option = GetPosIntInput();

    switch (option) {
        case 0:
            printf("\nGoing back to main menu..");
            MainMenu();
        case 1:
            printf("\nCircle Area Calculator starting..\n\n");
            return 1;
        default:
            printf("Unknown option!\n");
            MainMenu();
    }
    return 0;
}

int GetPosIntInput()
{
    int input;
    while (1)
    {
        if (scanf("%d", &input) == 1 && input >= 0)
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
