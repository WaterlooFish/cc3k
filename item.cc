#include "item.h"
using namespace std;

string Item::getValue() {
  return value;
}

int Item::getX() {
  return x;
}

int Item::getY() {
  return y;
}

string Item::hasSeen = "";

Item::Item() : x(0), y(0) {}

Item::Item(string value, int x, int y) : value(value), x(x), y(y) {}

Item& Item::operator=(const Item &o) {
	if (this == &o) return *this;
	value = o.value;
	x = o.x;
	y = o.y;
	return *this;
}

Item::~Item() {}
