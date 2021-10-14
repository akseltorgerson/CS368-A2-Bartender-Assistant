// Aksel Torgerson
// atorgerson

#include <iostream>
#include "Customer.h"
#include "Drink.h"

using namespace std;

//
// Helper menu print functions.
//
void printMainMenu() {
  cout << "Welcome to the Downtown Dairy Bar!" << endl;
  cout << "[1] Order a Drink" << endl;
  cout << "[2] Pay Your Tab" << endl;
  cout << "[3] Exit Program" << endl;
  cout << "Please enter a menu item: ";
  return;
}

void printDrinkMenu() {
  cout << "What drink would you like?" << endl;
  cout << "[1] Whole Milk" << endl;
  cout << "[2] 2% Milk" << endl;
  cout << "[3] Heavy Cream" << endl;
  cout << "[4] Milkshake" << endl;
	cout << "[5] Malt" << endl;
	cout << "[6] Skim Milk" << endl;
	cout << "Return to main menu" << endl;
  cout << "Please enter a menu item: ";
  return;
}

void printStyleMenu() {
  cout << "How would you like it served?" << endl;
  cout << "[1] Neat" << endl;
  cout << "[2] On the Rocks" << endl;
  cout << "[3] Double" << endl;
  cout << "[4] Tall" << endl;
  cout << "Please enter a menu item: ";
  return;
}

//
// Gets a valid input.
//
float getInput() {
	float retVal;
	bool goodInput;
	do {
		goodInput = true;
		cin >> retVal;
		if (retVal <= 0 || cin.fail()) {
			goodInput = false;
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Please enter a number: ";
		} 
	} while (!goodInput);
	return retVal;
}

int main() {
	// Scope variables
	int userSel = 0;
	float userTip = 0.0;
	int menuState = 1;
	Customer cust = Customer();
	Drink drink = Drink();

	while (1) {

		userSel = 0;

		// Main menu
		if (menuState == 1) {
			printMainMenu();
			userSel = getInput();
			switch (userSel) {
				// Order a drink
				case 1:
					menuState = 2;
					break;
				// Pay your tab
				case 2:
					menuState = 4;
					break;
				// Exit
				case 3:
					return 0;
					break;
				default:
					cout << "Please enter a valid selection!" << endl;
					break;
			}
		}

		// Order a drink
		else if (menuState == 2) {
			printDrinkMenu();
			userSel = getInput();
			switch (userSel) {
				case 1:
					drink = Drink("Whole Milk", 2.5, NEAT);
					menuState = 3;
					break;
				case 2:
					drink = Drink("2% Milk", 2.0, NEAT);
					menuState = 3;
					break;
				case 3:
					drink = Drink("Heavy Cream", 3.5, NEAT);
					menuState = 3;
					break;
				case 4:
					drink = Drink("Milkshake", 5.0, NEAT);
					menuState = 3;
					break;
				case 5:
					drink = Drink("Malt", 6.0, NEAT);
					menuState = 3;
					break;
				case 6:
					drink = Drink("Skim Milk", 1.0, NEAT);
					menuState = 3;
					break;
				case 7:
					menuState = 1;
					break;
				default:
					cout << "Please enter a valid selection!" << endl;
					break;
			}
		}

		else if (menuState == 3) {
			printStyleMenu();
			userSel = getInput();
			switch (userSel) {
			case 1:
				cust.Serve(drink, NEAT);
				menuState = 1;
				break;
			case 2:
				cust.Serve(drink, ROCKS);
				menuState = 1;
				break;
			case 3:
				cust.Serve(drink, DOUBLE);
				menuState = 1;
				break;
			case 4:
				cust.Serve(drink, TALL);
				menuState = 1;
				break;
			default:
				cout << "Please enter a valid selection!" << endl;
				break;
			}
		}

		// Paying Tab
		else if (menuState == 4) {
			cout << "Please enter a tip: ";
			userTip = getInput();
			userTip /= 100;
			cust.Print(userTip);
			cout << "Enter any number to return to menu... ";
			cin >> userTip;
			menuState = 1;
			cust = Customer();
		}
	}
}