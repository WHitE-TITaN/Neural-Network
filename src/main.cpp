#include "../headers/transformer.h"

int main() {
	transformer sol;
	string hello = sol.sayHello();

	for (auto character : hello) {
		cout << character;
	}
}