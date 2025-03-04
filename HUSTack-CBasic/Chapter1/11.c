#include <stdio.h> 
#include <math.h> 
#include <string.h> 
#include <stdlib.h> 
int main() 
{ 	
    char str[300009]; 	
    scanf("%s", str); 	
    unsigned long long result=1, sum=0; 	
    char *token=strtok(str, "+"); 	
    while(token !=NULL) 	
    { 	    
        unsigned long long count=0; 	    
        unsigned long long result2=1; 	    
        unsigned long long ad=0; 	    
        unsigned long long result1=0;         
        for(unsigned long long i=0; i<strlen(token); i++)         
        {             
            if(token[i] != '*')
            {                 
                count++;             
            }             
            else
            {                 
                result1=0;                 
                for(unsigned long long j=ad; j<i; j++)                 
                {                     
                    result1+=(token[j]-'0')*pow(10,count-1);                     
                    count--;                 
                }                 
                ad=i+1;                 
                result2 *=result1;             
            }         
        } 		
        result1=0;         
        while(count !=0)         
        {             
            result1 += (token[ad]-'0')*pow(10,count-1); 			
            ad++;             
            count--;         
        }         
        result2 = result2*result1;         
        sum+=result2;         
        token=strtok(NULL, "+"); 	
    } 	
    unsigned long long ans =sum%((int) 1e9+7); 	
    printf("%llu", ans); 
}
