// FarmingMayhem.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
//Uses name space standard and includes iostream, cmath and stdlib.h.

string farmName;
double money;
int year;
int day;
double time;
//Variables for the farms name, money, date and time.

//Empty = 0                                             Owned
//Wheat = 1                                          Straw  |
//Barley = 2                                  Harvested  |  |
//OSR = 3                                 Fertilised  |  |  |
//Oats = 4                                 Seeded  |  |  |  |
//Fieldbeans = 5                    Cultivated  |  |  |  |  |
//Potatoes = 6                     Ploughed  |  |  |  |  |  |
//Sugar Beets = 7                 Size    |  |  |  |  |  |  |
double field[30][8]{ //              |    |  |  |  |  |  |  |
    {10.38, 1, 0, 0, 0, 0, 0, 1}, {12.19, 0, 0, 0, 0, 0, 0, 1}, {25.16, 0, 0, 0, 0, 0, 0, 0}, {64.67, 0, 0, 0, 0, 0, 0, 0}, {18.84, 1, 1, 0, 0, 0, 0, 1},
    {22.32, 0, 0, 0, 0, 0, 0, 0}, {18.45, 0, 0, 0, 0, 0, 0, 0}, {03.97, 0, 0, 0, 0, 0, 0, 0}, {09.43, 0, 0, 0, 0, 0, 0, 0}, {12.88, 0, 0, 0, 0, 0, 0, 0},
    {21.78, 0, 0, 0, 0, 0, 0, 0}, {32.39, 0, 0, 0, 0, 0, 0, 0}, {05.12, 0, 0, 0, 0, 0, 0, 0}, {14.64, 0, 0, 0, 0, 0, 0, 0}, {27.11, 0, 0, 0, 0, 0, 0, 0},
    {10.12, 0, 0, 0, 0, 0, 0, 0}, {25.82, 0, 0, 0, 0, 0, 0, 0}, {50.02, 0, 0, 0, 0, 0, 0, 0}, {31.01, 0, 0, 0, 0, 0, 0, 0}, {06.99, 0, 0, 0, 0, 0, 0, 0},
    {18.10, 0, 0, 0, 0, 0, 0, 0}, {19.45, 0, 0, 0, 0, 0, 0, 0}, {11.64, 0, 0, 0, 0, 0, 0, 0}, {15.07, 0, 0, 0, 0, 0, 0, 0}, {33.27, 0, 0, 0, 0, 0, 0, 0},
    {02.67, 0, 0, 0, 0, 0, 0, 0}, {08.84, 0, 0, 0, 0, 0, 0, 0}, {61.87, 0, 0, 0, 0, 0, 0, 0}, {43.08, 0, 0, 0, 0, 0, 0, 0}, {17.56, 0, 0, 0, 0, 0, 0, 0}
};
//Array of all 30 fields and it stores the current fieldwork state, the size of the field and whether the player owns them or not.
//Fields 1, 2 and 5 are owned by the player at the start of the game.

double landPrice = 10600;
double fertiliserPrice = 163.97;
double seedPrice = 56.68;
double fuelPrice = 6.89;
//Variables for setting out the starting costs.

double wheatYield = 3.6;
double barleyYield = 3.89;
double osrYield = 2.35;
double oatsYield = 2.31;
double fieldbeansYield = 1.92;
double potatoesYield = 6.72;
double beetsYield = 8.4;
double strawYield = 13.28;
//Variable for setting out the average yield of each crop in tons per acre.

double wheatPrice = 106.19;
double barleyPrice = 100.62;
double osrPrice = 142.42;
double oatsPrice = 148.9;
double fieldbeansPrice = 174.04;
double potatoesPrice = 45.08;
double beetsPrice = 38.49;
double strawPrice = 12.91;
//Variables setting out the standard base game crop sale prices.

double weatherMultiplier = 1;
//Variable for determining if there are any weather impacts.

double wheatPestMultiplier = 1;
double barleyPestMultiplier = 1;
double osrPestMultiplier = 1;
double oatsPestMultiplier = 1;
double fieldbeansPestMultiplier = 1;
double potatoesPestMultiplier = 1;
double beetsPestMultiplier = 1;
//Variables for determining if there is a pest on a given crop.

double wheatMultiplier = 1;
double barleyMultiplier = 1;
double osrMultiplier = 1;
double oatsMultiplier = 1;
double fieldbeansMultiplier = 1;
double potatoesMultiplier = 1;
double beetsMultiplier = 1;
double strawMultiplier = 1;
//Variables for storing the multipliers of crops.

int gamePlay();
int start();
int fieldworkMenu();
//Forwards to previously written functions and procedures so they can be accessed.

int checkGameEnd() {
    if (money <= 0) {
        cout << "The end of they year has come and it appears you have run out of money..." << endl << endl << "GAME OVER" << endl << endl;
        exit(1);
    }
    //If the player reaches the end of a year and they are in negative meoney from random events then the game ends.

    return(0);
}

int randomEvent() {
    int moneyEvent = 0;
    int weatherEvent = 0;
    int eventChance = 0;
    int priceChange = 0;
    int comodChange = 0;
    int demandChange  = 0;
    //Variables for determining if random events occur.

    bool wheatMultiplierOn = false;
    bool barleyMultiplierOn = false;
    bool osrMultiplierOn = false;
    bool oatsMultiplierOn = false;
    bool fieldbeansMultiplierOn = false;
    bool potatoesMultiplierOn = false;
    bool beetsMultiplierOn = false;
    bool strawMultiplierOn = false;
    //Variables for determining if there is a current great demand active for a certain crop.

    int wheatCount = 0;
    int barleyCount = 0;
    int osrCount = 0;
    int oatsCount = 0;
    int fieldbeansCount = 0;
    int potatoesCount = 0;
    int beetsCount = 0;
    //Variables for counting how many crops are planted at 1 time.

    cout << "CHANCE FOR RANDOM EVENT!" << endl << endl;  //Lets the player know there is a chance for a random event.
    
    if (year == 1) {
        eventChance = rand() % 20 + 1;
        //If in year 1 there is a 1/4 chance of a random event possibly occuring.
    }
    else if (year == 2) {
        eventChance = rand() % 15 + 1;
        //If in year 2 there is a 1/3 chance of a random event possibly occuring.
    }
    else if (year == 3) {
        eventChance = rand() % 10 + 1;
        //If in year 3 there is a 1/2 chamce of a random event possibly occuring.
    }
    else if (year >= 4) {
        eventChance = rand() % 6 + 1;
        //If in year 4 or more there is a 5/6 chance of a random event possibly occuring.
    }

    //Three predetermined events based of real life events: Brexit, Russia/Ukraine War and Covid-19.
    if (year == 2 && day == 19) { //If it is day 19 year 2 'Brexit' event occurs.
        cout << "You country has decided to leave its coalition with other countries and this has affected the price of goods..." << endl << endl;
        
        wheatMultiplier = wheatMultiplier * 0.9;
        barleyMultiplier = barleyMultiplier * 0.9;
        osrMultiplier = osrMultiplier * 0.9;
        oatsMultiplier = oatsMultiplier * 0.9;
        fieldbeansMultiplier = fieldbeansMultiplier * 0.9;
        potatoesMultiplier = potatoesMultiplier * 0.9;
        beetsMultiplier = beetsMultiplier * 0.9;
        strawMultiplier = strawMultiplier * 0.9;
        //Good prices decrease by 10%.

        fuelPrice = fuelPrice * 1.1;
        fertiliserPrice = fertiliserPrice * 1.1;
        seedPrice = seedPrice * 1.1;
        //Costs increase by 10%.
    }
    else if (year == 3 && day == 15) { //If it is day 15 in year 3 the 'Russia/Ukraine War' event occurs.
        cout << " A war has broken out in one of the biggest exporters of oil and fertiliser, this will affect these prices..." << endl << endl;

        fuelPrice = fuelPrice * 2;
        //Fuel prices double.
        fertiliserPrice = fertiliserPrice * 1.5;
        //Fertiliser prices increase by 50%.
    }
    else if (year == 4 && day == 2) { //If it is day 2 year 4 the 'Covid-19' event occurs.
        cout << "A viral pandemic has broken out and it has affected certain prices and costs..." << endl << endl;

        wheatMultiplier = wheatMultiplier * 0.9;
        barleyMultiplier = barleyMultiplier * 0.8;
        osrMultiplier = osrMultiplier * 0.9;
        oatsMultiplier = oatsMultiplier * 0.9;
        fieldbeansMultiplier = fieldbeansMultiplier * 0.9;
        potatoesMultiplier = potatoesMultiplier * 0.9;
        beetsMultiplier = beetsMultiplier * 0.9;
        //Cost of good decreases by 10 percent exept barley which decreases by 20% as it is mainly used for beer brewing and all pubs and bars are shut.

        fuelPrice = fuelPrice * 1.2;
        fertiliserPrice = fertiliserPrice * 1.2;
        //Fuel price increases by 20% and fertiliser prices increase by 20%.
    }
    else if (year == 5 && day == 26) { //If it is day 26 year 5 than the pandemic ends.
        cout << "The pandemic that started last year has now ended." << endl << endl;

        wheatMultiplier = wheatMultiplier * 1.01;
        barleyMultiplier = barleyMultiplier * 1.15;
        osrMultiplier = osrMultiplier * 1.05;
        oatsMultiplier = oatsMultiplier * 1.05;
        fieldbeansMultiplier = fieldbeansMultiplier * 1.05;
        potatoesMultiplier = potatoesMultiplier * 1.05;
        beetsMultiplier = beetsMultiplier * 1.05;
        //Goods prices increase but not completely to ensure a harder gameplay this deep into the game.

        fuelPrice = fuelPrice * 0.93;
        fertiliserPrice = fertiliserPrice * 0.81;
        //Fuel and fertiliser prices lower but not to original values to ensure a harder level of gameplay.
    }
    else {
        if (eventChance <= 5) { //Checks what the cahnce of an event is.
            if (day % 3 == 0) { //If the day number is devisable by 3 chance of money event.
                if (money >= 1000 && money < 15000) {
                    moneyEvent = rand() % 50 + 1;
                    //If money is greater the £7500 and less than £15000 makes the chance between 1 and 50.
                }
                else if (money >= 15000) {
                    moneyEvent = rand() % 100 + 1;
                    //If money is greater than £15000 makes the chance between 1 and 100 allowing for more costly events.
                }
                else {
                    moneyEvent = 0;
                    //If money is less than £7500 sets the chance to 0.
                }

                if (moneyEvent > 0 && moneyEvent <= 25) { //Depending on the number genetrated there is a chance of 1 of 4 events occuring...
                    cout << "One of your machines has broken down... You have to pay 2500 pounds to repair it." << endl << endl;
                    money = money - 2500;
                    //£2500 is deducted for broken machinery.
                }
                else if (moneyEvent > 25 && moneyEvent <= 50) {
                    cout << "One of your vehicles was involved in an accident! You have to pay 1000 pounds for repairs and costs." << endl << endl;
                    money = money - 1000;
                    //£1000 is deducted for a traffic accident.
                }
                else if (moneyEvent > 50 && moneyEvent <= 75) {
                    cout << "One of the buildings on the farm has faced severe damage.. You have to pay 5500 pounds to repair it." << endl << endl;
                    money = money - 5500;
                    //£5500 is deducted for building repairs.
                }
                else if (moneyEvent > 75) {
                    cout << "A member of public had an accident on your land... You have to pay 8000 pounds toward legal fees." << endl << endl;
                    money = money - 8000;
                    //£8000 is deducted for legal costs.
                }
                else {
                    cout << "There is no random event today..." << endl << endl; //Outputs that there will be no random event today.
                }
            }
            else if (day == 20) { //If day equals 20 then will check to see if a pest event can occur.
                for (int i = 0; i <= 29; i++) { //Cycles through each field checking what crops are planted.
                    if (field[i][3] == 1) {
                        wheatCount++; //If wheat is planted counts this.
                    }
                    else if (field[i][3] == 2) {
                        barleyCount++; //If barley is planted counts this.
                    }
                    else if (field[i][3] == 3) {
                        osrCount++; //If OSR is planted counts this.
                    }
                    else if (field[i][3] == 4) {
                        oatsCount++; //If oats are palnted counts this.
                    }
                    else if (field[i][3] == 5) {
                        fieldbeansCount++; //If fieldbeans are planted counts this.
                    }
                    else if (field[i][3] == 6) {
                        potatoesCount++; //If potatoes are planted counts this.
                    }
                    else if (field[i][3] == 7) {
                        beetsCount++; //If beets are planted counts this.
                    }

                    if (wheatCount > 2) {
                        cout << "Your wheat has been ravished by pests and yield will drop by 25%." << endl << endl;
                        wheatPestMultiplier = 0.75;
                        //If more then 2 fields contain wheat they become infested and yield decreases by 25 percent.
                    }
                    else if (barleyCount > 2) {
                        cout << "Your barley has been ravished by pests and yield will drop by 25%." << endl << endl;
                        barleyPestMultiplier = 0.75;
                        //If more then 2 fields contain barley they become infested and yield decreases by 25 percent.
                    }
                    else if (osrCount > 2) {
                        cout << "Your OSR has been ravished by pests and yield will drop by 25%." << endl << endl;
                        osrPestMultiplier = 0.75;
                        //If more then 2 fields contain OSR they become infested and yield decreases by 25 percent.
                    }
                    else if (oatsCount > 2) {
                        cout << "Your oats have been ravished by pests and yield will drop by 25%." << endl << endl;
                        oatsPestMultiplier = 0.75;
                        //If more then 2 fields contain oats they become infested and yield decreases by 25 percent.
                    }
                    else if (fieldbeansCount > 2) {
                        cout << "Your fieldbeans have been ravished by pests and yield will drop by 25%." << endl << endl;
                        fieldbeansPestMultiplier = 0.75;
                        //If more then 2 fields contain fieldbeans they become infested and yield decreases by 25 percent.
                    }
                    else if (potatoesCount > 2) {
                        cout << "Your potatoes have been ravished by pests and yield will drop by 25%." << endl << endl;
                        potatoesPestMultiplier = 0.75;
                        //If more then 2 fields contain potatoes they become infested and yield decreases by 25 percent.
                    }
                    else if (beetsCount > 2) {
                        cout << "Your sugar beets have been ravished by pests and yield will drop by 25%." << endl << endl;
                        beetsPestMultiplier = 0.75;
                        //If more then 2 fields contain beets they become infested and yield decreases by 25 percent.
                    }
                    else {
                        cout << "There is no random event today..." << endl << endl; //Outputs that there will be no random event today.
                    }
                }
            }
            else if (day == 18) { //If the day is day 18 then performs a possible weather event
                weatherEvent = rand() & 4 + 1; //Gets a random number between 1 and 4 to determine a 1/2 chance of a random weather event occuring
                if (weatherEvent == 1) {
                    cout << "You have faced severe drought this year and will effect yields by 15%!" << endl << endl;
                    weatherMultiplier = 0.85;
                    //Adds a multiplier of a 85% yield due to bad weather.
                }
                else if (weatherEvent == 2) {
                    cout << "You have faced extreme rainfall this year and will effect yields by 10%!" << endl << endl;
                    weatherMultiplier = 0.9;
                    //Adds a multiplier of a 90% yield due to bad weather.
                }
                else {
                    cout << "There is no random event today..." << endl << endl; //Outputs that there will be no random event today.
                }
            }
            else if ((money >= 5000) && (day % 5 == 0)) { //If the players money is £5000 or more and the day of the month is devisiable by 5 then it performs a price change event.
                comodChange = rand() % 4 + 1; //Determines which cost woud change by picking a random number between 1 and 4.
                priceChange = rand() % 2 + 1; //Determines whether the price should increase or decrease by selecting either 1 or 2.
                if (comodChange == 1) {
                    //Prices increase by more than they decrease to add to increasing level of difficulty as the game progresses.
                    if (priceChange == 1) {
                        landPrice = landPrice * 1.3;
                        cout << "Land price has increased by 30 percent." << endl << endl;
                        //Increases land price by 30 percent.
                    }
                    else {
                        landPrice = landPrice * 0.8;
                        cout << "Land price has decreased by 20 percent." << endl << endl;
                        //Decreases land price by 20 percent.
                    }
                }
                else if (comodChange == 2) {
                    if (priceChange == 1) {
                        seedPrice = seedPrice * 1.3;
                        cout << "Seed prices has increased by 30 percent." << endl << endl;
                        //Increases seed price by 30 percent.
                    }
                    else {
                        seedPrice = seedPrice * 0.8;
                        cout << "Seed prices has decreased by 20 percent." << endl << endl;
                        //Decreases seed price by 20 percent.
                    }
                }
                else if (comodChange == 3) {
                    if (priceChange == 1) {
                        fertiliserPrice = fertiliserPrice * 1.3;
                        cout << "Fertiliser prices has increased by 30 percent." << endl << endl;
                        //Increases fertiliser prices by 30 percent.
                    }
                    else {
                        fertiliserPrice = fertiliserPrice * 0.8;
                        cout << "Fertiliser prices has decreased by 20 percent." << endl << endl;
                        //Decreases fertiliser prices by 20 percent.
                    }
                }
                else if (comodChange == 4) {
                    if (priceChange == 1) {
                        fuelPrice = fuelPrice * 1.3;
                        cout << "Fuel prices has increased by 30 percent." << endl << endl;
                        //Increases fuel prices by 30 percent.
                    }
                    else {
                        fuelPrice = fuelPrice * 0.8;
                        cout << "Fuel prices has decreased by 20 percent." << endl << endl;
                        //Decreases fuel prices by 20 percent.
                    }
                }
                else {
                    cout << "There is no random event today..." << endl << endl; //Outputs that there will be no random event today.
                }
            }
            else if (money < 2500 && day == 18) { //If they have less than £2500 after planting all crops allows for a chance of a high demand occuring.
                demandChange = rand() % 12 + 1; //Determines a random number between 1 and 12 giving a 2/3 chance of a random high demand event.
                if (demandChange == 1) {
                    cout << "The price of wheat has increased after a great demand." << endl << endl;
                    wheatMultiplierOn = true;
                    wheatMultiplier = wheatMultiplier * 2;
                    //If the chance for wheat high demand is true it doubles the sale price of the crop.
                }
                else if (demandChange == 2) {
                    cout << "The price of barley has increased after a great demand." << endl << endl;
                    barleyMultiplierOn = true;
                    barleyMultiplier = barleyMultiplier * 2;
                    //If the chance for barley high demand is true it doubles the sale price of the crop.
                }
                else if (demandChange == 3) {
                    cout << "The price of OSR has increased after a great demand." << endl << endl;
                    osrMultiplierOn = true;
                    osrMultiplier = wheatMultiplier * 2;
                    //If the chance for osr high demand is true it doubles the sale price of the crop.
                }
                else if (demandChange == 4) {
                    cout << "The price of oats has increased after a great demand." << endl << endl;
                    oatsMultiplierOn = true;
                    oatsMultiplier = oatsMultiplier * 2;
                    //If the chance for oats high demand is true it doubles the sale price of the crop.
                }
                else if (demandChange == 5) {
                    cout << "The price of fieldbeans has increased after a great demand." << endl << endl;
                    fieldbeansMultiplierOn = true;
                    fieldbeansMultiplier = fieldbeansMultiplier * 2;
                    //If the chance for fieldbeans high demand is true it doubles the sale price of the crop.
                }
                else if (demandChange == 6) {
                    cout << "The price of potatoes has increased after a great demand." << endl << endl;
                    potatoesMultiplierOn = true;
                    potatoesMultiplier = potatoesMultiplier * 2;
                    //If the chance for potatoes high demand is true it doubles the sale price of the crop.
                }
                else if (demandChange == 7) {
                    cout << "The price of sugar beets has increased after a great demand." << endl << endl;
                    beetsMultiplierOn = true;
                    beetsMultiplier = beetsMultiplier * 2;
                    //If the chance for beets high demand is true it doubles the sale price of the crop.
                }
                else if (demandChange == 8) {
                    cout << "The price of wheat has increased after a great demand." << endl << endl;
                    strawMultiplierOn = true;
                    strawMultiplier = strawMultiplier * 2;
                    //If the chance for straw high demand is true it doubles the sale price of the crop.
                }
                else {
                    cout << "There is no random event today..." << endl << endl; //Outputs that there will be no random event today.
                }
            }
            else if (day == 35 && year != 1) {
                if (wheatMultiplierOn) {
                    wheatMultiplierOn = false;
                    wheatMultiplier = wheatMultiplier / 2.05;
                    cout << "The great demand has ended." << endl << endl;
                    //Checks if wheat has a high demand and ends it by dividing by a slightly higher number than the multiple to slowly reduce selling costs and make the game increasingly harder.
                }
                else if (barleyMultiplierOn) {
                    barleyMultiplierOn = false;
                    barleyMultiplier = barleyMultiplier / 2.05;
                    cout << "The great demand has ended." << endl << endl;
                    //Checks if barley has a high demand and ends it by dividing by a slightly higher number than the multiple to slowly reduce selling costs and make the game increasingly harder.
                }
                else if (osrMultiplierOn) {
                    osrMultiplierOn = false;
                    osrMultiplier = osrMultiplier / 2.05;
                    cout << "The great demand has ended." << endl << endl;
                    //Checks if osr has a high demand and ends it by dividing by a slightly higher number than the multiple to slowly reduce selling costs and make the game increasingly harder.
                }
                else if (oatsMultiplierOn) {
                    oatsMultiplierOn = false;
                    oatsMultiplier = oatsMultiplier / 2.05;
                    cout << "The great demand has ended." << endl << endl;
                    //Checks if oats has a high demand and ends it by dividing by a slightly higher number than the multiple to slowly reduce selling costs and make the game increasingly harder.
                }
                else if (fieldbeansMultiplierOn) {
                    fieldbeansMultiplierOn = false;
                    fieldbeansMultiplier = fieldbeansMultiplier / 2.05;
                    cout << "The great demand has ended." << endl << endl;
                    //Checks if fieldbeans has a high demand and ends it by dividing by a slightly higher number than the multiple to slowly reduce selling costs and make the game increasingly harder.
                }
                else if (potatoesMultiplierOn) {
                    potatoesMultiplierOn = false;
                    potatoesMultiplier = potatoesMultiplier / 2.05;
                    cout << "The great demand has ended." << endl << endl;
                    //Checks if potatoes has a high demand and ends it by dividing by a slightly higher number than the multiple to slowly reduce selling costs and make the game increasingly harder.
                }
                else if (beetsMultiplierOn) {
                    beetsMultiplierOn = false;
                    beetsMultiplier = beetsMultiplier / 2.05;
                    cout << "The great demand has ended." << endl << endl;
                    //Checks if beets has a high demand and ends it by dividing by a slightly higher number than the multiple to slowly reduce selling costs and make the game increasingly harder.
                }
                else if (strawMultiplierOn) {
                    strawMultiplierOn = false;
                    strawMultiplier = strawMultiplier / 2.05;
                    cout << "The great demand has ended." << endl << endl;
                    //Checks if straw has a high demand and ends it by dividing by a slightly higher number than the multiple to slowly reduce selling costs and make the game increasingly harder.
                }
                else
                {
                    cout << "There is no random event today..." << endl << endl; //Outputs that there will be no random event today.
                }
            }
        }
        else {
        cout << "There is no random event today..." << endl << endl; //Outputs that there will be no random event today.
        }
    cout << "There is no random event today..." << endl << endl; //Outputs that there will be no random event today.
    }

    return(0);
}

int strawHarvest(int menuSelection) {
    string confirmTask; //Variable for confirming menu selection.
    double multiplier = 1; //Variable for determining fertiliser multiplier.
    double yield = 0; //Variable for determining the sale price of the crop.

    if (field[menuSelection - 1][4] == 1) {
        multiplier = 1.5;
    }
    else {
        multiplier = 0.75;
    } //Checks if the field was previously fertilised and sets the multiplier to the correct value.

    yield = strawYield * strawPrice * multiplier * field[menuSelection - 1][0] * weatherMultiplier; //Calculates the sale price of straw based on yield, price, fertiliser state, size and random event multipliers.

    cout << "The cost of collecting the straw from this field is " << round(field[menuSelection - 1][0] * fuelPrice * 2) << " pounds in fuel, it will take " << round(field[menuSelection - 1][0] / 2) << " hours to complete, but will yield " <<
        round(yield) << " pounds worth of profit." << endl << "Do you with to carry out this task (Y or N): ";
    cin >> confirmTask;
    cout << endl; //Allows the user to confirm the task before carrying it out.

    if (confirmTask == "y" or confirmTask == "Y") { //Checks to ensure the player wishes to perform the task.
        if (time < 24 - (field[menuSelection - 1][0] / 4) && money + yield > field[menuSelection - 1][0] * fuelPrice) { //Ensures the user has enouh money and time to perform the task.
            money = money - (field[menuSelection - 1][0] * fuelPrice * 2) + yield; //Deducts the money required to carry out the task and adds the profit from the harvest. Note, fuel is doubled as 2 vehicles would be required.
            time = time - (field[menuSelection - 1][0] / 4); //Adds the time onto the clock to account for the action.
            field[menuSelection - 1][1] = 0;
            field[menuSelection - 1][2] = 0;
            field[menuSelection - 1][3] = 0;
            field[menuSelection - 1][4] = 0;
            field[menuSelection - 1][5] = 0;
            field[menuSelection - 1][6] = 0; //Resets the state of each field allwoing new work to be carried out after straw has been collected.
            gamePlay();
        }
        else {
            cout << "Sorry, it appears you do not have enough money or time left in the day for this action." << endl << endl;
            gamePlay();
            //If the player doesn't have enough money or time it makes them aware and goes back to the gameplay menu with no action being carried out.
        }
    }
    else if (confirmTask == "n" or confirmTask == "N") {
        gamePlay();
        //If the player doesn't have enough money or time it makes them aware and goes back to the gameplay menu with no action being carried out.
    }
    else {
        cout << "That was not a valid input, try again..." << endl << endl;
        fieldworkMenu(); //Returns the player back to the fieldwork menu.
    }
    return(0);
}

int harvesting(int menuSelection) {
    string confirmTask; //Variable for confirming menu selection.
    double multiplier = 1; //Variable for determining fertiliser multiplier.
    double yield = 0; //Variable for determining the sale price of the crop.

    if (field[menuSelection - 1][4] == 1) {
        multiplier = 1.5;
    }
    else {
        multiplier = 0.75;
    } //Checks if the field was previously fertilised and sets the multiplier to the correct value.

    if (field[menuSelection - 1][3] == 1) {
        yield = wheatYield * wheatPrice * multiplier * field[menuSelection - 1][0] * weatherMultiplier * wheatPestMultiplier * wheatMultiplier; //Wheat yields
    }
    else if (field[menuSelection - 1][3] == 2) {
        yield = barleyYield * barleyPrice * multiplier * field[menuSelection - 1][0] * weatherMultiplier * barleyPestMultiplier * barleyMultiplier; //Barley yields
    }
    else if (field[menuSelection - 1][3] == 3) {
        yield = osrYield * osrPrice * multiplier * field[menuSelection - 1][0] * weatherMultiplier * osrPestMultiplier * osrMultiplier; //OSR yields
    }
    else if (field[menuSelection - 1][3] == 4) {
        yield = oatsYield * oatsPrice * multiplier * field[menuSelection - 1][0] * weatherMultiplier * oatsPestMultiplier * oatsMultiplier; //Oat yields
    }
    else if (field[menuSelection - 1][3] == 5) {
        yield = fieldbeansYield * fieldbeansPrice * multiplier * field[menuSelection - 1][0] * weatherMultiplier * fieldbeansPestMultiplier * fieldbeansMultiplier; //Fieldbean yields
    }
    else if (field[menuSelection - 1][3] == 6) {
        yield = potatoesYield * potatoesPrice * multiplier * field[menuSelection - 1][0] * weatherMultiplier * potatoesPestMultiplier * potatoesMultiplier; //Potato yields
    }
    else if (field[menuSelection - 1][3] == 7){
        yield = beetsYield * beetsPrice * multiplier * field[menuSelection - 1][0] * weatherMultiplier * beetsPestMultiplier * beetsMultiplier; //Beet yields
    } //Checks which crop is planted and calculates the proft based on the crops sale price, yield, field size, fertiliser status and event multipliers.
    
    cout << "The cost of harvesting this field is " << round(field[menuSelection - 1][0] * fuelPrice * 2) << " pounds in fuel, it will take " << round(field[menuSelection - 1][0] / 4) << " hours to complete, but will yield " <<
        round(yield) << " pounds worth of profit." << endl << "Do you with to carry out this task (Y or N): ";
    cin >> confirmTask;
    cout << endl; //Allows the user to confirm the task before carrying it out.

    if (time < 24 - (field[menuSelection - 1][0] / 4) && money + yield > field[menuSelection - 1][0] * fuelPrice) { //Ensures the user has enouh money and time to perform the task.
        if (confirmTask == "y" or confirmTask == "Y") { //Checks to ensure the player wishes to perform the task.
            money = money + yield - (field[menuSelection - 1][0] * fuelPrice * 2); //Deducts the money required to carry out the task and adds the profit from the harvest. Note, fuel is doubled as 2 vehicles would be required.
            time = time + (field[menuSelection - 1][0] / 4); //Adds the time onto the clock to account for the action.
            if (field[menuSelection - 1][3] == 1 or field[menuSelection - 1][3] == 2 or field[menuSelection - 1][3] == 4) { //Checks to see if the field harvested contained 1 of the 3 straw crops.
                field[menuSelection - 1][6] = 1; //Sets to show that this field is elidgable for straw collection.
                field[menuSelection - 1][5] = 0; //Sets to show the field has been harvested.
            }
            else {
                field[menuSelection - 1][1] = 0;
                field[menuSelection - 1][2] = 0;
                field[menuSelection - 1][3] = 0;
                field[menuSelection - 1][4] = 0;
                field[menuSelection - 1][5] = 0; //Resets the state of each field allwoing new work to be carried out after harvest.
            }
            gamePlay(); //Returns the player back to the gamepaly menu.
        }
        else if (confirmTask == "n" or confirmTask == "N") {
            gamePlay(); //Returns the player ack to the gameplay menu.
        }
        else {
            cout << "That was not a valid input, try again..." << endl << endl;
            fieldworkMenu(); //Returns the player back to the fieldwork menu.
        }
    }
    else {
        cout << "Sorry, it appears you do not have enough money or time left in the day for this action." << endl << endl;
        gamePlay();
        //If the player doesn't have enough money or time it makes them aware and goes back to the gameplay menu with no action being carried out.
    }

    return(0);
}

int fertilising(int menuSelection) {
    string confirmTask; //Variable for confirming menu selection.

    cout << "You can either choose to fertilise the field to boost the yield, however it will cost more..." << endl << "It will cost " << round(field[menuSelection - 1][0] * fuelPrice) << " pounds in fuel, cost " <<
        round(field[menuSelection - 1][0] * fertiliserPrice) << " pounds in fertiliser" << " and take " << round(field[menuSelection - 1][0] / 4) << " hours." << endl << "Do you wish to carry out this task (Y or N): ";
    //Output message informing the player that this task is optional, and of the costs associated with this task and the benefits of performing the task.
    cin >> confirmTask; 
    cout << endl; //Saves the players decision.
   
    if (confirmTask == "y" or confirmTask == "Y") { //If selected yes carries out the folllowing:
        if ((money > (field[menuSelection - 1][0] * fuelPrice) + (field[menuSelection - 1][0] * fertiliserPrice)) && time < 24 - (field[menuSelection - 1][0] / 4)) { //Checks that the player has enough money and time left in the day.
            field[menuSelection - 1][4] = 1; //Changes the current fertiliser state of the field.
            money = money - (field[menuSelection - 1][0] * fuelPrice) - (field[menuSelection - 1][0] * fertiliserPrice); //Deducts the money required for the work.
            time = time + field[menuSelection - 1][0] / 4; //Increases the time by the time the task took.
            gamePlay(); //Goes back to the main gameplay menu.
        }
        else {
            cout << "Sorry, it appears you do not have enough money or time left in the day for this action." << endl << endl;
            gamePlay();
            //If the player doesn't have enough money or time it makes them aware and goes back to the gameplay menu with no action being carried out.
        }
    }
    else if (confirmTask == "n" or confirmTask == "N") {
        cout << "This field will not be fertilised." << endl;
        field[menuSelection - 1][4] = 2; //Changes the current fertiliser state of the field.
        gamePlay();
        //If the player determins they don't wish to carry the task out they are taken back to the gameplay menu and the field will be marked as not fertilised.
    }
    else {
        cout << "Sorry, that is an invalid input, try again..." << endl;
        fieldworkMenu();
        //If any other input is entered it makes the player aware and allows them to retry.
    }

    return(0);
}

int sowing(int menuSelection) {
    string confirmTask; //Variable for confirming menu selection.
    int cropSelection; //Variable for selecting crop to be sown.

    cout << "[1] Wheat" << endl << "[2] Barley" << endl << "[3] OSR" << endl << "[4] Oats" << endl <<
        "[5] Fieldbeans" << endl << "[6] Potatoes" << endl << "[7] Sugar Beets" << endl << "Please select which crop you wish to be planted: "; //Outputs the different crop options and allows the player to choose one.
    cin >> cropSelection;
    cout << endl; // Saves the players crop selection for planting.
    cout << "It will cost " << round(field[menuSelection - 1][0] * fuelPrice) << " pounds in fuel, cost " << round(field[menuSelection - 1][0] * seedPrice) << " pounds in seed"
        << " and take " << round(field[menuSelection - 1][0] / 4) << " hours." << endl << "Do you wish to carry out this task (Y or N): "; //Output message informing the player of the costs associated with this task.
    cin >> confirmTask;
    cout << endl; //Saves the players decision.
    
    if (confirmTask == "y" or confirmTask == "Y") { //If selected yes carries out the folllowing:
        if ((money > (field[menuSelection - 1][0] * fuelPrice) + (field[menuSelection - 1][0] * seedPrice)) && time < 24 - (field[menuSelection - 1][0] / 4)) { //Checks that the player has enough money and time left in the day.
            if ((cropSelection == 1) & ((day > 6) && (day <= 12))) { //Checks that it is the right time of year for planting this crop.
                field[menuSelection - 1][3] = cropSelection; //Changes the state of the field in repect to the planted crop.
                money = money - (field[menuSelection - 1][0] * fuelPrice) - (field[menuSelection - 1][0] * seedPrice); //Deducts the money required for the work.
                time = time + field[menuSelection - 1][0] / 4; //Increases the time by the time the task took.
                field[menuSelection - 1][5] = 14; //Changes the growth timer to the number of in-game days left + 1.
                gamePlay(); //Goes back to the main gameplay menu.
            }
            else if ((cropSelection == 2) && ((day > 6) && (day <= 15))) { //Same as previous crop just different numbers for differences between crops.
                field[menuSelection - 1][3] = cropSelection;
                money = money - (field[menuSelection - 1][0] * fuelPrice) - (field[menuSelection - 1][0] * seedPrice);
                time = time + field[menuSelection - 1][0] / 4;
                field[menuSelection - 1][5] = 14;
                gamePlay();
            }
            else if ((cropSelection == 3) && ((day > 3) && (day <= 12))) { //Same as previous crop just different numbers for differences between crops.
                field[menuSelection - 1][3] = cropSelection;
                money = money - (field[menuSelection - 1][0] * fuelPrice) - (field[menuSelection - 1][0] * seedPrice);
                time = time + field[menuSelection - 1][0] / 4;
                field[menuSelection - 1][5] = 16;
                gamePlay();
            }
            else if ((cropSelection == 4) && ((day > 4) && (day <= 12))) { //Same as previous crop just different numbers for differences between crops.
                field[menuSelection - 1][3] = cropSelection;
                money = money - (field[menuSelection - 1][0] * fuelPrice) - (field[menuSelection - 1][0] * seedPrice);
                time = time + field[menuSelection - 1][0] / 4;
                field[menuSelection - 1][5] = 10;
                gamePlay();
            }
            else if ((cropSelection == 5) && ((day > 4) && (day <= 12))) { //Same as previous crop just different numbers for differences between crops.
                field[menuSelection - 1][3] = cropSelection;
                money = money - (field[menuSelection - 1][0] * fuelPrice) - (field[menuSelection - 1][0] * seedPrice);
                time = time + field[menuSelection - 1][0] / 4;
                field[menuSelection - 1][5] = 12;
                gamePlay();
            }
            else if ((cropSelection == 6) && ((day > 9) && (day <= 15))) { //Same as previous crop just different numbers for differences between crops.
                field[menuSelection - 1][3] = cropSelection;
                money = money - (field[menuSelection - 1][0] * fuelPrice) - (field[menuSelection - 1][0] * seedPrice);
                time = time + field[menuSelection - 1][0] / 4;
                field[menuSelection - 1][5] = 15;
                gamePlay();
            }
            else if ((cropSelection == 7) && ((day > 7) && (day <= 13))) { //Same as previous crop just different numbers for differences between crops.
                field[menuSelection - 1][3] = cropSelection;
                money = money - (field[menuSelection - 1][0] * fuelPrice) - (field[menuSelection - 1][0] * seedPrice);
                time = time + field[menuSelection - 1][0] / 4;
                field[menuSelection - 1][5] = 22;
                gamePlay();
            }
            else {
                cout << "It appears you are in the wrong season to plant this crop." << endl;
                gamePlay();
                //If the season is incorrect it outputs a message to the player informing them and takes them back to the gameplay menu.
            }
        }
        else {
            cout << "Sorry, it appears you do not have enough money or time left in the day for this action." << endl << endl;
            gamePlay();
            //If the player doesn't have enough money or time it makes them aware and goes back to the gameplay menu with no action being carried out.
        }
    }
    else if (confirmTask == "N" or confirmTask == "n") {
        gamePlay();
        //If the player determins they don't wish to carry the task out they are taken back to the gameplay menu with no action being taken.
    }
    else {
        cout << "Sorry, that is an invalid input, try again..." << endl;
        fieldworkMenu();
        //If any other input is entered it makes the player aware and allows them to retry.
    }

    return(0);
}

int cultivating(int menuSelection) {
    string confirmTask;

    cout << "It will cost " << round(field[menuSelection - 1][0] * fuelPrice * 2) << " pounds in fuel and take " << round(field[menuSelection - 1][0] / 4) << " hours." << endl <<
        "Do you wish to carry out this task (Y or N): "; //Output message informing the player of the costs associated with this task, it uses a 2x multiplier for fuel costs as ground work is power heavy.
    cin >> confirmTask;
    cout << endl; //Saves the players decision.
    
    if (confirmTask == "y" or confirmTask == "Y") { //If selected yes carries out the folllowing:
        if ((money > (field[menuSelection - 1][0] * fuelPrice) * 2) && time < 24 - (field[menuSelection - 1][0] / 4)) { //Checks that the player has enough money and time left in the day.
            field[menuSelection - 1][2] = 1; //Changes the current state of the field.
            money = money - ((field[menuSelection - 1][0] * fuelPrice) * 2); //Deducts the money required for the work.
            time = time + field[menuSelection - 1][0] / 4; //Increases the time by the time the task took.
            gamePlay(); //Goes back to the main gameplay menu.
        }
        else {
            cout << "Sorry, it appears you do not have enough money or time left in the day for this action." << endl << endl;
            gamePlay();
            //If the player doesn't have enough money or time it makes them aware and goes back to the gameplay menu with no action being carried out.
        }
    }
    else if (confirmTask == "N" or confirmTask == "n") {
        gamePlay();
        //If the player determins they don't wish to carry the task out they are taken back to the gameplay menu with no action being taken.
    }
    else {
        cout << "Sorry, that is an invalid input, try again..." << endl;
        fieldworkMenu();
        //If any other input is entered it makes the player aware and allows them to retry.
    }

    return(0);
}

int ploughing(int menuSelection) {
    string confirmTask; //Variable for confirming if a task is to be carried out.

    cout << "It will cost " << round(field[menuSelection - 1][0] * fuelPrice * 2) << " pounds in fuel and take " << round(field[menuSelection - 1][0] / 4) << " hours." << endl <<
        "Do you wish to carry out this task (Y or N): "; //Output message informing the player of the costs associated with this task, it uses a 2x multiplier for fuel costs as ground work is power heavy.
    cin >> confirmTask;
    cout << endl; //Saves the players decision.
   
    if (confirmTask == "y" or confirmTask == "Y") { //If selected yes carries out the folllowing:
        if ((money > (field[menuSelection - 1][0] * fuelPrice) * 2) && time < 24 - (field[menuSelection - 1][0] / 4)) { //Checks that the player has enough money and time left in the day.
            field[menuSelection - 1][1] = 1; //Changes the current state of the field.
            money = money - ((field[menuSelection - 1][0] * fuelPrice) * 2); //Deducts the money required for the work.
            time = time + field[menuSelection - 1][0] / 4; //Increases the time by the time the task took.
            gamePlay(); //Goes back to the main gameplay menu.
        }
        else {
            cout << "Sorry, it appears you do not have enough money or time left in the day for this action." << endl << endl;
            gamePlay();
            //If the player doesn't have enough money or time it makes them aware and goes back to the gameplay menu with no action being carried out.
        }
    }
    else if (confirmTask == "N" or confirmTask == "n") {
        gamePlay();
        //If the player determins they don't wish to carry the task out they are taken back to the gameplay menu with no action being taken.
    }
    else {
        cout << "Sorry, that is an invalid input, try again..." << endl;
        fieldworkMenu();
        //If any other input is entered it makes the player aware and allows them to retry.
    }

    return(0);
}

int fieldworkMenu()
{
    string crop; //Variable to store the crop planted.
    int menuSelection; //Variable to store the option selected, passed through to each fieldwork function.

    cout << "Fields to work on:" << endl;
    for (int i = 0; i <= 29; i++) {
        if (field[i][7] == 1) { //Checks through the multidimensional array to see which fields are owned.
            if (field[i][3] == 1) { //Checks to see if there is anything planted in the field.
                crop = "Wheat"; //Saves the name of the corresponding crop to a variable for output.
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

            cout << "[" << i + 1 << "]   " << "Crop: " << crop << "   "; //Start of the field data being dispalyed the player.

            if (field[i][1] == 1) { //Series of embedded if statements to check what the next stage of work required for a field is.
                if (field[i][2] == 1) {
                    if (field[i][3] != 0) {
                        if (field[i][4] != 0) {
                            if (field[i][5] == 1) {
                                cout << "Needs Harvesting." << endl; //Lets the player know a field needs harvesting.
                            }
                            else if (field[i][5] > 1) {
                                cout << "Growing... " << field[i][5] - 1 << " Days Left." << endl; //Tells the player how long is left before harvest.
                            }
                            else {
                                if (field[i][6] == 1) {
                                    cout << "Straw Needs Collecting." << endl; //Lets the player know straw needs collecting.
                                }
                            }
                        }
                        else {
                            cout << "Growing... " << field[i][5] - 1 << " Days Left." << "    Needs Fertilising." << endl; //Tells the player how long is left before harvest and if it needs fertilising.
                        }
                    }
                    else {
                        cout << "Needs Sowing." << endl; //Lets the player know a field needs sowing.
                    }
                }
                else {
                    cout << "Needs Cultivating." << endl; //Lets the player know a field needs cultivating.
                }
            }
            else {
                cout << "Needs Ploughing." << endl; //Lets the player know a field needs ploughing.
            }
        }
    }

    cout << "Please select the number field you would like to do the next stage of work on [x]: ";
    cin >> menuSelection;
    cout << endl;
    //Allows the user to choose which action for which field they would like to carry out.

    if (field[menuSelection - 1][7] == 1) { //Checks to make sure the field the player wishes to work on is owned by them.
        if (field[menuSelection - 1][1] == 0) {
            ploughing(menuSelection); //Goes to the ploughing function of a field.
        }
        else if (field[menuSelection - 1][2] == 0) {
            cultivating(menuSelection); //Goes to the cultivating function of a field.
        }
        else if (field[menuSelection - 1][3] == 0) {
            sowing(menuSelection); //Goes to the sowing function of a field.
        }
        else if (field[menuSelection - 1][4] == 0) {
            fertilising(menuSelection); //Goes to the fertilising function of a field.
        }
        else if (field[menuSelection - 1][5] > 1) {
            cout << "It apears this field is not ready to be harvested yet." << endl << endl;
            gamePlay(); //Checks if the field is ready to be harvested yet and if not maks the player aware of this.
        }
        else if (field[menuSelection - 1][5] == 1) {
            harvesting(menuSelection); //Goes to the harvesting function of a field.
        }
        else if (field[menuSelection - 1][6] == 1) {
            strawHarvest(menuSelection); //Goes to the straw collection function of a field.
        }
    }
    else {
        cout << "Sorry, it appears you do not own this field yet..." << endl << endl;
        gamePlay();
        //If the player doesnt own the field it lets them know and returns them to the main gameplay menu.
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

    cout << farmName << "'s Farm         Money: " << round(money) << "         " << round(time) << ":00  Day: " << day << "   Year: " << year << endl << endl << "Fields:" << endl;
    //Output showing the current stats of the game: Money, time and date.

    for (int i = 0; i <= 29; i++) {
        if (field[i][7] == 1) { //Checks through the multidimensional array to see which fields are owned.
            if (field[i][3] == 1) { //Checks to see if there is anything planted in the field.
                crop = "Wheat"; //Saves the name of the corresponding crop to a variable for output.
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

            cout << "[" << i + 1 << "]   " << "Crop: " << crop << "   "; //Start of the field data being dispalyed the player.

            if (field[i][1] == 1) { //Series of embedded if statements to check what the next stage of work required for a field is.
                if (field[i][2] == 1) {
                    if (field[i][3] != 0) {
                        if (field[i][4] != 0) {
                            if (field[i][5] == 1) {
                                cout << "Needs Harvesting." << endl; //Lets the player know a field needs harvesting.
                            }
                            else if (field[i][5] > 1) {
                                cout << "Growing... " << field[i][5] - 1 << " Days Left." << endl; //Tells the player how long is left before harvest.
                            }
                            else {
                                if (field[i][6] == 1) {
                                    cout << "Straw Needs Collecting" << endl; //Lets the player know straw needs collecting.
                                }
                            }
                        }
                        else {
                            cout << "Growing... " << field[i][5] - 1 << " Days Left." << "    Needs Fertilising." << endl; //Tells the player how long is left before harvest and if it needs fertilising.
                        }
                    }
                    else {
                        cout << "Needs Sowing." << endl; //Lets the player know a field needs sowing.
                    }
                }
                else {
                    cout << "Needs Cultivating." << endl; //Lets the player know a field needs cultivating.
                }
            }
            else {
                cout << "Needs Ploughing." << endl; //Lets the player know a field needs ploughing.
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

            for (int i = 0; i <= 29; i++) {
                if (field[i][3] != 0) {
                    field[i][1] = 0;
                    field[i][2] = 0;
                    field[i][3] = 0;
                    field[i][4] = 0;
                    field[i][5] = 0;
                    field[i][6] = 0;

                }
            } //Uses a for loop at the end of each year to check if there are still crops in the field and if so for them to die over winter and reset the field back to original state.

            weatherMultiplier = 1;
            wheatPestMultiplier = 1;
            barleyPestMultiplier = 1;
            osrPestMultiplier = 1;
            oatsPestMultiplier = 1;
            fieldbeansPestMultiplier = 1;
            potatoesPestMultiplier = 1;
            beetsPestMultiplier = 1;
            //Resets any multipliers from random events that occured in the previous year.

            checkGameEnd(); //Check at the end of the year to see if the game is over.
        }
        else {
            day++; //Increases the day by 1.
        }

        for (int i = 0; i <= 29; i++) {
            if (field[i][5] > 1) {
                field[i][5] = field[i][5] - 1;
            }
        }
        //Uses a for loop to check which fields are planted and when the player sleeps lowers the time left to grow by a day.

        randomEvent(); //Goes to the procedure for determining if a random event should occur.

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

    cout << "Please enter your name: ";
    cin >> farmName;
    cout << endl;
    //Allows the user to enter a name for their new farm.

    money = 5000;
    year = 1;
    day = 1;
    time = 8;
    //Initialises the game by setting the initial money and and date/time.

    gamePlay(); //Goes to the main gameplay menu.

    return(0);
}

int start() //Start menu procedure.
{
    int gameStart; //Variable for menu options.

    cout << "[1] Start Game" << endl << "[2] Exit" << endl << "Please enter what you would like to do: ";
    cin >> gameStart;
    cout << endl << endl;
    //Simple option to allow the player to start or exit the game.

    if (gameStart == 1) {
        gameInitialization(); //Goes to the menu to start a game.
    }
    else if (gameStart == 2) {
        exit(1); //Exits the program.
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