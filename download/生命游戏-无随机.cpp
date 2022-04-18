#include<stdio.h>
#include<stdlib.h>
int a[11][11];
void delay();
int main()
{
	for(int i = 0;i < 11;i++)
	{
		for(int j = 0;j < 11;j++)
		a[i][j] = 0;
	}
	a[2][3] = 1;
	a[4][3] = 1;
	a[4][4] = 1;
	a[4][5] = 1;
	a[3][5] = 1;
	int t = 0;
	while(1)
	{
		delay(); //ÑÓÊ±
		
		for(int i = 1;i < 11;i++)
		{
			for(int j = 1;j < 11;j++)
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
				//if(cnt > 3 || cnt < 2) a[i][j] = 0;
				cnt = 0;
			}
		}
		
		for(int i = 1;i < 11;i++)
		{
			printf("                                                ");
			for(int j = 1;j < 11;j++)
			{
				printf("%d ",a[i][j]);
			}
			
			printf("\n");
		}
		delay();
		system("cls"); //ÇåÆÁº¯Êý 
	}
	
	return 0;
}

void delay()
{
	int t = 0;
	while(t < 10000000) t++;
	t = 0;
}
