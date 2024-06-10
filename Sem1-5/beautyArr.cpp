#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> nums;
        nums.resize(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] < nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }
        int answer = nums[n - 1] - nums[0];
        cout << answer << endl;
    }
    return 0;
}