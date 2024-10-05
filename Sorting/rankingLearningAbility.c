#include <stdio.h>
#include <string.h>

typedef struct
{
	char ID[11];
	int grade;
	int rank;
} student;

student st[100001];
int n;

//sort by ID

void swap(int i, int j)
{
	student temp = st[i];
	st[i] = st[j];
	st[j] = temp;
}

void max_heapify_ID(int i, int size)
{
	int left = 2*i + 1;
	int right = 2*i + 2;
	int max = i;
	if(left < size && strcmp(st[left].ID, st[max].ID) > 0) max = left;
	if(right < size && strcmp(st[right].ID, st[max].ID) > 0) max = right;
	if(max != i)
    {
		swap(i, max);
		max_heapify_ID(max, size);
	}
}

void build_max_heap_ID(int size){
	for(int i = (size/2) - 1; i >= 0; i--)
    {
		max_heapify_ID(i, size);
	}
}

void heap_sort_ID(int size)
{
	build_max_heap_ID(size);
	for(int i = size - 1; i >= 0; i--)
    {
		swap(0, i);
		max_heapify_ID(0, i);
	}
}

//Place Rank for each student

void max_heapify_grade(int i, int size)
{
	int left = 2*i + 1;
	int right = 2*i + 2;
	int max =i;
	if(left < size && st[left].grade > st[max].grade) max = left;
	if(right < size && st[right].grade > st[max].grade) max = right;
	if(max != i)
    {
		swap(i, max);
		max_heapify_grade(max, size);
	}
}

void build_max_heap_grade(int size)
{
	for(int i = (size/2) - 1; i >= 0; i--)
    {
		max_heapify_grade(i, size);
	}
}

void heap_sort_grade(int size)
{
	build_max_heap_grade(size);
	for(int i = size - 1; i >= 0; i--)
    {
		swap(0, i);
		max_heapify_grade(0, i);
	}
}

void ranking()
{
	heap_sort_grade(n);
	for(int i = 0; i < n; i++)
    {
		st[i].rank = i;
	}
}

//solving

void read_input()
{
	for(int i = 0; i < n; i++)
    {
		scanf("%s", st[i].ID);
		scanf("%d", &st[i].grade);
	}
}

void print()
{
	for(int i = 0; i < n; i++)
    {
		printf("%s %d\n", st[i].ID, st[i].rank);
	}
}

void solve()
{
	scanf("%d", &n);
	read_input();
	ranking();
	heap_sort_ID(n);
	print();
}


int main()
{
	solve();
	return 0;
}