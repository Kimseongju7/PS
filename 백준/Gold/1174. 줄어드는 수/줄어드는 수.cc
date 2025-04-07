#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    unsigned long long dap[505050] = {};
    int index = 1, N;
    unsigned long long num, n;
    cin >> N;
    
    queue<unsigned long long> q;
    for(int i = 0; i <= 9; ++i) {
        q.push(i);
        dap[index++] = i;
    }

    while(!q.empty()){
        num = q.front(); q.pop();

        for(int i = 0; i < num % 10; ++i){
            n = num * 10 + i;
            q.push(n);
            dap[index++] = n;
        }
    }

    if(N >= index) cout << -1;
    else cout << dap[N];
    return 0;
}