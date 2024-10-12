#include <stdio.h>
#include <stdlib.h>

//Hàm so sánh
int cmp1(const void *ptr1, const void *ptr2){
    //Ép kiểu
    int *x = (int*)ptr1;
    int *y = (int*)ptr2;
    if(*x < *y){
        return -1;
    }
    else{
        return 1;
    }
    //return *x - *y sẽ nhanh hơn
}

int cmp2(const void *ptr1, const void *ptr2){
    //Ép kiểu
    int *x = (int*)ptr1;
    int *y = (int*)ptr2;
    if(*x > *y){
        return -1;
    }
    else{
        return 1;
    }
    //return *y - *x sẽ nhanh hơn
}

int main(){
    int n;
    int a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Mang sap tang dan : ");
    qsort(a, n, sizeof(int), cmp1);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\nMang sap giam dan : ");
    qsort(a, n, sizeof(int), cmp2);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}