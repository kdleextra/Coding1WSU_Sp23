// Coding 1 - W14 HW Fav Games

/*-------------------IMPORTANT------------------
I used Bard from Google to write some of the code/functions, but modified them a
bit
-----------------------------------------*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Necessary Variables
string favGames[100];
int index = 0;

// Function to output main menu options
//  and return choice of use (in string)
void mainMenu() {
  cout << "\n------------------\nWhat would you like to do?\n";
  cout << "- Type 'add' to add a game.\n";
  cout << "- Type 'remove' to remove a game.\n";
  cout << "- Type 'bulkadd' to add multiple games.\n";
  cout << "- Type 'show' to show your favorite game.\n";
  cout << "- Type 'clear' to clear save file.\n";
  cout << "- To edit one of the entries, try these: \n\t'edit', "
          "'editlast','find'\n";
  cout << "There are " << index << " game in the list.\n";
  cout << "- Type 'quit' to quit the program.\n>>";
}

// Function to load from the file to the fav games array
//  also increase index value while loading
void load(string filename, string array[]) {
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "Error opening file." << endl;
    return;
  }

  cout << "Reading from save.......\n";
  // read until the end of the file
  while (!file.eof()) {
    string line;
    getline(file, line);
    // if the line is empty, skip (in case the save is new/empty)
    if (!line.empty()) {
      array[index] = line;
      index++;
    }
  }

  file.close();
}

// Function to save game array to file
void save(string filename, string array[]) {
  ofstream file(filename);
  if (!file.is_open()) {
    cout << "Error opening file." << endl;
    return;
  }

  cout << "\n\nSaving...Done! \n";

  for (int i = 0; i < index - 1; i++) {
    file << array[i] << endl;
  }
  // Prevent empty line at the end of the save file
  if (index > 0) {
    file << array[index - 1];
  }
  file.close();
}

// Function to clear the save file
void clear() {
  string input;
  cout << "Are you sure? Clearing save file cannot be undone! (Y/N)\n>>";
  cin >> input;
  if (input == "Y" || input == "y") {
    index = 0;
    save("games.txt", favGames);
    load("games.txt", favGames);
  } else {
    cout << "Cancelled! Going back to main menu...\n";
  }
}

// Function to output the list of game
void show() {
  cout << endl;
  for (int i = 0; i < index; i++) {
    cout << i + 1 << ". " << favGames[i] << endl;
  }
}

// Function to add a game to the array
void add() {
  string input;
  cout << "What game to add?\n>>";
  cin >> input;
  favGames[index] = input;
  index++;
}

// Function to remove a game
void remove() {
  show();
  string input;
  cout << "What game do you wanna remove?\n>>";
  cin >> input;
  // loop and compare all entries to input,
  // stop loop if found the right one & remove it
  for (int i = 0; i < index; i++) {
    if (input == favGames[i]) {
      cout << "Found it! Game removed from the list!\n";
      // shift the rest of the value 'up' in the array, decrease Index value
      for (int j = i; j < index - 1; j++) {
        favGames[j] = favGames[j + 1];
      }
      index--;
      break;
    }

    if (i + 1 == index) {
      cout << "Specific game not found. Sorry!\n";
    }
  }
}

// Function to bulk add game to the array
void bulkAdd() {
  string input;
  cout << "Enter the games you wanna add, type 'quit' to stop adding.\n>>";
  // while loop, checking if input is 'quit' --> stop adding, else keep adding
  // entries
  while (true) {
    cin >> input;
    if (input == "quit") {
      break;
    } else {
      favGames[index] = input;
      index++;
      cout << ">>";
    }
  } // end of while loop
}

// Function to ask player an entry to edit
void edit() {
  string input;
  cout << endl;
  for (int i = 0; i < index; i++) {
    cout << i + 1 << ". " << favGames[i] << endl;
  } // end of for loop
  int numInput;
  cout << "Which game (number) would you like to change?\n>>";
  cin >> numInput;
  cout << "What is the new name for " << favGames[numInput - 1] << "?\n>>";
  cin >> input;
  favGames[numInput - 1] = input;
}

// Function to ask for the name of the game to edit, then edit it
void findEdit() {
  string input;
  cout << "What game do you wanna find?\n>>";
  cin >> input;
  // loop and compare all entries to input,
  // stop loop if found the right one & edit that name
  for (int i = 0; i < index; i++) {
    if (input == favGames[i]) {
      cout << "Found it! What is the new name for " << favGames[i] << "?\n>>";
      cin >> input;
      favGames[i] = input;
      break;
    }

    if (i + 1 == index) {
      cout << "Specific game not found. Sorry!\n";
    }
  }
}

// Function to edit the last entry
void editLast() {
  string input;
  cout << "What is the new name for " << favGames[index - 1] << "?\n>>";
  cin >> input;
  favGames[index - 1] = input;
}

// Function to ask which task to do from the main menu,
// then do that ONE specific task
// return false if the program is 'quit' by player
bool doTheTask() {
  mainMenu();
  string input;
  cin >> input;
  if (input == "quit")
    return false;
  else if (input == "show")
    show();
  else if (input == "remove")
    remove();
  else if (input == "clear")
    clear();
  else if (input == "add")
    add();
  else if (input == "bulkadd")
    bulkAdd();
  else if (input == "edit")
    edit();
  else if (input == "editlast")
    editLast();
  else if (input == "find")
    findEdit();
  else
    cout << "Command not regconized. Try again!\n";

  return true;
}

// Main Program
int main() {
  // bool variable to break the while loop of the main program
  bool isContinue = true;

  // load save file to game array, and get the correct global index
  load("games.txt", favGames);

  // looping main menu until 'quit'
  while (isContinue) {
    isContinue = doTheTask();
  }

  // save game array to file after exit the loop and end the program
  save("games.txt", favGames);
  cout << "Bye Bye!\n\n";
}