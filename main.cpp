//COMSC 210 | Lab 20| Toma Dimov

#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>

using namespace std;
const int SIZE = 3;
const int MIN = 10000, MAX = 99999;
/*
instructions:
in the third code block at line 67, amend this such that the default constructors are used to populate these objects
*/

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        legs = 3+rand()%2; //default constructor to randomly select 3 or 4 legs
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand()%(MAX-MIN+1))/(double)100; //randomly select prices down to the cent from between $100.00 to $999.99
    }
    Chair(int l, double priceArg[SIZE]) { //parameter constructor to have two parameters: no. of legs and an array of 3 doubles (prices)
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = priceArg[i];
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    srand(time(NULL)); //seed the rand values
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with default constructor
    Chair *livingChair = new Chair();
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    cout<<"Randomized via default constructor:\n";
    Chair *collection = new Chair[SIZE]; //calls the default constructor
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}