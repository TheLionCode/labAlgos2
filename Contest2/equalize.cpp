#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        quickSort(nums, 0, n - 1);

        int maxCount = 0;
        for(int i = 0; i < n; i++){
            int currentCount = 1;
            if(maxCount >= n - i){
                break;
            }
            if(nums[i] == nums[i + 1]){
                continue;
            }
            for(int j = i + 1; j < n; j++){
                if(j < n - 1 && nums[j] == nums[j + 1]){
                    continue;
                }
                if(nums[j] - nums[i] < n){
                    currentCount++;
                } else {
                    break;
                }
            }
            maxCount = max(maxCount, currentCount);
        }

        cout << maxCount << "\n";
    }

    return 0;
}