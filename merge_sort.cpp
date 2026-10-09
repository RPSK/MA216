
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

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < (int)temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array in ascending order:\n";
    display(arr);

    return 0;
}
