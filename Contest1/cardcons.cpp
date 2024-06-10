#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

/*
EXPLICACION DE LA FORMULA
Se aplica la pista del enunciado que indica que una piramide de altura H contiene por completo a la piramide de altura H-1,
sobre una base formada por H-piramides de altura 1 (2 cartas cada una) y H-1 horizontales para la piramide contenida, es decir,
podemos traducirlo a la formula Cn = (Cn-1) + 2n + (n-1) ; notamos la recursividad en el termino (Cn-1) y desarrollando y despejando llegamos a una sumatoria,
concluimos el despeje en Cn = 2 + 3((n(n+1)/2)-1) - (n-1) ; luego desarrollamos un poco mas hasta obtener la formula aplicada (3(n**2) + n)/2 .

EXPLICACION DEL ALGORITMO
El programa itera aplicando la formula y calculando la cantidad total de cartas para armar una piramide de la altura del iterador,
en caso de que la altura del siguiente iterador exceda la cantidad de cartas disponibles, se resta la cantidad de cartas necesarias actual y se reinicia el loop.
Asi sucesivamente se va restando la piramide mas alta.
*/

int main() {
	int t;
	scanf("%i", &t);

    while(t--){
        int n;
	    scanf("%i", &n);
        int totalPyramids = 0;

        while(n >= 2){
            for(int i = 1; i < n; i++){
                if(((3*pow(i, 2) + i)/2 <= n) && ((3*pow(i+1, 2) + i+1)/2 > n)){
                    n -= (3*pow(i, 2) + i)/2;
                    totalPyramids++;
                    break;
                }
            }
        }
        printf("%i\n", (int)totalPyramids);
    }
	return 0;
}