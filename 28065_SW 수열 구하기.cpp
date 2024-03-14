#include <iostream>
using namespace std;

int main(){
    int N;
    int st, en;
    cin >> N;
    st = 1;
    en = N;
    while(st <= en){
        cout << en;
        cout << ' ';
        if(st != en) {
            cout << st;
            cout << ' ';
        }
        ++st;
        --en;
    }
    return 0;
}