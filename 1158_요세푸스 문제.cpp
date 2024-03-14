#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    queue<int> q;
    cout << "<";
    for(int i = 1; i <= N; ++i) q.push(i);
    while(q.size() > 1){
        for(int i = 0; i < K - 1; ++i){
            int tmp;
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">" << endl;
    return 0;
}