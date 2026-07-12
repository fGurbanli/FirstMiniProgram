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
void ElectricityPriceCal();
void MarioTower();
void SequenceGenerator();

//Functions
int GetPosIntInput();
int GetIntInput();
float GetPositiveFloat();
float GetFloatInput();
int AskUserOut();

//Electricity Price Calculator
/* Power ratings for bulbs in watts */
#define POWER_LED 9
#define POWER_INCANDESCENT 60

/* Number of days for calculation */
#define DAYS_PER_MONTH 30

/* Value added tax in percentages */
#define VAT_PERCENTAGE 24.0f

/* FILL IN! Something you buy regularly */
#define ITEM_NAME "Bulb"
#define ITEM_COST 2.01f

float ConvertMwhToKwh(float pricePerMwh);
float CalcElectricityCost(int consumptionInWatts, float pricePerKwh);
float CalcVat(float price, float vatPcnt);
int CalcMonthlyConsumption(int nConsumers, int nHours, int power, int days);
int CalcItemsForMoney(float money, float costPerItem);

//Mario Tower
void printBlocks(int height);

//Sequence Generator
#define WIDTH 65
/* Functions for visuals */
void PrintSeparator(int width);
void PrintMenu(int width);
void PrintAsciiWelcomeMsg(void);

/* Functions to handle arithmetic sequence */
void ArithmeticSequence(void);
void ArithmeticSequenceGenerator(float start, float diff, int cnt);

/* Functions to handle geometric sequence */
void GeometricSequence(void);
void GeometricSequenceGenerator(float start, float ratio, int cnt);


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

    int option = GetPosIntInput();

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
        case 5:
            printf("Electricty Price Calculator is starting..\n\n");
            ElectricityPriceCal();
            break;
        case 6:
            printf("Mario Tower is starting..\n\n");
            MarioTower();
            break;
        case 7:
            printf("Sequence Generator is starting..\n\n");
            SequenceGenerator();
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

void ElectricityPriceCal()
{
    printf("Enter the market price for electricity in MWh: ");
    float pricePerMwh = GetPositiveFloat();

    /* Convert from MWh to kWh for easier underastanding */
    float pricePerKwh = ConvertMwhToKwh(pricePerMwh);

    /* Calculate VAT and price of kWh with VAT */
    float vatPerKwh = CalcVat(pricePerKwh, VAT_PERCENTAGE);
    float priceWithVat = pricePerKwh + vatPerKwh;

    printf("\nMarket cost of electricity is %.2f EUR / MWh.\n", pricePerMwh);
    printf("This is %.4f EUR per kWh before taxes.\n", pricePerKwh);
    printf("The government takes %.4f EUR in taxes.\n", vatPerKwh);
    printf("With taxes, the cost for you is %.4f EUR / kWh\n\n", priceWithVat);


    printf("Lets do a rough savings estimate when switching "
           "from incandescent bulbs to LEDs\n\n");

    printf("Number of E27 lightbulbs in use: ");
    int numOfBulbs = GetPosIntInput();

    printf("Average hours per day the bulbs are turned on for: ");
    int hoursPerBulb = GetPosIntInput();

    /* Calculate avg monthly consumption for LED and incandescent bulbs */
    int consIncandescent = CalcMonthlyConsumption(numOfBulbs, hoursPerBulb,
                                                  POWER_INCANDESCENT,
                                                  DAYS_PER_MONTH);
    int consLED = CalcMonthlyConsumption(numOfBulbs, hoursPerBulb, POWER_LED,
                                         DAYS_PER_MONTH);

    /* Calculate the cost for the consumed energy for both bulb types */
    float costIncandescent = CalcElectricityCost(consIncandescent, priceWithVat);
    float costLED = CalcElectricityCost(consLED, priceWithVat);

    printf("\nResults are calculated for a %d-day month.\n", DAYS_PER_MONTH);
    printf("\nUsing %d W incandescent bulbs consumes %d W, costing %.2f EUR\n",
           POWER_INCANDESCENT, consIncandescent, costIncandescent);
    printf("Using %d W LED bulbs consumes %d W, costing %.2f EUR\n",
           POWER_LED, consLED, costLED);

    float potentialSavings = costIncandescent - costLED;
    int purchasableItems = CalcItemsForMoney(potentialSavings, ITEM_COST);

    printf("That's a saving of %.2f EUR.\n", potentialSavings);
    printf("At the price of %.2f, you could buy %d %s with that money!",
            ITEM_COST, purchasableItems, ITEM_NAME);
    if (AskUserOut() == 1)
    {
        ElectricityPriceCal();
    }
}

void MarioTower()
{
    printf("\nPlease enter tower height: ");
    int height = GetPosIntInput();
    const char head[] = "\\O/";
    const char body[] = " | ";
    const char legs[] = "/ \\";
    // Printing stickman
    printf("%s\n%s\n%s\t\t\t\trow\t\ttotal\n", head, body, legs);
    printBlocks(height);
    if (AskUserOut() == 1){
        MarioTower();
    }
}

void SequenceGenerator()
{
    PrintAsciiWelcomeMsg();
    PrintSeparator(WIDTH);

    PrintMenu(WIDTH);

    PrintSeparator(WIDTH);

    printf("Enter selection\n> ");
    int option = GetPosIntInput();
    PrintSeparator(WIDTH);

    /* Process the user action */
    switch (option)
    {
        case 1:
            ArithmeticSequence();
            break;
        case 2:
            GeometricSequence();
            break;
        default:
            printf("Unknown option!\n");
    }
    printf("\n");
    PrintSeparator(WIDTH);


}


//Functions
int AskUserOut()
{
    printf("\n\nDo you want to continue?\n");
    printf("1 - Continue\n");
    printf("0 - Back to main menu\n");

    int option = GetPosIntInput();

    switch (option) {
        case 0:
            printf("\nGoing back to main menu..");
            MainMenu();
        case 1:
            printf("\nProgram is starting again..\n\n");
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

float GetPositiveFloat()
{
    float input;
    while (1)
    {
        if (scanf("%f", &input) != 1)
        {
            printf("Please enter a valid number: \n");
            while (getchar() != '\n');
            continue;
        }

        if (input > 0)
        {
            return input;
        }
        printf("Please enter a positive number: \n");
    }
}

//Electricty Price Calculator functions
float ConvertMwhToKwh(float price)
{
    return price / 1000.0f;
}
float CalcElectricityCost(int consumptionInWatts, float pricePerKwh)
{

    return consumptionInWatts * pricePerKwh / 1000.0f;
}
float CalcVat(float price, float vatPcnt)
{

    return price * vatPcnt / 100;
}
int CalcMonthlyConsumption(int nConsumers, int nHours, int power, int days)
{
    int consumption;
    consumption = nConsumers * nHours * power * days;
    return consumption;
}
int CalcItemsForMoney(float money, float costPerItem)
{

    return money / costPerItem;
}

//Mario Tower function
void printBlocks(int height)
{
    int total = 0;
    for (int i = 3; i <= height; i++)
    {
        //Printing blocks
        for (int blockCount = 1; blockCount <= i; blockCount++)
        {
            printf("#");
        }
        //Printing spaces
        for (int spaceCount = 0; spaceCount <= height - i; spaceCount++)
        {
            printf(" ");
        }
        //Printing row and total at the end
        total += i;
        printf("%d\t\t%d\n", i, total);
    }
}

//Sequence Generator
void ArithmeticSequence(void)
{

    /* Header for this generation */
    printf("Arithmetic sequence generator\n");
    PrintSeparator(WIDTH);

    /* Get user input for the generator parameters */
    printf("Enter number of results: ");
    int resultCount = GetPosIntInput();
    printf("Enter starting value: ");
    float startingValue = GetFloatInput();
    printf("Enter common difference: ");
    float cmnDiff = GetFloatInput();
    /* Call the generator with user specified parameters */
    ArithmeticSequenceGenerator(startingValue, cmnDiff, resultCount);
}

void GeometricSequence(void)
{
    /* Header for this generation */
    printf("Geometric sequence generator\n");
    PrintSeparator(WIDTH);

    /* Get user input for the generator parameters */
    printf("Enter number of results: ");
    int resultCount = GetPosIntInput();
    printf("Enter starting value: ");
    float startingValue = GetFloatInput();
    printf("Enter common difference: ");
    float cmnRatio = GetFloatInput();

    /* Call the generator with user specified parameters */
    GeometricSequenceGenerator(startingValue, cmnRatio, resultCount);

}

void ArithmeticSequenceGenerator(float start, float diff, int cnt)
{
    printf("Results\n");
    for(int i = 1; i <= cnt; i++)
    {
        printf(" %.2f", start);
        start += diff;
    }
    if (AskUserOut() == 1){
        SequenceGenerator();
    }
}

void GeometricSequenceGenerator(float start, float ratio, int cnt)
{
    printf("Results\n");

    for (int i = 1; i <= cnt; i++)
    {
        printf(" %.2f", start);
        start *= ratio;
    }
    if (AskUserOut() == 1){
        SequenceGenerator();
    }

}

void PrintAsciiWelcomeMsg(void)
{
    /* TODO: add ASCII art */
    printf("   _____                           _             _             \n"
       "  / ____|                         | |           | |            \n"
       " | |  __  ___ _ __   ___ _ __ __ _| |_ ___  _ __| |_ ___ _ __  \n"
       " | | |_ |/ _ \\ '_ \\ / _ \\ '__/ _` | __/ _ \\| '__| __/ _ \\ '__| \n"
       " | |__| |  __/ | | |  __/ | | (_| | || (_) | |  | ||  __/ |    \n"
       "  \\_____|\\___|_| |_|\\___|_|  \\__,_|\\__\\___/|_|   \\__\\___|_|    \n"
       "                                                               \n");
}

void PrintMenu(int width)
{
    const int paddingLeft = 3;
    const int paddingRight = 2;

    /* Calculate area for a menu line text*/
    int textArea = width - (paddingLeft + paddingRight);

    /* Format: align left, give room up to 'textArea' characters, cut off
     *         anything that doesn't fit.
     */
    printf("#  %-*.*s #\n", textArea, textArea, "1 - Arithmetic sequence generator");
    printf("#  %-*.*s #\n", textArea, textArea, "2 - Geometric sequence generator");
    printf("#  %-*.*s #\n", textArea, textArea, "0 - exit");
}

void PrintSeparator(int width)
{
    for (int i = 1; i <= width; i++)
    {
        printf("#");
    }
    printf("\n");
}
