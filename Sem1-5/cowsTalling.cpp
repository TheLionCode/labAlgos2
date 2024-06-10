#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

vector<int> minAdjacentDifference(const vector<int>& arr) {
    vector<int> minDiff{INT_MAX, 0};
    for (int i = 0; i < arr.size() - 1; i++) {
        int diff = abs(arr[i] - arr[i + 1]);
        if (diff < minDiff[0]) {
            minDiff[0] = diff;
            minDiff[1] = i + 1;
        }
    }
    return minDiff;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n, c;
        scanf("%d", &n);
        scanf("%d", &c);

        vector<int> stalls(n);
        for(int i = 0; i < n; i++){
            scanf("%i", &stalls[i]);
        }

        mergeSort(stalls, 0, n - 1);

        if(c == 2){
            printf("%i", abs(stalls[0] - stalls[n - 1]));
        } else if (c == n){
            int min = minAdjacentDifference(stalls)[0];
            printf("%i", (int)min);
        } else {
            int difference = n - c;
            for(int i = difference; i > 0; i--){
                stalls.erase(stalls.begin() + minAdjacentDifference(stalls)[1]);
            }
            int min = minAdjacentDifference(stalls)[0];
            printf("%i", (int)min);
        }
        cout << endl;
    }
    return 0;
}