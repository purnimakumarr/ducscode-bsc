// HeapSort.cpp : Objective : Implement heap sort and print number of comparisons.

#include <iostream>

using namespace std;

int arr[1000];

int left(int num)
{
    return 2 * num;
}

int right(int num)
{
    return 2 * num + 1;
}

int max_heapify(int s, int i, int count)
{
    int l = left(i), r = right(i), largest = i;
    if (l <= s && arr[l] > arr[i])
        largest = l;
    if(l<=s)
        count++;
    
    if (r <= s && arr[r] > arr[largest])
        largest = r;
    if(r<=s)
        count++;
    

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        count=max_heapify(s, largest, count);
    }
    return count;
}

int build_heap(int s, int count)
{
    for (int i = s / 2; i >= 1; i--)
    {
       count=max_heapify(s, i, count);
    }
    return count;
}

int  heap_sort(int s)
{
    int count = 0;
    count=build_heap(s, count);
    for (int i = s; i >= 2; i--)
    {
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        s = s - 1;
        count=max_heapify(s, 1, count);
    }
    return count;
}

int main()
{
    int s;
    cout << "Enter size of array: ";
    cin >> s; //length of array
    cout << "Enter an array: ";
    for (int i = 1; i <= s; i++)
        cin>>arr[i];

    int count=heap_sort(s);

    cout << "Sorted array:\n";
    for (int i = 1; i <= s; i++)
        cout << arr[i] << "\t";

    cout << "\nTotal number of comparisons: " << count;
    
}

