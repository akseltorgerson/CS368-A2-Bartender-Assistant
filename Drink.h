#include <string>

#ifndef DRINK_HEADER
#define DRINK_HEADER

enum STYLE {NEAT, ROCKS, DOUBLE, TALL};

struct Drink {
		string name;
		float basePrice;
		STYLE style;
		private:
			string getStyle();
		public:
			Drink(string _name, float _price, STYLE _style = NEAT);
			Drink(const Drink& copy_from);
			void Prepare(const STYLE serving_style);
			float TotalPrice();
			void Print();
};

#endif

