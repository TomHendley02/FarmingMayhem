// FarmingMayhem.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
using namespace std;

string farmName;
double money;
int year;
int day;
int time;

//Empty = 0         Not Fertilised = 0        Not Owned = 0
//Wheat = 1         Fertilised = 1            Owned = 1
//Barley = 2
//OSR = 3
//Oats = 4
//Fieldbeans = 5
//Potatoes = 6
//Sugar Beets = 7
double field[30][4]{
    {10.38, 0, 0}, {12.19, 0, 0}, {25.16, 0, 0}, {64.67, 0, 0}, {18.84, 0, 0},
    {22.32, 0, 0}, {18.45, 0, 0}, {03.97, 0, 0}, {09.43, 0, 0}, {12.88, 0, 0},
    {21.78, 0, 0}, {32.39, 0, 0}, {05.12, 0, 0}, {14.64, 0, 0}, {27.11, 0, 0},
    {10.12, 0, 0}, {25.82, 0, 0}, {50.02, 0, 0}, {31.01, 0, 0}, {06.99, 0, 0},
    {18.10, 0, 0}, {19.45, 0, 0}, {11.64, 0, 0}, {15.07, 0, 0}, {33.27, 0, 0},
    {12.67, 0, 0}, {08.84, 0, 0}, {61.87, 0, 0}, {43.08, 0, 0}, {17.56, 0, 0}
};

double landPrice = 10600;
double fertiliserPrice = 163.97;
double seedPrice = 56.68;
double fuelCosts = 24.29;
double labourCosts = 82.59;

double wheatYield = 2.83;
double barelyYield = 2.39;
double osrYield = 1.1;
double oatsYield = 1.98;
double fieldbeansYield = 1.34;
double potatoesYield;
double beetsYield;

int gameInitialization() //Game initialization menu.
{
    cout << "Please enter your farm's name: ";
    cin >> farmName;
    cout << endl;

    money = 450000;
    year = 1;
    day = 1;
    time = 900;
    
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
    cout << "Welcome to Farming Mayhem, a game about the struggles faced by farmers around the country and what goes into producing" << endl << "the food on your plate." << endl << endl;
    //Start message to inform the player of the game.

    start();
    //Goes to start procedure.

    return(0);
}