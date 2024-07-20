//Implement Randomized Quick sort (The program should report the number of comparisons)

#include<iostream>
#include<stdlib.h>

using namespace std;

int counter = 0, arr[1001];
void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
int partition(int p, int r)
{
	int pivot = arr[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		counter++;
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}
int randomizedPartition(int p, int r)
{
	int temp = p + rand() % (r - p);
	swap(arr[r], arr[temp]);
	return partition(p, r);
}

void randomizedQuickSort(int p, int r)
{
	if (p < r)
	{
		int q = randomizedPartition(p, r);
		randomizedQuickSort(p, q - 1);
		randomizedQuickSort(q + 1, r);
	}
}

int main()
{
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	cout << "Enter elements:-";
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	randomizedQuickSort(1, n);

	cout << "Sorted array:\t";
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\nNumber of comparisons:\t" << counter;
	return 0;
}