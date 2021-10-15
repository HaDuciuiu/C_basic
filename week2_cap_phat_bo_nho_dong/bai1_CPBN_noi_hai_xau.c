#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum{MAX_LEN = 20
};
char *my_strcat(char *str1,char *str2)
{
	int len1,len2;
	char *result;
	len1 = strlen(str1);
	len2 = strlen(str2);
	result = (char *)malloc((len1 + len2 +1)*sizeof(char));
	/*kich co cua mang result phai la len1 + len2 +1 vi ham strlen() tra ve do dai cua 
	hai xau str1 va str2 ko bao gom ki tu '\0' ket thuc , vi vay khi ghep hai xau lai 
	voi nhau thi ta can them mot phan tu de chua phan tu '\0' nay*/
	if(result==NULL)
	{
		printf("Allocation failed, check memory\n");
		return NULL;
		/*NULL - con tro NULL
		'\0' - gia tri cua con tro NULL
		vi ham my_strcat nay tra ve kieu con tro nen ta return con tro NULL*/
	}
	strcpy(result,str1);// truoc tien ta copy xau str1 vao xau result
	strcpy(result + len1,str2);/*sau do ta copy xau str2 vao xau result ke tu chi 
	so len1 tro di*/
	return result;
}

int main()
{
	char s1[MAX_LEN +1],s2[MAX_LEN +1];
	char *cat_str;
	printf("Please enter two strings\n");
	scanf("%100s",s1);
	scanf("%100s",s2);
	cat_str = my_strcat(s1,s2);
	if(cat_str==NULL)
	{
		printf("Problem allocating memory\n");
		return 1;	
	}
	printf("The concatenation of %s and %s is : %s\n",s1,s2,cat_str);
	free(cat_str);//giai phong bo nho cho xau result,quan trong ko dc quen nhe
return 0;

}

