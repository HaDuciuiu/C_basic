#include<stdio.h>
typedef struct point
{
	double x;
	double y;
}point_t;
typedef struct circle
{
	point_t center;
	double radius;
}circle_t;
/*
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
*/
int is_in_circle(point_t *p,circle_t *c)
{
	double x_cach,y_cach;
	x_cach = p->x - c->center.x;
	y_cach = p->y - c->center.y;
	return (x_cach*x_cach + y_cach*y_cach<=c->radius*c->radius);
}
int main()
{
	point_t p;
	circle_t c;
	printf("Nhap vao toa do diem\n");
	scanf("%lf%lf",&p.x,&p.y);
	printf("Nhap vao toa do duong tron\n");
	scanf("%lf%lf",&c.center.x,&c.center.y);
	printf("Nhap vao ban kinh duong tron\n");
	scanf("%lf",&c.radius);
	if(is_in_circle(&p,&c))
	{
		printf("Diem duoc bao boi duong tron\n");
	}
	else
	{
		printf("Diem khong duoc bao boi duong tron\n");
	}

return 0;

}

