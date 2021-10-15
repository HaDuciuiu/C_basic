#include<stdio.h>
#include<string.h>
void thay_Ki_tu(char S[],char c1,char c2)
{
	int i;
	for(i=0;i<strlen(S);i++)
	{
		if(S[i]==c1)
		{
			S[i] = c2;
		}
	}
}
int main()
{
	char S[100];
	char c1,c2;
	printf("Nhap vao xau ki tu\n");
	gets(S);
	printf("Nhap vao ki tu thu nhat :\t");
	scanf("%c",&c1);
	printf("Nhap vao ki tu thu hai :\t");
	//phai co lenh getchar() de nhan vao ki tu \t di
	getchar();
	scanf("%c",&c2);
	thay_Ki_tu(S,c1,c2);
	printf("Xau sau khi thay the ki tu la: %s\n",S);
	return 0;
}

