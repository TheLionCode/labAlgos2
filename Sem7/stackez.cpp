#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%i", &t);

    int queue[t];

    int temp = -1;

    while(t--){
        int querie;
        scanf("%i", &querie);

        if(querie == 1){
            int input;
            scanf("%i", &input);
            temp++;
            queue[temp] = input;
        }
        else if(querie == 2){
            if(temp >= 0){
                temp--;
            }
        }
        else{
            if(temp >= 0){
                printf("%i\n", queue[temp]);
            } else {
                printf("Empty!\n");
            }
        }
    }
	
	return 0;
}