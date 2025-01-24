#include<iostream>
#include<iomanip>
#include<map>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    map<string, double> m;
    m["Paper"] = 57.99; m["Printer"] = 120.50; m["Planners"] = 31.25; m["Binders"] = 22.50; m["Calendar"] = 10.95; m["Notebooks"] = 11.20; m["Ink"] = 66.95;
    double dap = 0;
    string s;
    while (true)
    {
        cin >> s;
        if(s == "EOI") break;
        dap += m[s];
    }
    cout << fixed;
    cout.precision(2);
    cout << "$" << dap;
    return 0;
}