#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    string s;
    int dap;
    bool honest = true;
    vector<pair<int, int> > v;
    while(true){
        v.clear(); honest = true;
        while(true){
            cin >> N;
            if(!N) exit(0);
            cin.ignore();
            getline(cin, s);
            if (s == "too high") v.emplace_back(N, 1);
            else if(s == "too low") v.emplace_back(N, 0);
            else if(s == "right on") {
                dap = N;
                break;
            }
        }
        for(auto [i, j] : v){
            if(j && dap >= i) honest = false;
            if(!j && dap <= i) honest = false;
        }
        if(honest) cout << "Stan may be honest\n";
        else cout << "Stan is dishonest\n"; 
    }
    return 0;
}