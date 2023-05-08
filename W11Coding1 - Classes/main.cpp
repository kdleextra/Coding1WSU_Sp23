//Khoi Le
//Coding 1
//Homework - Classes

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

//Global Variable
string carNames[] = {"Alpha", "Bravo", "Casey", "Delta", "Ego"};


//class for car
class car {
    //data member 
    string brand;
    int miles;
//constructor and member functions
public:
    //constructor when no specifications, randomize name with miles
    car () {
        cout << "A new car has been created!\n";
        miles = rand()%30 + 1990;
        brand = "generic car " + to_string(miles);
    }

    //constructor with specific member value
    car(string brandName, int mileage) {
        cout << "A new car has been created!\n";
        brand = brandName;
        miles = mileage;
    }
    //member function to show car data member value
    void status() {
        cout << "[" << brand << " - " << miles << " miles]\n";
    }

    //member function to increase mileage of the car
    void increaseMiles(int length) {
        miles += length;
        cout << brand << " ran for " << length << " miles.\n";
    }
};

int main() {
    //seed the random function with time(0)
    srand(time(0));

    //initialize all 10 cars
    car cars[10];
    for (int i = 0; i <10; i++) {
        cars[i] = car(carNames[rand()%5], rand()%1000);
    }
    cout << endl;

    //show status of 10 cars
    for (int i = 0; i <10; i++) {
        cars[i].status();
    }
    cout << endl;

    //add mileage to each car with a random number from 0 to 999
    for (int i = 0; i <10; i++) {
        cars[i].increaseMiles(rand()%1000);
    }
    cout << endl;

    //show status of 10 cars again
    for (int i = 0; i <10; i++) {
        cars[i].status();
    }
    
}