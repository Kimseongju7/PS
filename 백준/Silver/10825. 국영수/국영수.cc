#include<algorithm>
#include<iostream>
#include<utility>
#include<vector>
#define endl '\n'
using namespace std;

class person{
public :
    string name;
    int k, e, m;
};
vector<person> v;
bool compair1(person &a, person &b){
    if(a.k == b.k){
        if(a.e == b.e){
            if(a.m == b.m) return a.name < b.name;
            else return a.m > b.m;
        }
        else return a.e < b.e;
    } else return a.k > b.k;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i){
        string s;
        int k, e, m;
        cin >> s >> k >> e >> m;
        v.push_back({s, k, e, m});
    }
    sort(v.begin(), v.end(), compair1);
    for(int i = 0; i < N; ++i) cout << v[i].name << endl;
    return 0;
}