#include <bits/stdc++.h>

using namespace std;

int main() {
	int m, n;
	int i, j;
	cin >> n >> m;
	// Khai báo con trỏ cấp 2 arr
	int **arr;
	// Cấp phát vùng nhớ động cho mảng 1 chiều các con trỏ kiểu int*
	arr = new int*[n]; 
	// Có thể hiểu arr là mảng n phần tử, mỗi phần tử là 1 con trỏ kiểu int*
	// Cấp phát động cho các n mảng 1 chiều
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	// Nhập dữ liệu cho các phần tử trong mảng
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}	
	}
	// Tính tổng từng hàng và hiển thị ra màn hình
	for (i = 0; i < n; i++)
	{
		int sum = 0;
		for (j = 0; j < m; j++)
		{
			sum += arr[i][j];
		}
		cout << sum << endl;
	}
	// Giải phóng bộ nhớ
	for (i = 0; i < n; i++)
	{
		// Giải phóng bộ nhớ con các mảng một chiều
		delete[] arr[i];
	}
	// Giải phóng bộ nhớ cho mảng các con trỏ
	delete[] arr;
	
	return 0;
}