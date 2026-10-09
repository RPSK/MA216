
#include <bits/stdc++.h>
using namespace std;

bool readInteger(int& value) {
    if (cin >> value) {
        return true;
    }

    cout << "Invalid input! Please enter an integer.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void display(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << '\n';
}

int main() {
    cout << "NAME - Mayank Kalakoti\n";
    cout << "Roll No - 25bma022\n\n";

    int n;

    cout << "Enter number of elements: ";

    if (!readInteger(n)) {
        return 0;
    }

    if (n < 0) {
        cout << "Invalid size! Number of elements cannot be negative.\n";
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter " << n << " integers:\n";

    for (int i = 0; i < n; i++) {
        if (!readInteger(arr[i])) {
            i--;
        }
    }

    insertionSort(arr);

    cout << "Sorted array in ascending order:\n";
    display(arr);

    return 0;
}
