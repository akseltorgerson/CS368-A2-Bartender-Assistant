// Aksel Torgerson
// atorgerson

#include <string>
#include "Drink.h"

#ifndef CUSTOMER_HEADER
#define CUSTOMER_HEADER

using namespace std;

#define DRINK_LIMIT 10
#define TAX 0.05

class Customer {
	private:
		Drink drinkList[DRINK_LIMIT];
		int drinkCount;
	public:
		Customer();
		void Serve(const Drink& drink, const STYLE style);
		float TotalTab(const float tip);
		void Print(const float tip);
};

#endif