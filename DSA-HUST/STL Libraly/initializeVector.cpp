#include <iostream>
// Kiểu dữ liệu vector nằm trong thư viện vector nên bạn cần include thư viện này
#include <vector>

using namespace std;

vector<int> initializeVector(int n)
{
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    return a;
}

int main() {
    // Khởi tạo vector các số nguyên a
    vector<int> a;

    // Thêm phần tử vào vector sử dụng hàm push_back
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    // Sử dụng hàm size() để lấy ra số phần tử trong vector
    cout << "Size of vector a: " << a.size() << endl;

    // Bạn có thể dụng vòng lặp để duyệt vector giống với duyệt mảng
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    return 0;
}