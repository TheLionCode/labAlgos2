#include <iostream>
#include <cstdio>
using namespace std;

/*
EXPLICACION
La idea es iterar sobre cada secuencia de piezas, una secuencia esta formada solo por un tipo de pieza y una vez hay un cambio se intercambian las sumas. 
En paralelo, se calcula el minimo de las ultimas dos secuencias y ese valor se duplica para obtener la respuesta.
*/

int main() {
	int n;
	scanf("%i", &n);

    int biggestResult = 0;
    int lastSum = 0;
    int sum = 1;
    int ingredient = 0;
    scanf("%i", &ingredient);

    for(int i = 0; i < n - 1; i++){
        int temp;
        scanf("%i", &temp);
        if(temp == ingredient){
            sum += 1;
        } else if(temp != ingredient){
            if(2 * min(lastSum, sum) > biggestResult && lastSum != 0){
                biggestResult = 2 * min(lastSum, sum);
            }
            lastSum = sum;
            sum = 1;
            ingredient = temp;
        }
        if(i == n - 2){
            if(2 * min(lastSum, sum) > biggestResult){
                biggestResult = 2 * min(lastSum, sum);
            }
        }
    }

    printf("%i", (int)biggestResult);
    
	return 0;
}