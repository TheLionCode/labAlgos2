#include <iostream>
#include <cstdio>
using namespace std;

/*
Se emplea la estructura de Array ya que es la mas rapida, se guardan dos valores,
lastItem que corresponde al indice del ultimo elemento agregado y firstItem, el elemento mas viejo agregado;
la operacion 1 avanza el lastItem al siguiente indice y sobrescribe el valor,
la operacion 2 avanza el firstItem al siguiente indice (simulando haberlo eliminado),
la operacion 3 imprime el elemento en el indice firstItem
*/

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