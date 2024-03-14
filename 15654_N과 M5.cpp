#include <iostream>
#include <vector>
#include<algorithm>
#define endl '\n'
using namespace std;

int n, m;
vector<int> arr;
vector<int> ary;

void dfs(int last){
    if(arr.size() == m){
        for(int i = 0; i < m; ++i) cout << arr[i] << ' ';
        cout << endl;
        return; 
    }
    for(int i = last + 1; i <= n; ++i){
            arr.push_back(ary[i]);
            dfs(i);
            arr.pop_back();
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tmp;
    cin >> n >> m;
    ary.push_back(0);
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        ary.push_back(tmp);
    }
    sort(ary.begin(), ary.end());
    dfs(0);
    return 0;
}