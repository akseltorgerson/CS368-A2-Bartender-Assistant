// Aksel Torgerson
// atorgerson

#include "Customer.h"

using namespace std;

Customer::Customer() {
	drinkCount = 0;
}
void Customer::Serve(const Drink& drink, const STYLE style) {
	if (drinkCount < DRINK_LIMIT) {
		Drink copyDrink = Drink(drink);
		copyDrink.Prepare(style);
		drinkList[drinkCount] = copyDrink;
		drinkCount++;
	} 
	return;
}
float Customer::TotalTab(const float tip) {
	float runningTotal = 0.0;
	for (int i = 0; i < drinkCount; i++) {
		runningTotal += drinkList[i].TotalPrice();
	}
	runningTotal += (runningTotal * TAX) + (runningTotal * tip);
	return runningTotal;
}
void Customer::Print(const float tip) {
	for (int i = 0; i < drinkCount; i++) {
		drinkList[i].Print();
	}
	std::cout << "***" << endl;
	std::cout << "Tax: " << TAX * 100 << "%" << endl;
	std::cout << "Tip: " << tip * 100 << "%" << endl;
	std::cout << "Total: $" << TotalTab(tip) << endl;
}