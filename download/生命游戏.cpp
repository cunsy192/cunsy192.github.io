#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[101][101];
void delay(); //�ӳٺ��� 
int main()
{
	//��ʼ�� 
	for(int i = 0;i < 101;i++)
	{
		for(int j = 0;j < 101;j++)
		a[i][j] = 0;
	}
	
	//�趨��ʼ����
	printf("���뷽����У��У���\nN=");
	int N;
	scanf("%d",&N);
	printf("����ϸ������\n");
	int n;
	scanf("%d",&n);
	srand(time(NULL));
	for(int i = 0;i < n;i++)
	{
		a[rand()%11][rand()%11] = 1;
	}
	
	
	int t = 0;
	while(1)
	{
		delay(); //��ʱ
		
		for(int i = 0;i < N;i++) //������Ϸ�������� 
		{
			for(int j = 0;j < N;j++)
			{
				int k = a[i][j];
				int cnt = 0;
				if(a[i-1][j-1] == 1) cnt++;
				if(a[i-1][j] == 1) cnt++;
				if(a[i-1][j+1] == 1) cnt++;
				if(a[i][j-1] == 1) cnt++;
				if(a[i][j+1] == 1) cnt++;
				if(a[i+1][j-1] == 1) cnt++;
				if(a[i+1][j] == 1) cnt++;
				if(a[i+1][j+1] == 1) cnt++;
				if(cnt == 2) a[i][j] = k;
				if(cnt == 3) a[i][j] = 1;
				if(cnt > 3 || cnt < 2) a[i][j] = 0;
				cnt = 0;
			}
		}
		
		for(int i = 0;i < N;i++)
		{
			printf("                                                ");
			for(int j = 0;j < N;j++)
			{
				printf("%d  ",a[i][j]);
			}
			
			printf("\n\n");
		}
		delay();
		system("cls"); //�������� 
	}
	
	return 0;
}

void delay()
{
	int t = 0;
	while(t < 10000000) t++; 
	t = 0;
}
