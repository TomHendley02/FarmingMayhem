// FarmingMayhem.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cmath>
using namespace std;

string farmName;
double money;
int year;
int day;
double time;

//Empty = 0                 //                          Owned
//Wheat = 1                 //                       Straw  |
//Barley = 2                //                Harvested  |  |
//OSR = 3                   //            Fertilised  |  |  |
//Oats = 4                  //             Seeded  |  |  |  |
//Fieldbeans = 5            //      Cultivated  |  |  |  |  |
//Potatoes = 6              //     Ploughed  |  |  |  |  |  |
//Sugar Beets = 7           //    Size    |  |  |  |  |  |  |
double field[30][8]{        //       |    |  |  |  |  |  |  |
    {10.38, 1, 0, 0, 0, 0, 0, 1}, {12.19, 0, 0, 0, 0, 0, 0, 1}, {25.16, 0, 0, 0, 0, 0, 0, 0}, {64.67, 0, 0, 0, 0, 0, 0, 0}, {18.84, 1, 1, 0, 0, 0, 0, 1},
    {22.32, 0, 0, 0, 0, 0, 0, 0}, {18.45, 0, 0, 0, 0, 0, 0, 0}, {03.97, 0, 0, 0, 0, 0, 0, 0}, {09.43, 0, 0, 0, 0, 0, 0, 0}, {12.88, 0, 0, 0, 0, 0, 0, 0},
    {21.78, 0, 0, 0, 0, 0, 0, 0}, {32.39, 0, 0, 0, 0, 0, 0, 0}, {05.12, 0, 0, 0, 0, 0, 0, 0}, {14.64, 0, 0, 0, 0, 0, 0, 0}, {27.11, 0, 0, 0, 0, 0, 0, 0},
    {10.12, 0, 0, 0, 0, 0, 0, 0}, {25.82, 0, 0, 0, 0, 0, 0, 0}, {50.02, 0, 0, 0, 0, 0, 0, 0}, {31.01, 0, 0, 0, 0, 0, 0, 0}, {06.99, 0, 0, 0, 0, 0, 0, 0},
    {18.10, 0, 0, 0, 0, 0, 0, 0}, {19.45, 0, 0, 0, 0, 0, 0, 0}, {11.64, 0, 0, 0, 0, 0, 0, 0}, {15.07, 0, 0, 0, 0, 0, 0, 0}, {33.27, 0, 0, 0, 0, 0, 0, 0},
    {02.67, 0, 0, 0, 0, 0, 0, 0}, {08.84, 0, 0, 0, 0, 0, 0, 0}, {61.87, 0, 0, 0, 0, 0, 0, 0}, {43.08, 0, 0, 0, 0, 0, 0, 0}, {17.56, 0, 0, 0, 0, 0, 0, 0}
};

double landPrice = 10600;
double fertiliserPrice = 163.97;
double seedPrice = 56.68;
double fuelPrice = 6.89;

double wheatYield = 2.83;
double barelyYield = 2.39;
double osrYield = 1.1;
double oatsYield = 1.98;
double fieldbeansYield = 1.34;
double potatoesYield = 10.12;
double beetsYield = 32.83;

int gamePlay();
int start();

int fieldworkMenu()
{
    string crop; //Variable to store the crop planted.
    int menuSelection;
    string confirmTask;
    int cropSelection;

    cout << "Fields to work on:" << endl;
    for (int i = 0; i <= 29; i++) {
        if (field[i][7] == 1) { //Checks through the multidimensional array to see which fields are owned.
            if (field[i][3] == 1) { //Checks to see if there is anything planted in the field.
                crop = "Wheat";
            }
            else if (field[i][3] == 2) {
                crop = "Barley";
            }
            else if (field[i][3] == 3) {
                crop = "OSR";
            }
            else if (field[i][3] == 4) {
                crop = "Oats";
            }
            else if (field[i][3] == 5) {
                crop = "Fieldbeans";
            }
            else if (field[i][3] == 6) {
                crop = "Potatoes";
            }
            else if (field[i][3] == 7) {
                crop = "Sugar Beets";
            }
            else {
                crop = "Empty";
            }

            cout << "[" << i+1 << "]   " << "Crop: " << crop << "   ";

            if (field[i][1] == 1) {
                if (field[i][2] == 1) {
                    if (field[i][3] != 0) {
                        if (field[i][4] == 1) {
                            if (field[i][5] == 1) {
                                cout << "Needs Harvesting." << endl;
                            }
                        else if (field[i][5] > 1) {
                            cout << "Growing... " << field[i][5] << " Days Left." << endl;
                        }
                            else {
                                if (field[i][6] == 1) {
                                   cout << "Straw Needs Collecting" << endl;
                                }
                            }
                        }
                        else {
                            cout << "Needs Fertilising." << endl;
                        }
                    }
                    else {
                        cout << "Needs Sowing." << endl;
                    }
                }
                else {
                    cout << "Needs Cultivating." << endl;
                }
            }
            else {
                cout << "Needs Ploughing." << endl;
            }
        }
    }

    cout << "Please select the number field you would like to do the next stage of work on [x]: ";
    cin >> menuSelection;
    cout << endl;

    if (field[menuSelection - 1][1] == 0) {
        cout << "It will cost " << round(field[menuSelection - 1][0] * 6.89 * 2) << " pounds in fuel and take " << round(field[menuSelection - 1][0] / 4) << " hours." << endl <<
            "Do you wish to carry out this task (Y or N): ";
        cin >> confirmTask;
        cout << endl;
        if (confirmTask == "y" or "y") {
            if ((money > (field[menuSelection - 1][0] * 6.89) * 2) & (time < 24 - (field[menuSelection - 1][0] / 4))) {
                field[menuSelection - 1][1] = 1;
                money = money - (field[menuSelection - 1][0] * 6.89) * 2;
                time = time + field[menuSelection - 1][0] / 4;
                gamePlay();
            }
            else {
                cout << "Sorry, it appears you do not have enough money or time left in the day for this action." << endl << endl;
                gamePlay();
            }
        }
        else if (confirmTask == "N" or "n") {
            gamePlay();
        }
        else {
            cout << "Sorry, that is an invalid input, try again..." << endl;
            fieldworkMenu();
        }
    }
    else {
        if (field[menuSelection - 1][2] == 0) {
            cout << "It will cost " << round(field[menuSelection - 1][0] * 6.89 * 2) << " pounds in fuel and take " << round(field[menuSelection - 1][0] / 4) << " hours." << endl <<
                "Do you wish to carry out this task (Y or N): ";
            cin >> confirmTask;
            cout << endl;
            if (confirmTask == "y" or "y") {
                if ((money > (field[menuSelection - 1][0] * 6.89) * 2) & (time < 24 - (field[menuSelection - 1][0] / 4))) {
                    field[menuSelection - 1][2] = 1;
                    money = money - (field[menuSelection - 1][0] * 6.89) * 2;
                    time = time + field[menuSelection - 1][0] / 4;
                    gamePlay();
                }
                else {
                    cout << "Sorry, it appears you do not have enough money or time left in the day for this action." << endl << endl;
                    gamePlay();
                }
            }
            else if (confirmTask == "N" or "n") {
                gamePlay();
            }
            else {
                cout << "Sorry, that is an invalid input, try again..." << endl;
                fieldworkMenu();
            }
        }
        else {
            if (field[menuSelection - 1][3] == 0) {
                cout << "[1] Wheat" << endl << "[2] Barley" << endl << "[3] OSR" << endl << "[4] Oats" << endl <<
                    "[5] Fieldbeans" << endl << "[6] Potatoes" << endl << "[7] Sugar Beets" << endl << "Please select which crop you wish to be planted: ";
                cin >> cropSelection;
                cout << endl;
                cout << "It will cost " << round(field[menuSelection - 1][0] * 6.89) << " pounds in fuel, cost " << round(field[menuSelection - 1][0] * seedPrice) << "pounds in seed" 
                    << " and take " << round(field[menuSelection - 1][0] / 4) << " hours." << endl << "Do you wish to carry out this task (Y or N): ";
                cin >> confirmTask;
                cout << endl;
                if (confirmTask == "y" or "y") {
                    if ((money > (field[menuSelection - 1][0] * 6.89) + (field[menuSelection - 1][0] * seedPrice)) & (time < 24 - (field[menuSelection - 1][0] / 4))) {
                        if (cropSelection == 1 & (day > 6 & day <= 12)) {
                            field[menuSelection - 1][3] = cropSelection;
                            money = money - ((field[menuSelection - 1][0] * 6.8) + (field[menuSelection - 1][0] * seedPrice));
                            time = time + field[menuSelection - 1][0] / 4;
                            gamePlay();
                        }
                        else if (cropSelection == 2 & (day > 6 & day <= 15)) {
                            field[menuSelection - 1][3] = cropSelection;
                            money = money - ((field[menuSelection - 1][0] * 6.8) + (field[menuSelection - 1][0] * seedPrice));
                            time = time + field[menuSelection - 1][0] / 4;
                            gamePlay();
                        } 
                        else if (cropSelection == 3 & (day > 3 & day <= 12)) {
                            field[menuSelection - 1][3] = cropSelection;
                            money = money - ((field[menuSelection - 1][0] * 6.8) + (field[menuSelection - 1][0] * seedPrice));
                            time = time + field[menuSelection - 1][0] / 4;
                            gamePlay();
                        } 
                        else if (cropSelection == 4 & (day > 4 & day <= 12)) {
                            field[menuSelection - 1][3] = cropSelection;
                            money = money - ((field[menuSelection - 1][0] * 6.8) + (field[menuSelection - 1][0] * seedPrice));
                            time = time + field[menuSelection - 1][0] / 4;
                            gamePlay();
                        } 
                        else if (cropSelection == 5 & (day > 4 & day <= 12)) {
                            field[menuSelection - 1][3] = cropSelection;
                            money = money - ((field[menuSelection - 1][0] * 6.8) + (field[menuSelection - 1][0] * seedPrice));
                            time = time + field[menuSelection - 1][0] / 4;
                            gamePlay();
                        } 
                        else if (cropSelection == 6 & (day > 9 & day <= 15)) {
                            field[menuSelection - 1][3] = cropSelection;
                            money = money - ((field[menuSelection - 1][0] * 6.8) + (field[menuSelection - 1][0] * seedPrice));
                            time = time + field[menuSelection - 1][0] / 4;
                            gamePlay();
                        } 
                        else if (cropSelection == 7 & (day > 7 & day <= 13)) {
                            field[menuSelection - 1][3] = cropSelection;
                            money = money - (field[menuSelection - 1][0] * 6.8) + (field[menuSelection - 1][0] * seedPrice);
                            time = time + field[menuSelection - 1][0] / 4;
                            gamePlay();
                        }
                        else {
                            cout << "It appears you are in the wrong season to plant this crop." << endl;
                            gamePlay();
                        }
                    }
                    else {
                        cout << "Sorry, it appears you do not have enough money or time left in the day for this action." << endl << endl;
                        gamePlay();
                    }
                }
                else if (confirmTask == "N" or "n") {
                    gamePlay();
                }
                else {
                    cout << "Sorry, that is an invalid input, try again..." << endl;
                    fieldworkMenu();
                }
            }
            else {

            }
        }
    }

    return(0);
}

int fieldSale() 
{
    int fieldSelected; //Variable for selecting whch field to sell.

    cout << "Fields you are able to sell: " << endl;
    for (int i = 0; i <= 29; i++) {
        if (field[i][7] == 1) { //Loops through and checks for which fields are currently owned by the player.
            cout << "[" << i + 1 << "]" << "Sell field " << i + 1 << " for " << field[i][0] * (landPrice * 0.8) << " pounds" << endl;
            //Outputs each field that the player currenly owns and the price that ti will sell for.
        }
    }

    cout << "Please enter the number that corrosponds to the field you would like to sell: ";
    cin >> fieldSelected;
    cout << endl;
    //Allows the user to enter the field they would like to try and sell.

    if (field[fieldSelected - 1][7] == 0) { //Checks to see if the selected field is already not owned.
        cout << "Sorry, you don't own this field to sell." << endl << endl;
        //Outputs a message to inform the player that the field they are trying to sell isn't owned by them.
    }
    else {
        money = money + (field[fieldSelected - 1][0] * (landPrice * 0.8)); //Adds the value of the field to the players money.
        cout << "You have sold field " << fieldSelected << "." << endl << endl; //Outputs a message to confirm the transaction.
        field[fieldSelected - 1][3] = 0; //Changes the value to show the field is now not owned.
    }

    gamePlay(); //Returns back to the main game menu for more actions to be carried out.

    return(0);
}

int fieldPurchase() 
{
    int fieldSelected; //Variable for selecting whch field to buy.

    cout << "Fields for purchase: " << endl;
    for (int i = 0; i <= 29; i++) {
        if (field[i][7] == 0) { //Loops through and checks for which fields are currently not owned by the player.
            cout << "[" << i + 1 << "]" << "Purchase field " << i + 1 << " for " << field[i][0] * landPrice << " pounds" << endl;
            //Outputs each field that they don't already won with its number and the amount it costs to buy.
        }
    }

    cout << "Please enter the number that corrosponds to the field you would like to purchase: ";
    cin >> fieldSelected;
    cout << endl;
    //Allows the user to enter the field they would like to try and buy.

    if (field[fieldSelected - 1][7] == 1) { //Checks to see if the selected field is already owned.
        cout << "Sorry, you already own this field." << endl << endl;
        //Outputs a message to inform the player that the field they are trying to buy is already owned by them.
    }
    else {
        if (money > (field[fieldSelected - 1][7] * landPrice)) { //Checks to see if the player has enough money for this.
            money = money - (field[fieldSelected - 1][0] * landPrice); //Deducts the cost of the field from the players money.
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
    string crop; //Variable to store the crop planted.

    cout << farmName << "         Money: " << round(money) << "         " << round(time) << ":00  Day: " << day << "   Year: " << year << endl << endl << "Fields:" << endl;
    //Output showing the current stats of the game: Money, time and date.

    for (int i = 0; i <= 29; i++) {
        if (field[i][7] == 1) { //Checks through the multidimensional array to see which fields are owned.
            if (field[i][3] == 1) { //Checks to see if there is anything planted in the field.
                crop = "Wheat";
            }
            else if (field[i][3] == 2) {
                crop = "Barley";
            }
            else if (field[i][3] == 3) {
                crop = "OSR";
            }
            else if (field[i][3] == 4) {
                crop = "Oats";
            }
            else if (field[i][3] == 5) {
                crop = "Fieldbeans";
            }
            else if (field[i][3] == 6) {
                crop = "Potatoes";
            }
            else if (field[i][3] == 7) {
                crop = "Sugar Beets";
            }
            else {
                crop = "Empty";
            }

            cout << "[" << i + 1 << "]   " << "Crop: " << crop << "   ";

            if (field[i][1] == 1) {
                if (field[i][2] == 1) {
                    if (field[i][3] != 0) {
                        if (field[i][4] == 1) {
                            if (field[i][5] == 1) {
                                cout << "Needs Harvesting." << endl;
                            }
                            else if (field[i][5] > 1) {
                                cout << "Growing... " << field[i][5] << " Days Left." << endl;
                            }
                            else {
                                if (field[i][6] == 1) {
                                    cout << "Straw Needs Collecting" << endl;
                                }
                            }
                        }
                        else {
                            cout << "Needs Fertilising." << endl;
                        }
                    }
                    else {
                        cout << "Needs Sowing." << endl;
                    }
                }
                else {
                    cout << "Needs Cultivating." << endl;
                }
            }
            else {
                cout << "Needs Ploughing." << endl;
            }
        }
    }

    cout << endl << "[1] Purchase a new field" << endl << "[2] Sell an owned field" << endl << "[3] Fieldwork" << endl << "[4] Go to sleep" << endl << "[5] Exit" << endl 
        << "Please slect an optiom (1, 2 or 3): ";
    cin >> menuOption;
    cout << endl << endl;
    //Outputs a menu to allow the user to select what actions the wish to perform.

    if (menuOption == "1") {
        fieldPurchase(); //Option 1 is purchasing new fields.
    }
    else if (menuOption == "2") {
        fieldSale(); //Option 2 is selling owned fields.
    }
    else if (menuOption == "3") {
        fieldworkMenu(); //Option 3 goes to the menu for carrying out different fieldwork.
    }
    else if (menuOption == "4") { //Option 4 is for sleeping to the next day.
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
    else if (menuOption == "5") { //Option 5 is to go back to the main menu.
        start(); //Goes back to the main menu of the game.
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
        exit;
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