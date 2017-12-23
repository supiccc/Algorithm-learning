#include <iostream>

using namespace std;

int count_solve = 0;

void solve(int num) {
	if (num == 1) {
		count_solve ++;
	} else {
		for (int i = 2;i <= num;i++) {
			if (num % i == 0) {
				solve(num / i);
			}
		}
	}
}
int main(int argc, char *argv[]) {
	int num;
	cin >> num;
	solve(num);
	cout << count_solve;
}