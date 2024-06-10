#include <iostream>
#include <vector>
using namespace std;

class NumKey {
public:
    int index;
    int value;
    NumKey(int x = 0, int y = 0) {
        index = x;
        value = y;
    }
};

class NumPart {
public:
    int first;
    int last;
    int total;
    NumPart(int x = -1, int y = -1, int z = 0) {
        first = x;
        last = y;
        total = z;
    }
};

int partition(vector<NumKey>& arr, int low, int high) {
    NumKey pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].value < pivot.value) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<NumKey>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int partitionParts(vector<NumPart>& arr, int low, int high) {
    NumPart pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].total > pivot.total) {
            i++;
            swap(arr[i], arr[j]);
        } else if (arr[j].total == pivot.total) {
            if (arr[j].first < pivot.first) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksortParts(vector<NumPart>& arr, int low, int high) {
    if (low < high) {
        int pivot = partitionParts(arr, low, high);
        quicksortParts(arr, low, pivot - 1);
        quicksortParts(arr, pivot + 1, high);
    }
}

int main() {
    int n, c;
    cin >> n >> c;

    vector<NumKey> nums(n);
    vector<NumPart> parts(c);

    for (int i = 0; i < n; i++) {
        nums[i].index = i;
        cin >> nums[i].value;
    }

    quicksort(nums, 0, nums.size() - 1);

    for (int i = 0; i < nums.size(); i++) {
        parts[nums[i].value - 1].total += 1;
        if (parts[nums[i].value - 1].first == -1) {
            parts[nums[i].value - 1].first = i;
        }
        parts[nums[i].value - 1].last = i;
    }

    quicksortParts(parts, 0, parts.size() - 1);

    for (int i = 0; i < parts.size(); i++) {
        for (int j = parts[i].first; j <= parts[i].last; j++) {
            cout << nums[j].value << " ";
        }
    }
    cout << endl;
    return 0;
}