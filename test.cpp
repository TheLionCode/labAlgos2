#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

int main() {
    int t;
    scanf("%i", &t);

    list<int> queue;

    while(t--){
        int querie;
        scanf("%i", &querie);

        if(querie == 1){
            int input;
            scanf("%i", &input);
            queue.push_back(input);
        }
        else if(querie == 2){
            if(queue.size() > 0){
                queue.pop_front();
            }
        }
        else{
            if(queue.size() > 0){
                printf("%i\n", queue.front());
            } else {
                printf("Empty!\n");
            }
        }
    }
	
	return 0;
}