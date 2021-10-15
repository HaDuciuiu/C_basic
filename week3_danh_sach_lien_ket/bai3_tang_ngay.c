#include<stdio.h>
int main()
{
	int N;
	int i;
	int y,m,d,h,min,s,s_add;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d%d%d%d%d%d%d",&y,&m,&d,&h,&min,&s,&s_add);
		long long tong=0;
		tong=s_add+s+min*60+h*3600+d*24*3600+m*30*24*3600+y*365*24*3600;
		y=tong/(365*24*3600);
		tong=tong%(365*24*3600);
		m=tong/(30*24*3600);
		tong=tong%(30*24*3600);
		d=tong/(24*3600);
		tong=tong%(24*3600);
		h=tong/3600;
		tong=tong%3600;
		min=tong/60;
		tong=tong%60;
		s+=tong;
		if(s>60)
		{
			min++;
			printf("%d:%d:%d:%d:%d:%d\n",y,m,d,h,min,s);
		}
		else
		{
			printf("%d:%d:%d:%d:%d:%d\n",y,m,d,h,min,s);	
		}
	}
  return 0;
}

