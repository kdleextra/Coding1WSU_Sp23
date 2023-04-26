#include "enemy.h"

// define the constructor
enemy::enemy(string givenName){
    name = givenName;
    health = 10;
    cout << name << " has appeared!\n";
}

void enemy::status(){
    cout << name << " has " << health << " health left.\n";
}

void enemy::changeHealthBy(int amount) {
    health += amount;

    if(health < 0) health = 0;
    if(health >10) health = 10;
}

int enemy::getHealth(){
    return health;
}

void enemy::setName(string newName) {
    name = newName;
}

string enemy::getName() {
    return name;
}