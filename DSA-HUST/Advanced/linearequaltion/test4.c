//C 
#include <stdio.h> 
int n, m, b[100], result = 0, sum = 0; 
void Try(int k)
{     
    for(int i = 1; i <= m - n + k; i++)
    {         
        sum += i * b[k];         
        if  (sum > m) 
        {             
            sum -= i * b[k];             
            continue;         
        }                  
        if (k == n)
        {             
            if(sum == m) 
            result++;         
        }         
        else Try(k+1);         
        sum -= i * b[k];     
    } 
} 

int main()
{     
    scanf("%d %d", &n, &m); 	
    for (int i = 1; i <= n; i++)
    { 		
        scanf("%d", &b[i]); 	
    }     
    Try(1); 	
    printf("%d\n", result); 
}