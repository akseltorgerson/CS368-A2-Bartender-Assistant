#include "Customer.h"

#define DRINK_LIMIT = 10
#define TAX = 0.05

class Customer {
	private:
		Drink drinkList[10];
		int drinkCount;
	public:
		Customer() {
			drinkCount = 0;
		}
		void Serve(const Drink& drink, const STYLE style) {
			if (drinkCount < DRINK_LIMIT) {
				drinkList[drinkCount] = Drink(drink);
				drinkList[drinkCount].Prepare(style);
				drinkCount++;
			} 
			return;
		}
		float TotalTab(const float tip) {
			float runningTotal = 0.0;
			for (int i = 0; i < drinkCount; i++) {
				runningTotal += drinkList[i].TotalPrice();
			}
			runningTotal += (runningTotal * TAX) + (runningTotal * tip);
			return runningTotal;
		}
		void Print(const float tip) {
			for (int i = 0; i < drinkCount; i++) {
				drinkList[drinkCount].Print();
			}
			cout << *** << endl;
			cout << "Tax: " << TAX * 100 << "%" << endl;
			cout << "Tip: " << tip * 100 << "%" << endl;
			cout << "Total: $" << TotalTab(tip) << endl;
		}
};
