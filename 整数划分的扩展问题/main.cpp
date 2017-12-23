#include <iostream>

using namespace std;
int solve_1(int n, int m);
int solve_2(int n, int m);
int solve_3(int n, int m);

int solve_1(int n, int m) {
	if (m == 1 || n == 1) {
		return 1;
	}
	if (n < 1 || m < 1) {
		return 0;
	}
	if (n < m) {
		return solve_1(n, n);
	}
	if (n == m) {
		return solve_1(n, m - 1) + 1;
	}
	return solve_1(n, m - 1) + solve_1(n - m, m);
}

// 正偶整数之和的划分数
int solve_2(int n, int m){
	if(m > n || m <= 0){
		return 0;
	}
	
	if(((n == 1) && (m == 1)) || ((n == 2) && (m == 2))){
		return 0;
	}
	
	if((n == 2) && (m == 1)){
		return 1;
	}
	
	return solve_3(n-m, m);
}

// 正奇整数之和的划分数
int solve_3(int n, int m){
	if(m > n || m <= 0){
		return 0;
	}
	
	if((n == 2) && (m == 1)){
		return 0;
	}
	
	if(((n == 1) && (m == 1)) || ((n == 2) && (m == 2))){
		return 1;
	}
	
	return solve_3(n-1, m-1) + solve_2(n-m, m);
}

int main(int argc, char *argv[]) {
	int n, m, num;
	cin >> n;
	cin >> m;
	num = solve_1(n, m);
	cout << num << " " << num <<" ";
	num = 0;
	for (int i = 1; i <= n; i++) {
		num += solve_3(n, i);
	}
	cout << num << " " << num << endl;
}
