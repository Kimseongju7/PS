#include <iostream>
using namespace std;

int main() {
	int N;
	int level[100];
	int count = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> level[i];
	}

	for (int i = N - 1; i > 0; i--) {
		// 이전 레벨의 점수가 더 높다면,
		while (level[i] <= level[i - 1]) {
			level[i - 1]--;	// 이전 레벨의 점수 감소
			count++;	// 감소시킨 횟수를 카운트
		}
	}
	
	cout << count;

	return 0;
}
