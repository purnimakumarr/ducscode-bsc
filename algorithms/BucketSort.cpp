#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display(float* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
void design() {
    for (int i = 0; i < 5; i++)
        cout << "\t";
    for (int i = 0; i < 42; i++)
        cout << "=";
    cout << endl;
}
/* sorting indivual buckets using insertion sort */
void insertionSort(vector<float>& vec) {
    for (auto it = vec.begin(); it != vec.end(); it++) {
        auto const insertion_point = upper_bound(vec.begin(), it, *it);
        rotate(insertion_point, it, it + 1);
    }
}
/* sorting elements using bucket sort */
void bucketSort(float* array, int size) {
    int index = 0;

    /* creating buckets of vector type */
    vector<float> bucket[10];

    /* put elements into different buckets */
    for (int i = 0; i < size; i++) {
        bucket[int(size * array[i])].push_back(array[i]);
    }

    /* sort indivual buckets */
    for (int i = 0; i < size; i++) {
        insertionSort(bucket[i]);
    }

    /* concatenating all the sorted bucket elements into the resultant array*/
    for (int i = 0; i < size; i++) {
        while (!bucket[i].empty()) {
            array[index++] = *(bucket[i].begin());
            bucket[i].erase(bucket[i].begin());
        }
    }
}
int main() {
    design();
    cout << "\t\t\t\t\t\tBUCKET SORT IMPLEMENTATION\n";
    design();
    int n;  float arr[10];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\n\nElements before Sorting: ";
    display(arr, n);

    bucketSort(arr, n);

    cout << "\n\nElements after Sorting: ";
    display(arr, n);
}