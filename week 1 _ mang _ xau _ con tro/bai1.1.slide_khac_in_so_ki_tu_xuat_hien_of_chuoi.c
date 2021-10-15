#include<stdio.h>
#include<string.h>
void in_cac_chu_xuat_hien(char S[])
{
	char A[26];//chuoi chua cac chu cai tu a den z
	int B[26];//mang luu so lan xuat hien cua cac chu cai
	int i,j;
	/*Vong for() duoi day dung de khoi tao cac ki tu trong chuoi A la cac chu cai tu
	a den z; cac phan tu trong mang B luu so lan xuat hien cua cac chu*/
	for(i=0;i<26;i++)
	{
		A[i] = 'a'+i;//A[0]='a' cac ptu sau tang len cac chu o phia sau
		B[i] = 0;
	}
	// di so sanh cac phan tu trong chuoi S co giong cac chu cai trong mang A ko
	for(i=0;i<strlen(S);i++)
	{
		for(j=0;j<26;j++)
		{
			if(A[j] == S[i])
			{
				B[j]++;/*neu co chu nao thi bien dung luu so lan xuat hien cua chu cai
				do duoc tang len 1 don vi*/
			}
		}
	}
	/*Thao tac in , in ra cac chu co so lan xuat hien lon hon 0*/
	for(i=0;i<26;i++)
	{
		if(B[i] > 0)
		{
			printf("Chu cai %c xuat hien %d lan\n",A[i],B[i]);
		}
	}

}
int main()
{
	char S[100];
	printf("Nhap vao mot xau ki tu:\n");
	gets(S);
	in_cac_chu_xuat_hien(S);
	return 0;
}
