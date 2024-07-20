#include<iostream>

using namespace std;

int arr[1000], counter=0;

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

void QuickSort(int p, int r)
{
	if (p < r)
	{
		int q = partition(p, r);
		QuickSort(p, q-1);
		QuickSort(q+1, r);
	}
}
int main()
{
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	cout << "Enter elemenets:-\n";
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	QuickSort(1, n);
	cout << "Sorted array:-\n";
	for (int i = 1; i <= n; i++)
		cout << arr[i] << "\t";
	cout << "\nNumber of comparisons:\t" << counter;
	return 0;
}