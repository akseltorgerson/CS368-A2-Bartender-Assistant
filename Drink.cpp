// Aksel Torgerson
// atorgerson

#include "Drink.h"

Drink::Drink() {}

Drink::Drink(string _name, float _price, STYLE _style) {
	name = _name;
	basePrice = _price;
	style = _style;
}

Drink::Drink(const Drink& copy_from) {
	name = copy_from.name;
	basePrice = copy_from.basePrice;
	style = copy_from.style;
}

void Drink::Prepare(const STYLE serving_style) {
	style = serving_style;
}

string Drink::getStyle() {
	switch (style) {
		case NEAT:
			return "Neat";
		case ROCKS:
			return "On the Rocks";
		case DOUBLE:
			return "Double";
		case TALL:
			return "Tall";
		default:
			return "";
	}
}

float Drink::TotalPrice() {
	switch (style) {
		case NEAT:
			return basePrice;
			break;
		case ROCKS:
			return basePrice + 0.25;
			break;
		case DOUBLE:
			return basePrice * 2.0;
			break;
		case TALL:
			return basePrice + 1.00;
			break;
		default:
			return 0.0;
			break;
	}
}
void Drink::Print() {
	std::cout << name << " (" << getStyle() << "): $";
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	std::cout << TotalPrice() << endl;
}
