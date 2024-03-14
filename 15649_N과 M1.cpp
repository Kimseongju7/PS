#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int n, m;
vector<int> arr;

void dfs(int last){
    if(arr.size() == m){
        for(int i = 0; i < m; ++i) cout << arr[i] << ' ';
        cout << endl;
        return;
    }
    for(int i = last; i <= n; ++i){
        arr.push_back(i); //추가할 노드를 자신보다 큰 노드로 한정짓기
        dfs(i);
        arr.pop_back();
        
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    dfs(1);
    return 0;
}
