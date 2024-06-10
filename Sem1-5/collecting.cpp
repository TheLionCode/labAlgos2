#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class NumKey {
    public:
        int index;
        long long value;
        NumKey(int x = 0, long long y = 0) {
            index = x;
            value = y;
        }
};

int main() {
    int t;
    scanf("%i", &t);

    while(t--){
        int n;
        scanf("%i", &n);

        vector<NumKey> nums(n);
        for(int i = 0; i < n; i++){
            nums[i].index = i;
            scanf("%lli", &nums[i].value);
        }

        for (int i = 0; i < n; i++) {
            int currentIndex = i;
            for (int j = currentIndex - 1; j >= 0; j--) {
                if (nums[currentIndex].value < nums[j].value) {
                    swap(nums[currentIndex], nums[j]);
                    currentIndex = j;
                }
            }
        }

        for(int i = 0; i < nums.size(); i++){
            printf("%lli ",nums[i].value) ;
        }

        vector<int> sums(n);
        for(int i = 0; i < nums.size(); i++){
            long long sum = nums[i].value;
            for(int j = 0; j < nums.size(); j++){
                if(sum >= nums[j].value && i != nums[j].index){
                    sum += nums[j].value;
                    sums[i] += 1;
                } else {break;}
            }
        }

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(nums[j].index == i){
                    printf("%i ", sums[j]);
                }
            }
        }
        cout << endl;
    }
	return 0;
}