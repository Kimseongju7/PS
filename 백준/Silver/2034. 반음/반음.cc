#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; int st, end;
    int arr[10101];
    char P[15] = {'A', 'X', 'B', 'C', 'X', 'D', 'X', 'E', 'F', 'X', 'G', 'X'};
    int size = 12;
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    for(int i = 0; i < size; ++i){
        st = i; end = i;
        if(P[st] == 'X') continue;
        for(int j = 1; j <= N; ++j){
            end = end + arr[j];
            if(end < 'X') end += size;
            end %= size;
            if(P[end] == 'X') break;
            if(j == N) cout << P[st] << ' ' << P[end] << '\n';
        }
    }
    return 0;
}
