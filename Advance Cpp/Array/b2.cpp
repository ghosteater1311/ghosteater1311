#include <iostream> 

using namespace std;

int main() {
	int n;
    int sum = 0;
    int i;
	cin >> n;
	// Thực hiện cấp phát bộ nhớ động cho mảng
	int* arr = new int[n];
	// Nhập dữ liệu cho mảng
	for (i = 0; i < n; i++) 
    {
		cin >> arr[i];
	}
	// Tính tổng các phần tử trong mảng và lưu vào biến sum
	for (i = 0; i < n; i++)
    {
        sum +=arr[i];
    }
	cout << "Sum = " << sum;
	delete []arr;
	return 0;
}