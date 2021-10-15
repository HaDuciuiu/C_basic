#include<stdio.h>
#include<stdlib.h>
int main(int argc , char* argv[])
{
    double width,height;
    printf("Nhap vao mot xau:\n");
    int i;
    argc=0;
    printf("nhap vao chuoi:\n");
    for(i=0;i<3;i++)
    {
    	getchar();
    	gets(*(argv+i));
		argc++;	
	}
    width = atof(argv[1]);
    height = atof(argv[2]);
    printf("chu vi cua hinh chu nhat : %lf\n",2*(width+height));
    printf("Dien tich cua hinh chu nhat la: %lf\n",width*height);
    return 0;
}
