#include <iostream>

using namespace std;

struct Position {
	int start;
	int end;
};
int main(int argc, char *argv[]) {
	int num;
	cin >> num;
	Position array[num];
	for (int i = 0; i < num; i++) {
		cin >> array[i].start;
		cin >> array[i].end;
	}
	Position temp;
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			if (array[i].end > array[j].end) {
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	int count = 1;
	int current = 0;
	for (int i = 0; i < num; i++) {
		if (array[current].end <= array[i].start) {
			count++;
			current = i;
		}
	}
	cout << num - count << endl;
}
