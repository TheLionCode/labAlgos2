#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%i", &t);

    int queue[t];

    int lastItem = -1;
    int firstItem = 0;

    while(t--){
        int querie;
        scanf("%i", &querie);

        if(querie == 1){
            int input;
            scanf("%i", &input);
            lastItem++;
            queue[lastItem] = input;
        }
        else if(querie == 2){
            if(firstItem <= lastItem){
                firstItem++;
            }
        }
        else{
            if(firstItem <= lastItem){
                printf("%i\n", queue[firstItem]);
            } else {
                printf("Empty!\n");
            }
        }
    }
	
	return 0;
}