#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define endl '\n'

struct compare
{
    bool operator() (pair<int,int> &a, pair<int,int> &b){
        if(a.first != b.first) return a.first > b.first;
        else return a.second > b.second;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, n;
    cin >> N;
    priority_queue<pair<int, int>, vector<pair<int,int> >, compare> q;
    for(int i = 0; i < N; ++i){
        cin >> n;
        if(n){
            if(n > 0) q.emplace(n, n);
            else q.emplace(-n, n);
        }
        else {
            if(q.empty()) cout << 0 << endl;
            else {
                cout << q.top().second << endl;
                q.pop();
            }
        }
    }
    return 0;
}