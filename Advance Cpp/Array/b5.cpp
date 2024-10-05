#include<iostream>

using namespace std;

void resize(int** arr, int newSize) {
	delete[] *arr;
	*arr = new int[newSize];
}

int main() {
	int* arr = new int[10];
	resize(&arr, 1000);
	for (int i = 0; i < 1000; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < 1000; i++) {
		cout << arr[i] << " ";
	}
	delete[]arr;
	return 0;
}

/*
#include<iostream>

using namespace std;

void resize(int*& arr, int newSize) {
	delete[] arr;
	arr = new int[newSize];
}

int main() {
	int* arr = new int[10];
	resize(arr, 1000);
	for (int i = 0; i < 1000; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < 1000; i++) {
		cout << arr[i] << " ";
	}
	delete[]arr;
	return 0;
}
*/