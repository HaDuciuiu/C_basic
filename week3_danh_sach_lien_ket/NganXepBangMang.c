#include <stdio.h>

#define MAXLEN 100
static int *s;
static int N;
void STACKinit(){
s = (int *)malloc(MAXLEN*sizeof(int));
N = 0;
}
int STACKempty(){return N==0;}
void STACKpush(int item){s[N++]= item;}
int STACKpop(){return s[--N];}


int main(){
    int one[] = {1,2,3,4,5,6};
    int i;
    // Khoi tao
    STACKinit();
    // Day 6 phan tu vao ngan xep
    printf("Hien ra day cac so day vao ngan xep : \n");
    for(i=0;i<6;i++){STACKpush(one[i]);printf("%d ",one[i]);}
    printf("\n");
    // Hien ra 6 phan tu
    printf("Hien ra day cac so lay tu ngan xep : \n");
    do
    printf("%d ",STACKpop());
    while(!STACKempty()); 
    printf("\n");
    getch();
    return 0;
}
