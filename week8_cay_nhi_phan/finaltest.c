#include<stdio.h>
#include "genbintree.h"
int main(){
  int k=0,a,b,q;
  element A,B;
  FILE *ptr;
  treetype *root;
  initialize(&root);
  while(1){
    printf("\n\nChuong trinh quan ly bong da\n"
	   "1.Tao cay\n"
	   "2.Ket qua\n"
	   "3.Tim kiem\n"
	   "4.Xuong hang\n"
	   "5.Xuat file\n"
	   "6.Quit\n"
	   "Choose: ");
    scanf("%d%*c",&k);
    switch(k){
    case 1:
      makenulltree(&root);
      if((ptr=fopen("BongDa.txt","r"))==NULL){
	printf("Cannot open BongDa.txt\n");
	return 1;
      }
      while(fscanf(ptr,"%s%s%d%d%*c",A.name,B.name,&a,&b)==4){
	if(a>b){
	  A.score=3;
	  B.score=0;
	}else if(a==b){
	  A.score=1;
	  B.score=1;
	}else{
	  A.score=0;
	  B.score=3;
	}
	q=0;
	inordersearch(&q,A,root);
	if(q==0){
	  input(A,&root);
	}else{
	  inorderupdate(A,&root);
	}
	q=0;
	inordersearch(&q,B,root);
	if(q==0){
	  input(B,&root);
	}else{
	  inorderupdate(B,&root);
	}
      }
      printf("Complete!\n");
      break;
    case 2:
      inorderprint(root);
      break;
    case 3:
      printf("Input football team code: ");
      gets(A.name);
      q=0;
      inordersearch2(&q,A,root);
      if(q==0){
	printf("This team is not exist!\n");
      }
      break;
    case 4:
      printf("Input score: ");
      scanf("%d",&A.score);
      xuonghang(A,&root);
      printf("Complete!\n");
      break;
     case 5:
      if((ptr=fopen("KetQua.txt","w"))==NULL){
	printf("Cannot create KetQua.txt\n");
	return 1;
      }
      xuatfile(ptr,root);
      fclose(ptr);
      printf("Complete!\n");
      break;
    case 6:
      makenulltree(&root);
      return 0;
    }
  }
}
      
