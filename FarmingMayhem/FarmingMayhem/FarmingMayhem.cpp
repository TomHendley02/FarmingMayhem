// FarmingMayhem.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

string farmName;
double money;
int year;
int day;
double time;

//Empty = 0         Not Fertilised = 0        Not Owned = 0
//Wheat = 1         Fertilised = 1            Owned = 1
//Barley = 2
//OSR = 3
//Oats = 4
//Fieldbeans = 5
//Potatoes = 6
//Sugar Beets = 7
double field[30][4]{
    {10.38, 0, 0, 1}, {12.19, 0, 0, 1}, {25.16, 0, 0, 0}, {64.67, 0, 0, 0}, {18.84, 0, 0, 1},
    {22.32, 0, 0, 0}, {18.45, 0, 0, 0}, {03.97, 0, 0, 0}, {09.43, 0, 0, 0}, {12.88, 0, 0, 0},
    {21.78, 0, 0, 0}, {32.39, 0, 0, 0}, {05.12, 0, 0, 0}, {14.64, 0, 0, 0}, {27.11, 0, 0, 0},
    {10.12, 0, 0, 0}, {25.82, 0, 0, 0}, {50.02, 0, 0, 0}, {31.01, 0, 0, 0}, {06.99, 0, 0, 0},
    {18.10, 0, 0, 0}, {19.45, 0, 0, 0}, {11.64, 0, 0, 0}, {15.07, 0, 0, 0}, {33.27, 0, 0, 0},
    {02.67, 0, 0, 0}, {08.84, 0, 0, 0}, {61.87, 0, 0, 0}, {43.08, 0, 0, 0}, {17.56, 0, 0, 0}
};

double landPrice = 10600;
double fertiliserPrice = 163.97;
double seedPrice = 56.68;

double wheatYield = 2.83;
double barelyYield = 2.39;
double osrYield = 1.1;
double oatsYield = 1.98;
double fieldbeansYield = 1.34;
double potatoesYield = 10.12;
double beetsYield = 32.83;

int gamePlay();

int fieldSale() {


    return(0);
}

int fieldPurchase() 
{
    int fieldSelected; //Variable for selecting whch field to buy.

    cout << "Fields for purchase: " << endl;
    for (int i = 0; i <= 29; i++) {
        if (field[i][3] == 0) { //Loops through and checks for which fields are currently not owned by the player.
            cout << "[" << i + 1 << "]" << "Purchase field " << i + 1 << " for " << field[i][0] * landPrice << " pounds" << endl;
            //Outputs each field theat they don't already won with its number and the amount it costs to buy.
        }
    }

    cout << "Please enter the number that corrosponds to the field you would like to purchase: ";
    cin >> fieldSelected;
    cout << endl;
    //Allows the user to enter the field they would like to try and buy.

    if (field[fieldSelected - 1][3] == 1) { //Checks to see if the selected field is already owned.
        cout << "Sorry, you already own this field." << endl << endl;
        //Outputs a message to inform the player that the field they are rying to but is already owned by them.
    }
    else {
        if (money > (field[fieldSelected - 1][0] * landPrice)) { //Checks to see if the player has enough money for this.
            money = money - (field[fieldSelected - 1][0] * landPrice); //Deducts the cost of the fields from the players money.
            cout << "You have purchased field " << fieldSelected << "." << endl << endl; //Outputs a message to confirm the transaction.
            field[fieldSelected - 1][3] = 1; //Changes the value to show the field is now owned.
        }
        else {
            cout << "Sorry, you do not have enough money to buy this field." << endl << endl;
            //Outputs a message to inform the player they do not have enough money for this action.
        }
    }

    gamePlay(); //Returns back to the main game menu for more actions to be carried out.

    return(0);
}

int gamePlay() 
{
    string menuOption; //Variable for menu selection.
    int planted; //Variable to Check if the field has a crop planted in.
    string crop; //Variable to store the crop planted.
    string fert; //Variable to store the fertiliser status.

    cout << farmName << "         Money: " << money << "         " << time << ":00  Day: " << day << "   Year: " << year << endl << endl << "Fields:" << endl;
    //Output showing the current stats of the game: Money, time and date.

    for (int i = 0; i <= 29; i++) {
        if (field[i][3] == 1) { //Checks through the multidimensional array to see which fields are owned.
            if (field[i][1] != 0) { //Checks to see if there is anything planted in the field.
                planted = field[i][3];
                switch (planted) { //Switch block sets the string to the crop type to output it.
                case 1:
                    crop = "Wheat";
                    break;
                case 2:
                    crop = "Barley";
                    break;
                case 3:
                    crop = "OSR";
                    break;
                case 4:
                    crop = "Oats";
                    break;
                case 5:
                    crop = "Fieldbeans";
                    break;
                case 6: 
                    crop = "Potatoes";
                    break;
                case 7:
                    crop = "Sugar Beets";
                    break;
                }
            }
            else {
                crop = "Empty";
            }
            
            if (field[i][2] == 1) { //Checks to see if the owned fields have been fertilised.
                fert = "Fertilised";
            }
            else {
                fert = "Not Fertilised";
            }

            cout << "[" << i + 1 << "]  " << crop << "  " << fert << endl;
            //Outputs each owned filed with the crop in it and its fertilized status.
        }
    }

    cout << endl << "[1] Purchase a new field" << endl << "[2] Field Work" << endl << "[3] Go to sleep" << endl <<  "Please slect an optiom (1, 2 or 3): ";
    cin >> menuOption;
    cout << endl << endl;
    //Outputs a menu to allow the user to select what actions the wish to perform.

    if (menuOption == "1") {
        fieldPurchase(); //Option 1 is purchase new fields.
    }
    else if (menuOption == "2") {
        fieldSale(); //Option 2 is sell owned fields.
    }
    else if (menuOption == "3") { //Option 3 is to perform field work actions.
        time = 8; //Resets time for a new day.
        if (day == 36) { //Checks if at the end of the year.
            day = 1;
            year++;
            //If we are at the end of the day increaes the year and resets the day to 1.
        }
        else {
            day++; //Increases the day by 1.
        }
        gamePlay(); //Restarts this procedure for the next day.
    }
    else {
        cout << "That is an invalid etry... Try again." << endl << endl;
        gamePlay();
        //If the entry isn't valid it produces an error message and restarts the procedure to allow the player to try again.
    }

    return(0);
}

int gameInitialization() //Game initialization menu.
{
    cout << "You have recieved a letter..." << endl << endl << "You open the letter and its from a distant relative." << endl << endl << "It reads:" << endl << "You have inherited" <<
        " our family farm. Please arrive as soon as possible to resume operations." << endl << endl << "But you have never operated a farm..." << endl << endl << "HERE WE GO..." <<
        endl << endl;
    //A serious of outputs providing a story to the farm, and how you came to own it.

    cout << "Please enter your farm's name: ";
    cin >> farmName;
    cout << endl;
    //Allows the user to enter a name for their new farm.

    money = 50000;
    year = 1;
    day = 1;
    time = 8;
    //Initialises the game by setting the initial money and and date/time.

    gamePlay(); //Goes to the main gameplay menu.

    return(0);
}

int start() //Start menu procedure.
{
    char gameStart; //Variable for menu options.

    cout << "To start a game please enter 'S', alternatively, to exit the game enter 'E': ";
    cin >> gameStart;
    cout << endl << endl;
    //Simple option to allow the player to start or exit the game.

    if (gameStart = "S" or "s") {
        gameInitialization(); //Goes to the menu to start a game.
    }
    else if (gameStart = "E" or "e") {
        exit(1); //Ends the current session.
    }
    else {
        cout << "Sorry, that was an invalid entry. Please try again..." << endl << endl;
        start();
        //Informs the player that they have entered an invalid option and restarts the procedure so they can re-try.
    }

    return(0);
}

int main()
{
    cout << "Welcome to Farming Mayhem, a game about the struggles faced by farmers around the country and what goes into producing" << endl << "the food on your plate."
        << endl << endl << "For easier playing of the game the days in the year have been divided by 10 to 36 days in a year rather than 365." << endl << endl;
    //Start message to inform the player of the game.

    start();
    //Goes to start procedure.

    return(0);
}