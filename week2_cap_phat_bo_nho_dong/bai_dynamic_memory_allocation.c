#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 100};
typedef struct phone_address 
{
    char name[30];
    char tel[15];
    char email[50];
}phoneaddress;
int main()
{
    FILE *fp;
    phoneaddress *phonearr;
    int i,m,n,irc; // return code
    int reval = SUCCESS;
    printf("Nhap vao vi tri du lieu ban muon doc :(tu m den n nhe)\n");
    scanf("%d%d",&m,&n);
    fp = fopen("phonebook.txt","r");
    if (fp == NULL)
	{
		printf("Loi o buoc mo file , kiem tra lai nhe\n");
		reval = FAIL;
	}
      // Memory allocation
    int num = n-m+1;
    phonearr = (phoneaddress*)malloc(num*sizeof(struct phone_address));
    if (phonearr == NULL)
    {
        printf("cung cap bo nho that bai!\n");
        return FAIL;
    }
    if (fseek(fp,(m-1)*sizeof(phoneaddress),SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        return FAIL;
    }
    // ham fseek tra ve 0 neu thanh cong
    irc = fread(phonearr, sizeof(phoneaddress),n-m+1, fp);
    printf("Du lieu doc vao tu file la:\n");
    for (i=0; i<(n-m+1); i++)
	{
    	printf("%s-",phonearr[i].name);
    	printf("%s-",phonearr[i].tel);
    	printf("%s\n",phonearr[i].email);
    }
    // Modifying some data
    strcpy(phonearr[1].name,"Lan Hoa");
    strcpy(phonearr[1].tel,"0923456");
    strcpy(phonearr[1].email,"lovelybuffalo@hut.edu.vn");
    fseek(fp,1*sizeof(phoneaddress),SEEK_SET);
    irc = fwrite(phonearr, sizeof(phoneaddress),m-n+1,fp);
    printf(" fwrite return code = %d\n", irc);
    fclose(fp); 
    free(phonearr);
    return reval;
}
