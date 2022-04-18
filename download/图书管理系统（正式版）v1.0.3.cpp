#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define MAXSIZE 50

typedef struct node
{
	char book_number[MAXSIZE];
	char book_name[MAXSIZE];
	char book_writer[MAXSIZE];
	bool status;
	node *next;
}dLinklist;

int Home();
int Student();
int Admin();
void InitdList(dLinklist *&);
int Insert(dLinklist *);
void Print(dLinklist *);
int Search_Home(); 
void Search(dLinklist *,int);
int Delete_Home();
void Delete(dLinklist *,int);
void Count(dLinklist *); 
void Borrow(dLinklist *);
void Return(dLinklist *);


int main()
{
	printf("���ã���ѡ����Ҫ�ķ���\n");
	printf("1.�������ϵͳ\n");
	printf("0.�˳�ϵͳ\n");
	printf("��ѡ��(0-1):");
	int k;
	scanf("%d",&k);
	getchar();
	if(k != 0)
	{
		dLinklist *head;
		InitdList(head);
		//int k0 = Home();
		while(k != 0)
		{
			int k0 = Home();
			if(k0 == 0)
			break;
			
			//ѧ��ϵͳ 
			if(k0 == 1)
			{
				while(1)
				{
					int k1 = Student();
					if(k1 == 0)
					break;
					else if(k1 == 1)
					{
						int ks;
						while(1)
						{
							ks = Search_Home();
							if(ks == 0)
							break;
							else
							Search(head,ks);
							
						}
					}
					else if(k1 == 2)
					{
						Borrow(head);
					}
					else if(k1 == 3)
					{
						Return(head);
					}
					else if(k1 == 4)
					Print(head);
					
				}
				
			}
			
			
			//����ϵͳ 
			if(k0 == 2)
			{
				while(1)
				{
					int k2 = Admin();
					//printf("k2=%d",k2);
					
					
					if(k2 == 0)
					break;
					else if(k2 == 1)
					{
						while(Insert(head));
					}
					else if(k2 == 2)
					{
						int kd;
						while(1)
						{
							kd = Delete_Home();
							if(kd == 0)
							break;
							else
							Delete(head,kd);
						}
					}
			     	else if(k2 == 3)
			     	{
			     		Print(head);
					}
					else if(k2 == 4)
					{
						int ks;
						while(1)
						{
							ks = Search_Home();
							if(ks == 0)
							break;
							else
							Search(head,ks);
						}
					}
					else if(k2 = 5)
					{
						Count(head);
					}
				}
				
			}
			
		}
	}
	printf("�ؼ���\n");
	return 0;
}


int Home()
{
	system("cls");
	printf("��ӭ����л����ѧͼ�����ϵͳ��\n");
	printf("��ѡ����Ҫ�ķ���\n");
	printf("1.ѧ������\n");
	printf("2.����ϵͳ\n");
	printf("0.�˳�ϵͳ\n");
	printf("��ѡ��(0-2):");
	int k;
	scanf("%d",&k);
	getchar();
	if(k == 0)
	return 0;
	if(k == 1)
	return 1; 
	if(k == 2)
	return 2;
}

int Student()
{
	system("cls");
	printf("��ã�ͬѧ��\n��ѡ����Ҫ���еĲ���:\n");
	printf("1.����ͼ��\n");
	printf("2.����ͼ��\n");
	printf("3.�黹ͼ��\n");
	printf("4.��ʾ��ǰͼ���\n");
	printf("0.����������\n");
	printf("��ѡ��(0-4):");
	int k;
	scanf("%d",&k);
	getchar();
	if(k == 0)
	return 0;
	if(k == 4)
	return 4;
}

int Admin()
{
	system("cls");
	printf("��ã�����Ա��\n��ѡ����Ҫ���еĲ���:\n");
	printf("1.����ͼ��\n");
	printf("2.ɾ��ͼ��\n");
	printf("3.��ʾ��ǰͼ���\n");
	printf("4.����ͼ��\n");
	printf("5.ͼ��ͳ����Ϣ\n");
	printf("0.����������\n");
	printf("��ѡ��(0-5):");
	int k;
	scanf("%d",&k);
	getchar();
	if(k == 0)	
	return 0;
	if(k == 1)
	return 1;
	if(k == 2)
	return 2;
	if(k == 3)
	return 3;
}

void InitdList(dLinklist *&head)
{
	head = (dLinklist *)malloc(sizeof(dLinklist));
	head->next = head;
	//printf("�����ɹ���\n");
}

int Insert(dLinklist *head)
{
	system("cls");
	dLinklist *p = head;
	char ch[MAXSIZE];
	char bookname[MAXSIZE];
	char writer[MAXSIZE];
	dLinklist *newnode = (dLinklist *)malloc(sizeof(dLinklist));
	printf("�������鼮��ţ��˳�������*����");
	scanf("%s",&ch);
	//printf("\n%s\n",ch);
	
	
	if(ch[0] == '*')
	{
		//printf("\nOK\n");
		return 0;
	}
	
	else
	{
		printf("�������鼮���ƣ�");
		scanf("%s",&bookname);
		printf("�������鼮���ߣ�");
		scanf("%s",&writer);
		strcpy(newnode->book_number,ch);
		strcpy(newnode->book_name,bookname);
		strcpy(newnode->book_writer,writer);
		newnode->status = 1;
		while(p->next != head)
		p = p->next;
		p->next = newnode;
		newnode->next = head;
		return 1;
	}

}

void Print(dLinklist *head)
{
	system("cls");
	dLinklist *p = head;
	printf("�鼮���\t�鼮����\t�鼮����\t����״̬");
	while(p->next != head)
	{
		p = p->next;
		printf("\n%s\t%12s\t%15s\t",p->book_number,p->book_name,p->book_writer);
		if(p->status == 1)
		printf("\t     �ɽ���\n");
		else
		printf("\t     �ѽ��\n");
	}
	printf("\n\n�����������\n");
	getch();
}

int Search_Home()
{
	system("cls");
	printf("1.����Ų���\n");
	printf("2.����������\n");
	printf("3.�����߲���\n");
	printf("4.������״̬����\n");
	printf("0.����\n");
	printf("��ѡ��0-4����");
	int k;
	scanf("%d",&k);
	getchar();
	if(k == 0)
	return 0;
	else if(k == 1)
	return 1;
	else if(k == 2)
	return 2;
	else if(k == 3)
	return 3;
	else if(k == 4)
	return 4;
}

void Search(dLinklist *head,int k)
{
	system("cls");
	
	char ch[MAXSIZE];
	if(k == 1)
	printf("��������Ҫ���ҵ��鼮��ţ�");
	else if(k == 2)
	printf("��������Ҫ���ҵ��鼮���ƣ�");
	else if(k == 3)
	printf("��������Ҫ���ҵ�����������");
	else if(k == 4)
	printf("������״̬���루0���ѽ�� 1.�ɽ��ģ���");
	scanf("%s",&ch);
	getchar();
	
	dLinklist *p = head;
	while(p->next != head)
	{
		p = p->next;
		int i;
		int flag = 0;
		
		if(k == 1)
		{
			for(i = 0;i < strlen(ch);i++)
			{
				if(ch[i] != p->book_number[i])
				{
					flag = 1;
					break; 
				} 
			}
			
		}
		else if(k == 2)
		{
			for(i = 0;i < strlen(ch);i++)
			{
				if(ch[i] != p->book_name[i])
				{
					flag = 1;
					break; 
				} 
			}
			
		}
		
		else if(k == 3)
		{
			for(i = 0;i < strlen(ch);i++)
			{
				if(ch[i] != p->book_writer[i])
				{
					flag = 1;
					break; 
				} 
			}
			
		}
		
		else if(k == 4)
		{
			if(ch[0] = p->status+47)
			{
				printf("�鼮��ţ�%s\n",p->book_number);
				printf("�鼮���ƣ�%s\n",p->book_name);
				printf("�鼮���ߣ�%s\n",p->book_writer);
				if(p->status == 1) printf("����״̬���ɽ���\n");
				if(p->status == 0) printf("����״̬���ѽ��\n");
				printf("\n");
				continue;
			}
			
			else if(ch[0] == p->status+48)
			{
				printf("�鼮��ţ�%s\n",p->book_number);
				printf("�鼮���ƣ�%s\n",p->book_name);
				printf("�鼮���ߣ�%s\n",p->book_writer);
				if(p->status == 1) printf("����״̬���ɽ���\n");
				if(p->status == 0) printf("����״̬���ѽ��\n");
				printf("\n");
				continue;
			}
			
		}
		
		if(i == strlen(ch) && flag == 0)
		{
			printf("�鼮��ţ�%s\n",p->book_number);
			printf("�鼮���ƣ�%s\n",p->book_name);
			printf("�鼮���ߣ�%s\n",p->book_writer);
			if(p->status == 1) printf("����״̬���ɽ���\n");
			if(p->status == 0) printf("����״̬���ѽ��\n");
			printf("\n");
		}
	}
		
	printf("\n�����������\n"); 
	getch();
}

int Delete_Home()
{
	system("cls");
	printf("1.�����ɾ��\n");
	printf("2.������ɾ��\n");
	printf("3.������ɾ��\n");
	printf("0.����\n");
	printf("��ѡ��0-3����");
	int k;
	scanf("%d",&k);
	getchar();
	if(k == 0)
	return 0;
	else if(k == 1)
	return 1;
	else if(k == 2)
	return 2;
	else if(k == 3)
	return 3;
	else if(k == 4)
	return 4;
}

void Delete(dLinklist *head,int k)
{
	system("cls");
	
	char ch[MAXSIZE];
	if(k == 1)
	printf("��������Ҫɾ�����鼮��ţ�");
	else if(k == 2)
	printf("��������Ҫɾ�����鼮���ƣ�");
	else if(k == 3)
	printf("��������Ҫɾ��������������");
	scanf("%s",&ch);
	getchar();
	
	dLinklist *p = head;
	int cnt = 0;
	while(p->next != head)
	{
		int i;
		int flag = 0;
		
		if(k == 1)
		{
			for(i = 0;i < strlen(ch);i++)
			{
				if(ch[i] != p->next->book_number[i])
				{
					flag = 1;
					break; 
				} 
			}
			
		}
		else if(k == 2)
		{
			for(i = 0;i < strlen(ch);i++)
			{
				if(ch[i] != p->next->book_name[i])
				{
					flag = 1;
					break; 
				} 
			}
			
		}
		
		else if(k == 3)
		{
			for(i = 0;i < strlen(ch);i++)
			{
				if(ch[i] != p->next->book_writer[i])
				{
					flag = 1;
					break; 
				} 
			}
		}
		
		if(i == strlen(ch) && flag == 0)
		{
			dLinklist *t = p->next;
			p->next = p->next->next;
			free(t);
			printf("ɾ���ɹ���\n");
			cnt++;
		}
		p = p->next;
	}
	if(cnt == 0)
	printf("ɾ��ʧ�ܣ�����ƴд��ȷ�ԣ�\n");	
	printf("\n�����������\n"); 
	getch();
}	


void Count(dLinklist *head)
{
	system("cls");
	int cnt_num = 0;
	int cnt_status = 0;
	dLinklist *p = head;
	while(p->next != head)
	{
		p = p->next;
		cnt_num++;
		if(p->status == 0)
		cnt_status++;
	}
	printf("��%d��ͼ��\n",cnt_num);
	printf("�����%d��\n",cnt_status);
	printf("\n�����������\n"); 
	getch();
}


void Borrow(dLinklist *head)
{
	system("cls");
	char ch[MAXSIZE];
	printf("������Ҫ���ĵ��鼮��ţ�");
	scanf("%s",ch);
	getchar();
	dLinklist *p = head;
	
	while(p->next != head)
	{
		p = p->next;
		int i;
		int flag = 0;
		
		for(i = 0;i < strlen(ch);i++)
		{
			if(ch[i] != p->book_number[i])
			{
				flag = 1;
				break; 
			} 
		}
		
		if(flag == 0)
		{
			if(p->status == 1)
			{
				p->status = 0;
				printf("���ĳɹ���\n");
				getch();
				return;
			}
			else
			{
				printf("�����ѱ����ģ�\n");
				getch();
				return;
			}
		} 
	}
	
	printf("δ��ѯ�����鼮\n");
	
	//printf("\n�����������\n");
	getch();
}

void Return(dLinklist *head)
{
	system("cls");
	char ch[MAXSIZE];
	printf("������Ҫ�黹���鼮��ţ�");
	scanf("%s",ch);
	getchar();
	dLinklist *p = head;
	
	while(p->next != head)
	{
		p = p->next;
		int i;
		int flag = 0;
		
		for(i = 0;i < strlen(ch);i++)
		{
			if(ch[i] != p->book_number[i])
			{
				flag = 1;
				break; 
			} 
		}
		
		if(flag == 0)
		{
			if(p->status == 0)
			{
				p->status = 1;
				printf("�黹�ɹ���\n");
				getch();
				return;
			}
			else
			{
				printf("�����ѱ��黹��\n");
				getch();
				return;
			}
		} 
	}
	
	printf("δ��ѯ�����鼮\n");
	
	//printf("\n�����������\n");
	getch();
}
