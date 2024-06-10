#include <iostream>
#include <cstdio>
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
    NumPart(int x = -1, int y = -1, int z = 0){
        first = x;
        last = y;
        total = z;
    }
};

int main() {
    int n, c;
    scanf("%d", &n);
    scanf("%d", &c);

    vector<NumKey> nums(n);
    vector<NumPart> parts(c);

    for (int i = 0; i < n; i++) {
        nums[i].index = i;
        scanf( "%d", &nums[i].value);
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
        parts[nums[i].value - 1].total += 1;
        if(parts[nums[i].value - 1].first == -1){
            parts[nums[i].value - 1].first = i;
        }
        parts[nums[i].value - 1].last = i;
    }

    for (int i = 1; i < c; i++) {
        int currentIndex = i;
        for (int j = currentIndex - 1; j >= 0; j--) {
            if (parts[currentIndex].total > parts[j].total) {
                swap(parts[currentIndex], parts[j]);
                currentIndex = j;
            } else if(parts[currentIndex].total == parts[j].total){
                if(nums[parts[currentIndex].first].index < nums[parts[j].first].index){
                    swap(parts[currentIndex], parts[j]);
                    currentIndex = j;
                }
            }
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = parts[i].first; j <= parts[i].last; j++) {
            printf("%i ", (int)nums[j].value);
        }
    }
    cout << endl;
    return 0;
}