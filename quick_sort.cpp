
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

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

    quickSort(arr, 0, n - 1);

    cout << "Sorted array in ascending order:\n";
    display(arr);

    return 0;
}
