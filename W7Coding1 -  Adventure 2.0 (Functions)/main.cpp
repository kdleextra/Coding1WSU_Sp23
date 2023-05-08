//Khoi Le
//Coding 1

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

//global variables
int health = 15;
int totalTreasure = 0;
int dieSize = 24;

//function to tell a story at the beginning of the game
// return void
void Story() {
    cout << "Yo! Howdy, stranger! The weather is nice today!\n";
}

//function add a Yes/No 'question' as input parameter
// return TRUE if answer is y or Y, everything else inputted will return false!
bool AskYesNo(string question) {
    char input;
    cout << question << " [y/n]: ";
    cin >> input;
    return (input == 'y' || input == 'Y');
}

//function to roll a dice with param int 'sides = 6'
// return int
int RollDie(int sides = 6) {
    return rand() % sides + 1;
}

//function to tell how the adv end
// return void
void Ending() {
    if (health > 0) {
        cout << "Yo! Congrat! You survive with " << health << " healths and " << totalTreasure << " coins!\n";
    }
    else {
        cout << "You died! Better luck next time mate!\n";
    }
}

//fucntion to print our player stats
// return void
void ShowStats() {
    if (health > 0) cout << "Yo! You have " << health << " healths and " << totalTreasure << " coins!\n";
    else cout << "OOF! THAT GOTTA HURT! YOU LOST ALL THE COINS!\n";
}

//function to keep track of each encounter
// return bool = false if player is dead or doesnt wanna continue
bool Adventure() {
    //variable of an encounter
    int enemyAttack, playerBlock, treasure;

    //check if player wanna start an adventure
    bool isContinue;
    isContinue = AskYesNo("Wanna go on an adventure?");    
    if (!isContinue) return false; //this will stop the while loop in main()

    //initialize all variable of an encounter
    cout << "Weeeee! Let's go!\n";
    enemyAttack = RollDie(dieSize) + RollDie(dieSize);
    playerBlock = RollDie(dieSize) + RollDie(dieSize) + RollDie(dieSize);
    treasure = RollDie(dieSize);

    //check if player got hit and get any sh*t
    if (playerBlock >= enemyAttack) {
        cout << "Blocked successfully! They dropped some coins dude!\n";
        totalTreasure += treasure;
    }
    else {
        health -= enemyAttack - playerBlock;
        cout << "You got hit and found no sh*t! Lol\n";
    }

    //show current stat after an encounter
    ShowStats();
    //new line for readability 
    cout << "-------\n";

    if (health <= 0) return false; //this will stop the while loop in main()
    else return true; //this is continue a new loop in main()       
} //end of Adventure()


// main program
int main() {
    //seed random with time(0)
    srand(time(0));
    //variable check if player is alive
    bool isAlive = true;

    //start of adventure
    Story();
    ShowStats();
    //as long as player is alive, keep looping the Adventure function
    while(isAlive) {
        isAlive = Adventure();
    }
    //show how it ended, depending on player health left
    Ending();
}