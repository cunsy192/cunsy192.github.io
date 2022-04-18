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
	printf("您好！请选择需要的服务：\n");
	printf("1.进入管理系统\n");
	printf("0.退出系统\n");
	printf("请选择(0-1):");
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
			
			//学生系统 
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
			
			
			//管理系统 
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
	printf("回见！\n");
	return 0;
}


int Home()
{
	system("cls");
	printf("欢迎进入谢级大学图书管理系统！\n");
	printf("请选择需要的服务：\n");
	printf("1.学生服务\n");
	printf("2.管理系统\n");
	printf("0.退出系统\n");
	printf("请选择(0-2):");
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
	printf("你好，同学！\n请选择需要进行的操作:\n");
	printf("1.查阅图书\n");
	printf("2.借阅图书\n");
	printf("3.归还图书\n");
	printf("4.显示当前图书表\n");
	printf("0.返回主界面\n");
	printf("请选择(0-4):");
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
	printf("你好，管理员！\n请选择需要进行的操作:\n");
	printf("1.插入图书\n");
	printf("2.删除图书\n");
	printf("3.显示当前图书表\n");
	printf("4.查阅图书\n");
	printf("5.图书统计信息\n");
	printf("0.返回主界面\n");
	printf("请选择(0-5):");
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
	//printf("创建成功！\n");
}

int Insert(dLinklist *head)
{
	system("cls");
	dLinklist *p = head;
	char ch[MAXSIZE];
	char bookname[MAXSIZE];
	char writer[MAXSIZE];
	dLinklist *newnode = (dLinklist *)malloc(sizeof(dLinklist));
	printf("请输入书籍编号（退出请输入*）：");
	scanf("%s",&ch);
	//printf("\n%s\n",ch);
	
	
	if(ch[0] == '*')
	{
		//printf("\nOK\n");
		return 0;
	}
	
	else
	{
		printf("请输入书籍名称：");
		scanf("%s",&bookname);
		printf("请输入书籍作者：");
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
	printf("书籍编号\t书籍名称\t书籍作者\t借阅状态");
	while(p->next != head)
	{
		p = p->next;
		printf("\n%s\t%12s\t%15s\t",p->book_number,p->book_name,p->book_writer);
		if(p->status == 1)
		printf("\t     可借阅\n");
		else
		printf("\t     已借出\n");
	}
	printf("\n\n按任意键返回\n");
	getch();
}

int Search_Home()
{
	system("cls");
	printf("1.按编号查找\n");
	printf("2.按书名查找\n");
	printf("3.按作者查找\n");
	printf("4.按借阅状态查找\n");
	printf("0.返回\n");
	printf("请选择（0-4）：");
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
	printf("请输入需要查找的书籍编号：");
	else if(k == 2)
	printf("请输入需要查找的书籍名称：");
	else if(k == 3)
	printf("请输入需要查找的作者姓名：");
	else if(k == 4)
	printf("请输入状态编码（0：已借出 1.可借阅）：");
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
				printf("书籍编号：%s\n",p->book_number);
				printf("书籍名称：%s\n",p->book_name);
				printf("书籍作者：%s\n",p->book_writer);
				if(p->status == 1) printf("借阅状态：可借阅\n");
				if(p->status == 0) printf("借阅状态：已借出\n");
				printf("\n");
				continue;
			}
			
			else if(ch[0] == p->status+48)
			{
				printf("书籍编号：%s\n",p->book_number);
				printf("书籍名称：%s\n",p->book_name);
				printf("书籍作者：%s\n",p->book_writer);
				if(p->status == 1) printf("借阅状态：可借阅\n");
				if(p->status == 0) printf("借阅状态：已借出\n");
				printf("\n");
				continue;
			}
			
		}
		
		if(i == strlen(ch) && flag == 0)
		{
			printf("书籍编号：%s\n",p->book_number);
			printf("书籍名称：%s\n",p->book_name);
			printf("书籍作者：%s\n",p->book_writer);
			if(p->status == 1) printf("借阅状态：可借阅\n");
			if(p->status == 0) printf("借阅状态：已借出\n");
			printf("\n");
		}
	}
		
	printf("\n按任意键返回\n"); 
	getch();
}

int Delete_Home()
{
	system("cls");
	printf("1.按编号删除\n");
	printf("2.按书名删除\n");
	printf("3.按作者删除\n");
	printf("0.返回\n");
	printf("请选择（0-3）：");
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
	printf("请输入需要删除的书籍编号：");
	else if(k == 2)
	printf("请输入需要删除的书籍名称：");
	else if(k == 3)
	printf("请输入需要删除的作者姓名：");
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
			printf("删除成功！\n");
			cnt++;
		}
		p = p->next;
	}
	if(cnt == 0)
	printf("删除失败，请检查拼写正确性！\n");	
	printf("\n按任意键返回\n"); 
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
	printf("共%d本图书\n",cnt_num);
	printf("共借出%d本\n",cnt_status);
	printf("\n按任意键返回\n"); 
	getch();
}


void Borrow(dLinklist *head)
{
	system("cls");
	char ch[MAXSIZE];
	printf("请输入要借阅的书籍编号：");
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
				printf("借阅成功！\n");
				getch();
				return;
			}
			else
			{
				printf("该书已被借阅！\n");
				getch();
				return;
			}
		} 
	}
	
	printf("未查询到该书籍\n");
	
	//printf("\n按任意键返回\n");
	getch();
}

void Return(dLinklist *head)
{
	system("cls");
	char ch[MAXSIZE];
	printf("请输入要归还的书籍编号：");
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
				printf("归还成功！\n");
				getch();
				return;
			}
			else
			{
				printf("该书已被归还！\n");
				getch();
				return;
			}
		} 
	}
	
	printf("未查询到该书籍\n");
	
	//printf("\n按任意键返回\n");
	getch();
}
