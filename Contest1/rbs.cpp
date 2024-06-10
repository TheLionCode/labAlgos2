#include <iostream>
#include <vector>
using namespace std;

/*
EXPLICACION
El algoritmo itera sobre el string recibido de input, si es una llave abierta guarda el indice como la ultima llave abierta,
si es una llave cerrada la compara con la ultima llave abierta y en caso de ser distintas las cuenta como cambio,
la ultima llave abierta pasa a ser el indice anterior. En paralelo se va contando cuantas llaves abiertas van quedando, ya que
si el numero es menor que 0 entonces quedaria una llave cerrada sin su apertura, por tanto seria Imposible.
*/

int main() {
    string input;
    getline(cin, input);

    string characters = "()<>[]{} ";
    int changes = 0;
    vector<int> lastOpen;
    lastOpen.push_back(0);

    int openclose = 0;
    
    for(int i = 0; i < input.size(); i++){
        const char temp = input[i];
        if(openclose < 0){
            cout << "Impossible" << endl;
            return 0;
        }
        else if(temp == characters[0] || temp == characters[2] || temp == characters[4] || temp == characters[6]){
            openclose += 1;
            lastOpen.push_back(i);
        }
        else {
            switch (temp) {
                case ')':
                    if(characters[0] != input[lastOpen.back()]){
                        changes += 1;
                    }
                    lastOpen.pop_back();
                    openclose -= 1;
                    break;
                case '>':
                    if(characters[2] != input[lastOpen.back()]){
                        changes += 1;
                    }
                    lastOpen.pop_back();
                    openclose -= 1;
                    break;
                case ']':
                    if(characters[4] != input[lastOpen.back()]){
                        changes += 1;
                    }
                    lastOpen.pop_back();
                    openclose -= 1;
                    break;
                case '}':
                    if(characters[6] != input[lastOpen.back()]){
                        changes += 1;
                    }
                    lastOpen.pop_back();
                    openclose -= 1;
                    break;
                default:
                    continue;
            }
        }
    }

    if(openclose != 0){
        cout << "Impossible" << endl;
        return 0;
    }

    cout << changes << endl;

	return 0;
}