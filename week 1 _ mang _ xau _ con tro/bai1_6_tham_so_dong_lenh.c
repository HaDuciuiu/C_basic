#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  if(argc > 3)
  {
    printf("Qua nhieu doi so!\n");
  }
  else if(argc < 2){
    printf("Thieu doi so!\n");
  }
  else {
    double cd = atof(argv[1]);
    double cr = atof(argv[2]);

    printf("S = %g, C = %g\n", cd * cr, (cd + cr) * 2);
  }
}
