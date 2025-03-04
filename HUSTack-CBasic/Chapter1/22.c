//C 
#include <stdio.h> 
#include <string.h> 

int main() 
{     
    char str1[5];     
    char str2[100];     
    char str3[400];     
    char temp[200]; 

    scanf("%s", str1);     
    getchar();     
    fgets(str2, sizeof(str2), stdin);     
    fgets(str3, sizeof(str3), stdin); 

    strcpy(temp, str3);     

    char *tok = strtok(temp, " ");  

    while(tok != NULL)     
    {         
        if(strcmp(tok, str1) != 0)         
        {             
            printf("%s ", tok);         
        }         
        else         
        {             
            for(int i = 0; i < strlen(str2); i++)             
            {                 
                if(str2[i] != '\n')                     
                printf("%c", str2[i]);             
            }             
            printf(" ");         
        }         
        tok = strtok(NULL, " ");     
    } 
}
