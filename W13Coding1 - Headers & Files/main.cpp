#include "enemy.h"

int main() {
    enemy duke;
    duke.status();
    duke.changeHealthBy(-4);
    cout << "Duke got hit my -4 hp.\n";
    cout << "Duke current health is " << duke.getHealth() << ".\n";

    cout << "What would you like to name duke?\n>> ";
    string input;
    cin >> input;

    duke.setName(input);
    cout << "Duke is now named " << duke.getName() << ".\n";
    duke.status();
}