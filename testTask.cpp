#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int** func(int n, int lenArr[]) {
	srand(time(NULL));
	int** arr = new int* [n];

	for (int i = 0; i < n; i++) {
		lenArr[i] = 2 + rand() % (n+8);
		for (int k = 0; k < i; k++) {
			if (lenArr[k] == lenArr[i]) {
				lenArr[i] = 2 + rand() % (n+8);
				k = -1;
			}		
		}
		arr[i] = new int[lenArr[i]];
		
		for (int j = 0; j < lenArr[i]; j++) {
			arr[i][j] = -30 + rand() % 100;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int left = 0; left < lenArr[i]; left++) {
			int value = arr[i][left];
			int k = left - 1;
			for (; k >= 0; k--) {
				if (i % 2 == 0 && value > arr[i][k]) {
					arr[i][k + 1] = arr[i][k];
				}
				else if (i % 2 != 0 && value < arr[i][k]) {
					arr[i][k + 1] = arr[i][k];
				}
				else break;
			}
			arr[i][k + 1] = value;
		}
	}
	return arr;
}

int main() {
	int n;
	while (1) {
		cin >> n;
		if (n > 0) break;
		else cout << "Try again!" << endl;
	}
	int* lenghArr = new int[n];
	int** arr = func(n, lenghArr);
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < lenghArr[i]; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}