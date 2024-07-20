#include<iostream>
#include<algorithm>

using namespace std;

class item {
public:
	int value, weight;
}*items;


int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int n, int weight_knapsack) {
	if (n == 0 || weight_knapsack == 0)
		return 0;

	if (items[n - 1].weight > weight_knapsack)
		return knapsack(n - 1, weight_knapsack);
	else
		return max(items[n - 1].value + knapsack(n - 1, weight_knapsack - items[n - 1].weight), knapsack(n - 1, weight_knapsack));
}

void display() {
	for (int i = 0; i < 40; i++)
		cout << "=";
	cout << endl;
}
int main() {
	int n, weight_knapsack;

	display();
	cout << "\tKNAPSACK PROBLEM\n";
	display();
	cout << "Enter the number of items: ";
	cin >> n;
	items = new item[n + 1];

	for (int i = 0; i < n; i++) {
		cout << "\nFor item " << i << ":-\n";
		cout << "Value : ";
		cin >> items[i].value;
		cout << "Weight : ";
		cin >> items[i].weight;
	}

	cout << "\nEnter weight of knapsack: ";
	cin >> weight_knapsack;

	cout<<"\n\nValue in knapsack: "<<knapsack(n, weight_knapsack);
	return 0;
}