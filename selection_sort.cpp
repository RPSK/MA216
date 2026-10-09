
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

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
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

    selectionSort(arr);

    cout << "Sorted array in ascending order:\n";
    display(arr);

    return 0;
}
