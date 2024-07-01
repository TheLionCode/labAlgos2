#include <iostream>
#include <cstdio>
using namespace std;

/*
Se emplea la estructura de Array ya que es la mas rapida, se guardan un valore,
temp que corresponde al indice del ultimo elemento escrito;
la operacion 1 avanza el lastItem al siguiente indice y sobrescribe el valor,
la operacion 2 retrocede el temp al anterior indice (como la operacion 1 sobreescribe el valor, no es necesario borrar),
la operacion 3 imprime el elemento en el indice temp
*/

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