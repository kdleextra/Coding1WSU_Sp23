#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::string;
using std::cout;
using std::cin;

class enemy {
private:
    string name;
    int health;
public:
    enemy(string givenName = "Bad Guy McGee");
    void status();

    void changeHealthBy(int amount);
    int getHealth();
    void setName(string newName);
    string getName();
};