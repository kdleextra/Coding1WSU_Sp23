#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  // set up the game parameters and seed the random number
  srand(time(0));
  int health = 10;
  int attack = 0;
  int block = 0;
  int turns = 0;

  cout << "Welcome to the ADVANTURE!!! \n\n\n";

  // start the loop
  while (health > 0 && turns < 4) {
    // increase encounter number
    turns += 1;
    // output turn number
    cout << "Turn " << turns << ":\n";
    attack = rand() % 5;
    block = rand() % 5;
    // test the block vs. attack then show the turn result
    if (block >= attack) {
      cout << "Blocked successfully!\n\n";
    } else {
      health = health - attack;
      cout << "You got hit with " << attack << " damage!\n\n";
    }
  }
  // check if player won the game
  if (health > 0) {
    cout << "Congratulation! You survived!\n";
  } else {
    cout << "You died! Good luck next time!\n";
  }
}