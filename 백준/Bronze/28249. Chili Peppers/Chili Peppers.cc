#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, dap = 0; string s;
    cin >> N;
    while(N--){
        cin >> s;
        if(s == "Poblano") dap += 1500;
        else if(s == "Mirasol") dap += 6000;
        else if(s == "Serrano") dap += 15500;
        else if(s == "Cayenne") dap += 40000;
        else if(s == "Thai") dap += 75000;
        else if(s == "Habanero") dap += 125000;
    }
    cout << dap;
    return 0;
}