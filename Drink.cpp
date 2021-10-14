#include "Drink.h"

struct Drink {
		string name;
		float basePrice;
		STYLE style;
		public:
			Drink(string _name, float _price, STYLE _style = NEAT) {
				name = _name;
				basePrice = _price;
				style = _style;
			}
			Drink(const Drink& copy_from) {
				name = copy_from.name;
				basePrice = copy_from.price;
				style = copy_from.style;
			}
			void Prepare(const STYLE serving_style) {
				style = serving_style;
			}
			float TotalPrice() {
				switch (style) {
					case NEAT:
						return basePrice;
					case ROCKS:
						return basePrice + 0.25;
					case DOUBLE:
						return basePrice * 2.0;
					case TALL:
						return basePrice + 1.00;
				}
			}
			void Print() {
				cout << name << " (" << style << "): $";
				cout << std::fixed;
				cout << std::setprecision(2);
				cout << TotalPrice() << endl;
			}
};