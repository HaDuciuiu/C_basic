#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct S_Vien
{
	char id[10];
	char name[20];
	int grade;
}S_V;
typedef struct Student_t {
	S_V data;
	struct Student_t *next;
} Student;
Student *head=NULL;
Student *CreatNode(S_V data)
{
	Student *temp;
	temp = (Student*)malloc(sizeof(Student));
	temp->next=NULL;
	temp->data = data;
	return temp;	
} 
void AddTail(S_V data)
{
	Student *temp;
	temp = CreatNode(data);
	if(head==NULL)
	{
		head=temp;
		return ;
	}
	else{
		Student *p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next = temp;
	}
}
void Traverse()
{
	printf("\n");
	Student *p;
	printf("ID\t\tName\t\t\tGrade\n");
	for(p=head;p!=NULL;p=p->next)
	{
		printf("%-10s\t%-20s\t%-5d\n",p->data.id,p->data.name,p->data.grade);
	}
}
void swap(S_V *a,S_V *b)
{
	S_V temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void Sap_Xep()
{
	Student *p,*q;
	for(p=head;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data.grade < q->data.grade)
			{
				swap(&p->data,&q->data);
			}
		}	
	}
}
void Input()
{
	int i,n;
	S_V data;
	do
	{
		printf("Nhap vao so phan tu cua danh sach lien ket: ");
		scanf("%d",&n);
	}while(n<=0);
	getchar();
	for(i=0;i<n;i++)
	{
		printf("nhap vao thong tin sinh vien thu %d:\n",i+1);
		printf("Nhap id: ");
		gets(data.id);
		printf("Nhap name: ");
		gets(data.name);
		printf("Nhap grade: ");
		scanf("%d",&data.grade);
		getchar();
		AddTail(data);
	}	
}
/*
void Insert_SV(S_V data,int pos)
{
	Student *temp;
	temp = CreatNode(data);
	Student *p=head;
	int dem=1;
	while(p->next!=NULL&&dem!=pos)
	{
		p=p->next;
		dem++;
	}
	if(dem!=pos)
	{
		printf("Vi tri chen khong hop le\n");
		return;
	}
	else
	{
		printf("Vi tri chen nut moi vao danh sach : %d\n",dem);
		temp->next=p->next;
		p->next=temp;
	}
}
*/
void Search_ID(char val[])
{
	Student *p;
	for(p=head;p!=NULL;p=p->next)
	{
		if(strcmp(p->data.id,val)==0)
		{
			printf("Thong tin sinh vien tim thay la:\n");
			printf("Id\t\tName\t\t\tGrade\n");
			printf("%-10s\t%-20s\t%d\n",p->data.id,p->data.name,p->data.grade);
		}	
	}	
}
void them_dung(S_V value)
{
    Student *temp = CreatNode(value);
    Student *previous=NULL;
    Student *current = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }

    if(head->data.grade<temp->data.grade)
    {
        temp->next= head;
        head = temp;
        return;
    }
    else
    {
        previous = head;
        current = head->next;
        while(current != NULL)
        {
            if(current->data.grade < temp->data.grade)
            {
                temp->next = current;
                previous->next=temp;
                return;
            }
            previous = current;
            current = current->next;
        }
        previous->next=temp;
    } 
}
void Remove_student(char id[])
{
	Student *p;
	Student *cur=NULL;
	Student *prev=NULL;
	if(head==NULL)
	{
		printf("Empty Linked list\n");
		return;
	}
	cur = head;
	if(strcmp(cur->data.id,id)==0)
	{
		head = head->next;
		free(cur);
		return;
	}
	while(cur!=NULL&&strcmp(cur->data.id,id)!=0)
	{
		prev = cur;
		cur = cur->next;	
	}
	if(cur!=NULL)
	{
		prev->next = cur->next;
		free(cur);	
	}	
}
void Change_grade(char id_t[],int newGrade)
{
	S_V value;
	strcpy(value.id,id_t);
	value.grade = newGrade;
	Student *p;
	for(p=head;p!=NULL;p=p->next)
	{
		if(strcmp(p->data.id,id_t)==0)
		{
			strcpy(value.name,p->data.name);
			break;
		}
	}
	if(head==NULL)
	{
		printf("Empty linked list\n");
		return;
	}
	Remove_student(id_t);
	them_dung(value);
}
int main()
{
	printf("=====Tao mot danh sach lien ket==============\n");
	Input();
	printf("Danh sach nhap vao:\n");
	Traverse();
	printf("Sap xep diem sinh vien theo thu tu giam dan:\n");
	Sap_Xep();
	Traverse();
	printf("Them sinh vien vao danh sach lien ket:\n");
	printf("Nhap vao thong tin sinh vien muon them:\n");
	S_V val;
	int pos;
	printf("ID: ");
	gets(val.id);
	printf("Name: ");
	gets(val.name);
	printf("grade: ");
	scanf("%d",&val.grade);
	them_dung(val);
	Traverse();
	char ID[10];
	printf("Nhap vao id cua sinh vien can tim kiem: ");
	getchar();
	gets(ID);
	Search_ID(ID);
	char id_x[10];
	printf("Nhap vao id sinh vien ban muon xoa: ");
	gets(id_x);
	Remove_student(id_x);
	printf("Danh sach sinh vien sau khi xoa :\n");
	Traverse();
	Student *to_free;
	char id_change[10];
	int newGrade;
	printf("Nhap vao id muon thay doi diem: ");
	gets(id_change);
	printf("Nhap vao diem moi muon thay doi : ");
	scanf("%d",&newGrade);
	Change_grade(id_change,newGrade);
	Traverse();
	while(to_free!=NULL)
	{
		head = head->next;
		free(to_free);
		to_free = head;
	}
	
  return 0;
}

