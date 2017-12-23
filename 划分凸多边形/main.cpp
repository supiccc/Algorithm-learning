#include <iostream>

using namespace std;
int *arr; //存储计算过的结果

int total(int n) {
	if (arr[n] != 0) {
		//返回以前计算过的结果，增加运行速度
		return arr[n];
	}
	
	int num = 0;
	for (int i = 2; i < n; i++) {
		num += total(i) * total(n - i + 1);
	}
	arr[n] = num;
	return num;

}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	if (n == 2 || n == 1) {
		cout << "No answer";
		return 0;
	}
	int N[n];
	for (int i = 0; i < n + 1; i++) {
		N[i] = 0;
	}
	N[2] = 1;
	N[3] = 1;
	arr = N;
	cout << total(n);
	return 0;
}