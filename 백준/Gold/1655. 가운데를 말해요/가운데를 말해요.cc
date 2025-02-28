#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    priority_queue<int> maxq; priority_queue<int, vector<int>, greater<> > minq;
    for(int i = 1; i <= N; ++i){
        int t, t1, t2; cin >> t;
        if(minq.size() == maxq.size()) maxq.emplace(t);
        else minq.emplace(t);
        //정렬
        while(maxq.size() && minq.size() && maxq.top() > minq.top()){
            t1 = maxq.top(); maxq.pop();
            t2 = minq.top(); minq.pop();
            minq.emplace(t1); maxq.emplace(t2);
        }
        cout << maxq.top() << '\n';
    }
    return 0;
}