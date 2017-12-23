#include <iostream>

using namespace std;
int flag = 0;
void solve(int X[], int begin_x, int end_x, int Y[], int begin_y, int end_y, int k) {
	if (begin_x > end_x) {
		cout << Y[begin_y + k - 1];
		flag = 1;
	}
	if (begin_y > end_y) {
		cout << X[begin_x + k - 1];
		flag = 1;
	}
	if (!flag) {
		int mid_x = (end_x - begin_x) / 2 + begin_x;
		int mid_y = (end_y - begin_y) / 2 + begin_y;
		if (X[mid_x] < Y[mid_y]) {
			if (k < (mid_x - begin_x) + (mid_y - begin_y) + 2) {
				solve(X, begin_x, end_x, Y, begin_y, mid_y - 1, k);
			} else {
				solve(X, mid_x + 1, end_x, Y, begin_y, end_y, k - (mid_x - begin_x + 1));
			}
		} else {
			if (k < (mid_x - begin_x) + (mid_y - begin_y) + 2) {
				solve(X, begin_x, mid_x - 1, Y, begin_y, end_y, k);
			} else {
				solve(X, begin_x, end_x, Y, mid_y + 1, end_y, k - (mid_y - begin_y + 1));
			}
		}
	}

}

int main(int argc, char *argv[]) {
	int m, n, k;
	cin >> m;
	cin >> n;
	cin >> k;
	int X[m], Y[n];
	for (int i = 0; i < m; i++) {
		cin >> X[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> Y[i];
	}
	solve(X, 0, m - 1, Y, 0, n - 1, k);
	return 0;
}
