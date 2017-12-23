#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int num;
	cin >> num;
	int arrayOriginal[num][num], arrayPath[num][num];//一个原始数组，一个保存路径数组
	memset(arrayOriginal, -1, sizeof(int));
	memset(arrayPath, -1, sizeof(int));//数组清零
	for (int i = 0; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arrayOriginal[i][j];
		}
	}
	/*测试数组
	for(int i = 0; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			cout << arrayOriginal[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 0; i < num; i++) {
		//最底层填充数组
		arrayPath[num - 1][i] = arrayOriginal[num - 1][i];
	}
	
	for (int i = num - 2; i >= 0; i--) {
		//求最大路径数组
		for(int j = 0; j <= i; j++) {
			arrayPath[i][j] = max(arrayPath[i + 1][j], arrayPath[i + 1][j + 1]) + arrayOriginal[i][j];
		}
	}
	cout << arrayPath[0][0] << endl;
	//输出最长路径
	cout << arrayOriginal[0][0];
	int y = 0;
	for (int i = 1; i < num; i++) {
		cout << " ";
		if (arrayPath[i][y] > arrayPath[i][y + 1]) {
			cout << arrayOriginal[i][y];
		} else {
			cout << arrayOriginal[i][y + 1];
			y += 1;
		}
	}
	return 0;
}