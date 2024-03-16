#include <iostream>
#define endl '\n'
#include <algorithm>
using namespace std;

bool compare(const pair<int, int> a, const pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, x, y;
    cin >> N;
    pair<int, int> v[101010];
    for(int i = 0; i < N; ++i){
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }
    sort(v, v + N, compare);
    for(int i = 0; i < N; ++i){
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    return 0;
}