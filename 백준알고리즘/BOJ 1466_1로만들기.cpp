
#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int* arr = new int[N + 1];
	arr[1] = 0;
	if (N == 2) {
		arr[2] = 1;
	}
	else if (N > 2) {
		arr[2] = 1;
		arr[3] = 1;
	}
	for (int i = 4; i <= N; i++) {
		int temp = 999999;
		if (i % 3 == 0) {
			if (temp > arr[i / 3] + 1)
				temp = arr[i / 3] + 1;
		}
		if (i % 2 == 0) {
			if (temp > arr[i / 2] + 1)
				temp = arr[i / 2] + 1;
		}
		if (temp > arr[i - 1] + 1)
			temp = arr[i - 1] + 1;
		arr[i] = temp;
	}
	cout << arr[N];
	return 0;
}
