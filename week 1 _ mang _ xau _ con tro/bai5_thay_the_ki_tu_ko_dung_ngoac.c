#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void replace_char(char *str,char c1,char c2)
{
	if(str==NULL)
	{
		return;
	}
	while(*str != '\0')
	{
		if(*str==c1)
		*str = c2;
		++str;
	}
}
int main()
{
	char str[100];
	char c1,c2;
	printf("Nhap vao chuoi ki tu :");
	gets(str);
	printf("nhap vao ki tu thu nhat :");
	scanf("%c",&c1);
	printf("Nhap vao ki tu thu hai :");
	getchar();
	scanf("%c",&c2);
	replace_char(str,c1,c2);
	printf("Chuoi sau khi thay the hai ki tu la: %s\n",str);
return 0;

}

