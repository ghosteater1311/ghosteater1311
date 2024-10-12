#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct node{
    int coef;
    int expo;
    struct node *next;
}node;
node *poly[100], *temp[100];
int used[100];

void AddTerm(int id, int coe, int exp){
    if(used[id]==0) used[id]=1;
    node *newnode=(node *)malloc(sizeof(newnode));
    newnode->next=NULL;
    newnode->coef=coe;
    newnode->expo=exp;
    if(poly[id]==NULL){
        poly[id]=temp[id]=newnode;
    }
    else{
        // check xem expo co ton tai hay chua
        int res=0;
        node *t=poly[id];
        while(t != NULL){
            if(t->expo==exp){
                t->coef=t->coef+coe;
                res=1;
                break;
            }
            t=t->next;
        }
        // check xem exp co phai lon nhat de xep dau linklist k
        if(poly[id]->expo<exp){
            newnode->next=poly[id];
            poly[id]=newnode;
        }
        // check be nhat
        else if(temp[id]->expo > exp){
            temp[id]->next=newnode;
            temp[id]=newnode;
        }
        // check nam giua va khong bang cacs thang expo khac
        else if(res==0){
            node *tmp1, *tmp=poly[id];
            while(tmp->expo > exp){
                tmp1=tmp;
                tmp=tmp->next;
            }
            newnode->next=tmp;
            tmp1->next=newnode;
        }
    }
}

int main(){
    for(int i=0; i<100; i++) poly[i]=NULL;
    while(1){
        char s[20];
        scanf("%s", s);
        if(strcmp(s, "*")==0) break;
        else if(strcmp(s,"Create")==0){
            int id;
            scanf("%d", &id);
            used[id]=1; // da tao poly moi
        }
        else if(strcmp(s,"AddTerm")==0){
            int id,coe,exp;
            scanf("%d %d %d",&id,&coe,&exp);
            AddTerm(id, coe, exp);
        }
        else if(strcmp(s,"EvaluatePoly")==0){
            int id,vari;
            scanf("%d %d", &id, &vari);
            if(used[id]==0) printf("0\n");
            else{
                int sum=0;
                node *t=poly[id];
                while(t!= NULL){
                    sum+=t->coef*(int)pow(vari,t->expo);
                    t=t->next;
                }
                printf("%d\n", sum);
            }
        }
        else if(strcmp(s, "AddPoly")==0){
            int id1,id2, id3;
            scanf("%d %d %d", &id1, &id2, &id3);
            if(used[id3]==0){
                used[id3]=1;
                node *tmp1, *tmp2;
                tmp1=poly[id1];
                tmp2=poly[id2];
                while(1){
                    if(tmp1==NULL && tmp2==NULL) break;
                    node *new=(node *)malloc(sizeof(node));
                    new->next=NULL;
                    if(tmp2== NULL){
                        new->expo=tmp1->expo;
                        new->coef=tmp1->coef;
                        tmp1=tmp1->next;
                    }
                    else if(tmp1==NULL){
                        new->expo=tmp2->expo;
                        new->coef=tmp2->coef;
                        tmp2=tmp2->next;
                    }
                    else if(tmp1->expo==tmp2->expo){
                        new->expo=tmp1->expo;
                        new->coef=tmp1->coef+tmp2->coef;
                        tmp1=tmp1->next;
                        tmp2=tmp2->next;
                    }

                    else if(tmp1->expo>tmp2->expo){
                        new->expo=tmp1->expo;
                        new->coef=tmp1->coef;
                        tmp1=tmp1->next;
                    }
                    else if(tmp2->expo >tmp1->expo){
                        new->expo=tmp2->expo;
                        new->coef=tmp2->coef;
                        tmp2=tmp2->next;
                    }

                    if(poly[id3]==NULL) poly[id3]=temp[id3]=new;
                    else{
                        temp[id3]->next=new;
                        temp[id3]=new;
                    }
                }
            }
        }
        else if(strcmp(s, "PrintPoly")==0){
            int id;
            scanf("%d", &id);
            node *t=poly[id];
            while(t != NULL){
                printf("%d %d ", t->coef, t->expo);
                t=t->next;
            }
            printf("\n");
        }
    }
} 