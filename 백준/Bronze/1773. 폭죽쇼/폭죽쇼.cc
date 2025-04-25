#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    cin.tie(0)->sync_with_stdio(0);
	int count = 0;
	int n, c = 0;
	vector<int> v;
	
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	for (int i = 1; i <= c; i++) {
		for (int j = 0; j < n; j++) {
			if (i%v[j] == 0) {
				count++;
				break;
			}
		}
	}

	cout << count << endl;
	return 0;
}