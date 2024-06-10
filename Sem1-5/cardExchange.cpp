#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool repeats_at_least_k(vector<int> vec, int k) {
    int count = 1;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] == vec[i - 1]) {
            count++;
        } else {
            if (count >= k) {
                return true;
            }
            count = 1;
        }
    }
    return count >= k;
}

int main(){
    int t;
    scanf("%i", &t);

    while (t--){
        int n, k;
        scanf("%i", &n);
        scanf("%i", &k);

        vector<int> cards(n);
        for(int i = 0; i < n; i++){
            scanf("%i", &cards[i]);
        }

        if( k > n){
            printf("%i", (int)n);
        } else {
            for (int i = 0; i < n; i++) {
                int currentIndex = i;
                for (int j = currentIndex - 1; j >= 0; j--) {
                    if (cards[currentIndex] < cards[j]) {
                        swap(cards[currentIndex], cards[j]);
                        currentIndex = j;
                    }
                }
            }
            if(repeats_at_least_k(cards, k)){
                printf("%i", k - 1);
            }
            else {
                printf("%i", n);
            }
        }
        cout << endl;
    }
    return 0;
}