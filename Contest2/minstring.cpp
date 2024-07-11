#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t, u;
    cin >> s;

    while(s.length() > 0){
        if(t.length() == 0){
            t += s[0];
            s.erase(0, 1);
            continue;
        } else if(s[0] <= t[t.length() - 1]){
            t += s[0];
            s.erase(0, 1);
            continue;
        } else {
            u += t[t.length() - 1];
            t.erase(t.length() - 1);
        }
    }

    while(t.length() > 0){
        u += t[t.length() - 1];
        t.erase(t.length() - 1);
    }

    cout << u << "\n";

    return 0;
}