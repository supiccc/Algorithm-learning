#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	int *c = new int[n];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		cout << c[i];
	}
	return 0;
}