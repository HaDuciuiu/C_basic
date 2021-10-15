#include<stdio.h>
#include<string.h>
#include "stacklist.h"
#include <math.h>
#include <ctype.h>
#define MAX 100
int priority(char c){
  if(c=='^') return 3;
  else
    if(c=='*'||c=='/') return 2;
    else
      if(c=='+'||c=='-') return 1;
      else return 0;
}
int isoperator(char c){
  if(c=='^'|| c=='+'||c=='-'||c=='*'||c=='/') return 1;
  else return 0;
}
int compare(char c1, char c2){
  if(priority(c1)> priority(c2)) return 1;
  if(priority(c1)<= priority(c2)) return 0;
}
char *intopost(char s1[]){
  int i=0,j=0;
  char s2[MAX],c,*s3;
  s3=(char*)malloc((MAX+1) * sizeof(char));
  stacktype *r=NULL;
  push(&r,'(');
  strcat(s1,")");
  while(s1[i]!='\0'){
    if(s1[i]=='('){
      push(&r,s1[i]);
      printf("%c\n",s1[i]);
    }
    if(isdigit(s1[i]) || isalpha(s1[i])){
      s2[j]=s1[i];
      j++;
    } 
    if(isoperator(s1[i])==1){
      if(compare(s1[i],peek(r))==1){
	push(&r,s1[i]);
      } else{
	while(compare(s1[i],peek(r))==0){
	  s2[j]=pop(&r);
	  j++;
	}
	push(&r,s1[i]);
      }
    }
    if(s1[i]==')'){
      for(c=pop(&r);c!='(';c=pop(&r)){
	s2[j]=c;
	j++;
      }
    }
    i++;
  }
  s2[j]='\0';
  strcpy(s3,s2);
  return s3; 
}
int calculate(char s[]){
  int i=0,x1,x2;
  stacktype *r=NULL;
  while(s[i]!='\0'){
    if(isdigit(s[i])||isalpha(s[i])){
      push(&r,s[i]-'0');
    }
    if(isoperator(s[i])){
      x1=pop(&r);
      x2=pop(&r);
      switch(s[i]){
      case '+':
	push(&r,x1+x2);
	break;
      case '-':push(&r,x2-x1); break;
      case '*':push(&r,x1*x2);break;
      case '/':
	if((x2%x1)!=0) {
	  return -99999;
	}
	push(&r,x2/x1);
	break;
      case '^':push(&r,pow(x2,x1)); break;
      }
    }
    i++;
  }
  return pop(&r);
}
int main(){
  int x;
  char s1[100],s2[100],*s3;
  do{
    printf("***************INFIX AND POSTFIX***************\n");
    printf("1. Enter arithmetic expression in infix notation(1-9)\n");
    printf("2. Change to postfix form\n");
    printf("3. Calculating value\n");
    printf("4. exit\n");
    printf("your choice? ");
    scanf("%d", &x);
    switch(x){
    case 1:
      printf("Enter expression: ");
      scanf("%s",s1);
      printf("Done!\n");
      break;
    case 2:
      s3=intopost(s1);
      printf("Done!\n");
      printf("postfix form: %s\n",s3);
      break;
    case 3:
      /*if(calculate(s3)==-99999){
	printf("expression is wrong.\n");
      }else{
	printf("value is: %d\n",calculate(s3));
	}*/
      printf("value is: %d\n",calculate(s3));
      break;
    default: break;
    }
  }while(x!=4);
  return 0;
}
