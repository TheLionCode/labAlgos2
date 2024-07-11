#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;

    cin >> m >> n;

    vector<int> rows(m, 1);
    vector<int> columns(n, 1);
    vector<vector<int>> matrixB(m);
    vector<vector<int>> matrixA(m);

    for(int i = 0; i < m; i++){
        matrixB[i].resize(n);
        matrixA[i].resize(n);
        for(int j = 0; j < n; j++){
            cin >> matrixB[i][j];
            if(matrixB[i][j] == 0){
                rows[i] = 0;
                columns[j] = 0;
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrixB[i][j] == 1 && columns[j] == 0 && rows[i] == 0){
                cout << "NO\n";
                return 0;
            } else if(columns[j] == 1 && rows[i] == 1){
                matrixA[i][j] = 1;
            }
        }
    }

    cout << "YES\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << matrixA[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}