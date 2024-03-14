#include <iostream>
using namespace std;

void switchS(bool &s){
    if(s) s = false;
    else s = true;
}

void switchW(bool * sw, int st, int end){
    for(int i = st; i <= end; ++i) switchS(sw[i]);
}

int main(){
    int N, T, gen, num;
    cin >> N;
    bool * sw = new bool[N + 1];
    for(int i = 1; i <= N; ++i) cin >> sw[i];
    cin >> T;
    while(T--){
        cin >> gen >> num;
        if(gen == 1){
            for(int i = 1; i * num <= N; ++i) switchS(sw[i * num]);
        }
        else{
            int i = 0;
            for(i = 1; (0 < num - i) && (num + i <= N); ++i){
                if(sw[num - i] != sw[num + i]) {
                    break;
                }
            }
            --i;
            switchW(sw, num - i, num + i);
        }
    }
    for(int i = 1; i <= N; ++i) {
        cout << sw[i];
        if(i % 20 == 0) cout << endl;
        else if(i != N) cout << ' ';
    }
    delete[] sw;
    return 0;
}