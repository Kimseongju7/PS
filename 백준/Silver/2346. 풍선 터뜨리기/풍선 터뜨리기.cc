#include<iostream>
#include<deque>
#include<utility>
#include<cstdlib>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    deque<pair<int, int> > dq;
    for(int i = 1; i <= N; ++i){
        int n;
        cin >> n;
        dq.emplace_back(i, n);
    }
    while(!dq.empty()){
        auto [number, n] = dq.front();
        dq.pop_front();
        cout << number << ' ';
        if(n < 0){
            for(int i = 0; i < abs(n); ++i){
                dq.emplace_front(dq.back());
                dq.pop_back();
            }
        }
        else{
            for(int i = 1; i < n; ++i){
                dq.emplace_back(dq.front());
                dq.pop_front();
            }
        }
    }
    return 0;
}
