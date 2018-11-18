#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 5
#define max 25
int initiate_bingo();
void print_bingo();
int one_two();
int get_number_byMe();
int get_number_byCom();
int process_bingo();
int plus;
int user_line[max];
int computer_bingo[N][N];
int user_bingo[N][N];

int initiate_bingo(int bingo[N][N])
	{
	
	int line[max]={0};
	int same1=0, same2=0;		//중복을 확인시켜줄 변수  
	srand(time(NULL));

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

	int one=0;
	int two=0;
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
			
	
	return bingo[N][N];
}
	

void print_bingo(int user_bingo[N][N],int computer_bingo[N][N])
{
	printf("<나의 빙고판>\n");
	initiate_bingo(user_bingo);
	printf("<컴퓨터의 빙고판>\n");
	initiate_bingo(computer_bingo);
	return;
}
int get_number_byMe();
int get_number_byCom();
int process_bingo();








int main(void)
{	
	int user_bingo[N][N]={{0},{0}};
	int computer_bingo[N][N]={{0},{0}};
	rand() % max + 1;
	
	printf("<나의 빙고판>\n");
	initiate_bingo(user_bingo);
	printf("<컴퓨터의 빙고판>\n");
	initiate_bingo(user_bingo);
	


	
	

	
	
	return 0;
}







