#include <iostream>
#include <algorithm>

using namespace std;
int num = 0;
int solve(int *m, int start, int end, int tmp) {
	if (m[start] > tmp) {
		num ++;
		tmp = m[start] + 8;
		for (int i = start; i < end; i++) {
			if (m[i] > tmp) {
				solve(m, i, end, tmp);
				break;
			}
		}
		return 0;
	} else {
		return 0;
	}
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int m[n];
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	sort(m, m + n);
	solve(m, 0, n, 0);
	cout << num;
}