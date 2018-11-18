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
	int same1, same2;		//중복을 확인시켜줄 변수  
	srand(time(NULL));
	int two=0;
	
	while(two<2)
	{
	
		if(two==0)
		{
			printf("<나의 빙고판>\n");
		}
		else if(two==1)
		{
			printf("<컴퓨터의 빙고판>\n");
		}
	for (same1 = 0; same1 < max; same1++)
	{
		line[same1] = rand() % max + 1;   
	}
	 
	for (same1 = 0; same1 < max; same1++)		//중복을 찾아주는 반복문 
	{
		for (same2 = 0; same2 < max; same2++)		//same1이 0일때는 통과. 
		{
		  restart:									//goto restart을만나면 다시 돌아옴. 
			if (same1 != same2)
			{
				if (line[same1] == line[same2])
				{
					line[same1] = rand() % max + 1;
					same1--;						//다시 뽑았으니 다시 중복확인.  
					goto restart;
				}
			}
		}											//다르면 for문 계속 진행 
	
	}   

	

	
	int one;
	int two;
		for (one=0;one<N;one++)
		{
			for (two=0;two<N;two++)
			{
				
				
				if(one==0)							//시작할때만 0으로 시작해서 N^2까지 1차원을 명시 
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







