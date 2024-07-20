#include<iostream>
#include<math.h>

using namespace std;

int arr[100];

/* calculating maximum number from the numbers present at one's position in the array elements then for 
ten's position and so on..*/
int get_max(int size, int k)
{
	int large = (arr[0]/k)%10;
	for (int i = 1; i <= size; i++)
	{
		if ((arr[i]/k)%10 > large)
		{
			large = (arr[i]/k)%10;
			break;
		}

	}
	return large;
}

void counting_sort(int size, int k, int m)
{
	/* array c for keeping count of indivual numbers and array b for storing sorted array*/
	int c[10] = { 0 }, b[10] = { 0 };
	
	/* extracting digits at one's place, ten's place and so on and applying counting sort for each case*/
	for (int j = 0; j < size; j++)
		c[(arr[j] / m) % 10]++;

	for (int i = 1; i <= k; i++)
		c[i] = c[i] + c[i - 1];

	for (int j = size-1; j >= 0; j--)
	{
		b[c[(arr[j] / m) % 10]-1] = arr[j];
		c[(arr[j] / m) % 10]--; 
	}

	/*updating array arr with sorted elements that are present in array b*/
	for (int i = 0; i < size; i++)
	{
		arr[i] = b[i];
	}
}

void radix_sort(int size, int d)
{
	int max;
	for (int m=1, i=d; i>0; m*=10, i--)
	{
		/* gets largest value from numbers present at array elements one's place, ten's place and 
		so on..*/
		max = get_max(size, m);
		counting_sort(size, max, m);	
	}
}

int main()
{
	int n, temp, d=0;
	cout << "Enter size of array: ";
	cin >> n;
	cout << "Enter array elements(constraint: number of digits should be same for all elements):-\n";
	for (int i =0; i < n; i++)
		cin >> arr[i];

	//counting number of digits in the array
	temp = arr[1];
	for (; temp > 0;temp/=10)
		d++;

	radix_sort(n, d);
	cout << "Sorted array:-\n";
	for (int j = 0; j < n; j++)
		cout << arr[j] << "\t";
	return 0;
}