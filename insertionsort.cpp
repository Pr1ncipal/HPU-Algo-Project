//Time complexity: O(n^2) is worst case 
// Best Case: O(n) 
#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr, int& comparisons) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++; // Increment comparison counter
        }
        arr[j + 1] = x;
        
        // Print array after each pass
        cout << "Array after pass " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    int comparisons = 0;

    cout << "Original array is: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, comparisons);

    cout << "Sorted array is: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
