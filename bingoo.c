#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 5
#define max 25
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 5
#define max 25
int initiate_bingo();
int print_bingo();
int one_two();
int plus;





int main(void)
{
	int same1, same2;		//�ߺ��� Ȯ�ν����� ����  
	int line[max];			//���ٷ� �켱 �迭�� ���� 
	srand(time(NULL));

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

	
	int bingo[N][N]={{0},{0}};						//1���� �迭�� 2���� �迭�� �ٲٱ� 
	
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
		
		
		
		
			
	
	
	
	return 0;
}





