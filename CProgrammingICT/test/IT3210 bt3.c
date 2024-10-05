#include <stdio.h>

// Nguyên mẫu hàm
void process(int a[], int size, int *sum, int *mean);

int main() {
    // Khai báo mảng và kích thước
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Khai báo biến để lưu tổng và giá trị trung bình
    int sum, mean;

    // Gọi hàm process để tính tổng và giá trị trung bình
    process(arr, size, &sum, &mean);

    // Hiển thị kết quả
    printf("Tong cua day so la: %d\n", sum);
    printf("Gia tri trung binh cua day so la: %d\n", mean);

    return 0;
}

// Định nghĩa hàm process
void process(int a[], int size, int *sum, int *mean) {
    // Khởi tạo tổng
    *sum = 0;
    // Tính tổng các phần tử trong mảng
    for (int i = 0; i < size; i++) {
        *sum += a[i];
        *mean = *sum / size;
    }

    // Tính giá trị trung bình (lưu ý: đây chỉ là giá trị nguyên của tổng chia kích thước)
    
}
