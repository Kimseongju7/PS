#include<iostream>
#include<stack>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long N, G, B, x, y, D; cin >> N >> G >> B >> D;
    vector<pair<int, int> > O;
    int next[50505];
    stack<pair<int, int> > st;
    for(int i = 1; i <= N; ++i){
        cin >> x >> y;
        O.emplace_back(x, y);
    }
    O.emplace_back(D, -1);
    sort(O.begin(), O.end());
    for(int i = O.size() - 1; i >= 0; --i){
        int t = -1;
        while(!st.empty()){
            if(st.top().first <= O[i].second){
                t = st.top().second;
                break;
            }
            else st.pop();
        }
        next[i] = t;
        st.emplace(O[i].second, i);
    }
    long long pos = 0, dap = 0, nxt = O[0].first;
    for(int i = 0; i < N; ++i){
        B -= O[i].first - pos;
        if(B < 0){
            cout << -1;
            return 0;
        }
        pos = O[i].first;
        if(next[i] == -1 || O[next[i]].first - pos > G){
            dap += (G - B) * O[i].second;
            B = G;
        }
        else{
            if(O[next[i]].first - pos > B) {
                dap += (O[next[i]].first - pos - B) * O[i].second;
                B = O[next[i]].first - pos;
            }
            i = next[i] - 1;
        }
    }
    cout << dap;
    return 0;
}