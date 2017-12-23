#include <iostream>

using namespace std;
long long solve_1(long long n);
long long solve_2(long long n, long long m);


long long solve_1(long long n) {
	long long j = 2;
	if (n <= 1) {
		return 1;
	} else {
		n = n / 2;
		while(n != 1) {
			n = n / 2;
			j *= 2;
		}
		return j;
	}
}

long long solve_2(long long n, long long m) {
	long long j = 1;
	if (n <= 1) {
		return 1;
	} else {
		for (int i = 0; i < n - 1; i++) {
			j = (j + m - 1) % (i + 2) + 1;
		}
		return j;
	}
}

int main(int argc, char *argv[]) {
	long long n, m;
	cin >> n >> m;
	cout << solve_1(n);
	cout << " " << solve_2(n, m) << endl;
}