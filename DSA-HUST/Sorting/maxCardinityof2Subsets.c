#include <stdio.h>

//Heap sort

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int a[], int i, int size)
{
	int left = 2*i + 1;
	int right = 2*i + 2;
	int max = i;
	if(left < size && a[left] > a[max]) max = left;
	if(right < size && a[right] > a[max]) max = right;
	if(max != i)
    {
		swap(&a[i], &a[max]);
		max_heapify(a, max, size);
	}
}

void build_max_heap(int a[], int size)
{
	for(int i = (size/2) - 1; i >= 0; i--)
    {
		max_heapify(a, i, size);
	}
}

void heap_sort(int a[], int size)
{
	build_max_heap(a, size);
	for(int i = size - 1; i >= 0; i--)
    {
		swap(&a[0], &a[i]);
		max_heapify(a, 0, i);
	}
}

void read_input(int a[], int size)
{
	for(int i = 0; i < size; i++)
    {
		scanf("%d", &a[i]);
	}
//	for(int i = 0; i < size; i++){
//		printf("%d ", a[i]);
//	}
//	printf("\n");
}

int binary_search(int a[], int start, int end, int key)
{
	if(start > end) return 0;
	int mid = (start + end) / 2;
	if(a[mid] == key) return 1;
	if(a[mid] < key) return binary_search(a, mid + 1, end, key);
	else return binary_search(a, start, mid - 1, key);
}

void solve()
{
	int n, m, count = 0;
	scanf("%d %d", &n, &m);
	int a[n]; 
    int b[m];
	read_input(a, n);
	read_input(b, m);
	if(n >= m)
    {
		heap_sort(a, n);
		for(int i = 0; i < m; i++){
			if(binary_search(a, 0, n, b[i])) count++;
		}
	}
	else{
		heap_sort(b, m);
		for(int i = 0; i < n; i++){
			if(binary_search(b, 0, m, a[i])) count++;
		}
	}
	printf("%d", count);
}



int main()
{
	solve();
	return 0;
}