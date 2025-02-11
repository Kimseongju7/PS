#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; int st, end;
    int arr[10101];
    char P[15] = {'A', 0, 'B', 'C', 0, 'D', 0, 'E', 'F', 0, 'G', 0};
    int size = 12;
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    for(int i = 0; i < size; ++i){
        st = i; end = i;
        if(P[st] == 0) continue;
        for(int j = 1; j <= N; ++j){
            end = end + arr[j];
            end %= size;
            if(end < 0) end += size;
            if(P[end] == 0) break;
            if(j == N) cout << P[st] << ' ' << P[end] << '\n';
        }
    }
    return 0;
}
