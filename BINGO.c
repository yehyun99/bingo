#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 5
#define max 25
void initiate_bingo();
int print_bingo();
int one_two();
int plus;
int user_line[max];
int computer_bingo[N][N];
int user_bingo[N][N];

void initiate_bingo(int bingo[N][N])
	{
	int line[max];
	int same1, same2;		//�ߺ��� Ȯ�ν����� ����  
	srand(time(NULL));
	int two=0;
	
	while(two<2)
	{
	
		if(two==0)
		{
			printf("<���� ������>\n");
		}
		else if(two==1)
		{
			printf("<��ǻ���� ������>\n");
		}
	for (same1 = 0; same1 < max; same1++)
	{
		line[same1] = rand() % max + 1;   
	}
	 
	for (same1 = 0; same1 < max; same1++)		//�ߺ��� ã���ִ� �ݺ��� 
	{
		for (same2 = 0; same2 < max; same2++)		//same1�� 0�϶��� ���. 
		{
		  restart:									//goto restart�������� �ٽ� ���ƿ�. 
			if (same1 != same2)
			{
				if (line[same1] == line[same2])
				{
					line[same1] = rand() % max + 1;
					same1--;						//�ٽ� �̾����� �ٽ� �ߺ�Ȯ��.  
					goto restart;
				}
			}
		}											//�ٸ��� for�� ��� ���� 
	
	}   

	

	
	int one;
	int two;
		for (one=0;one<N;one++)
		{
			for (two=0;two<N;two++)
			{
				
				
				if(one==0)							//�����Ҷ��� 0���� �����ؼ� N^2���� 1������ ��� 
				{
				int	plus=0;
				}
				bingo[one][two]=line[plus];
				
				printf("%3d ",bingo[one][two]);
				
				plus++;
			}
				printf("\n");
		}
			
		two++;
	}
	return;
}
	


int main(void)
{	
	int user_bingo[N][N]={{0},{0}};
	int computer_bingo[N][N]={{0},{0}};

	

	initiate_bingo(user_bingo);


	
	

	
	
	return 0;
}







