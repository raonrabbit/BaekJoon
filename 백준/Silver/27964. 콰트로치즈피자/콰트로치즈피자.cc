#include<iostream>
#include<set>

using namespace std;

int main() {
	int toppingCount;
	set<string> toppings;
	string topping;
	cin >> toppingCount;

	for (int i = 0; i < toppingCount; i++) {
		cin >> topping;
		if (topping.size() < 6) {
			continue;
		}
		if (topping.substr(topping.size() - 6) != "Cheese") {
			continue;
		}
		toppings.insert(topping);
	}

	if (toppings.size() < 4) cout << "sad";
	else cout << "yummy";
}