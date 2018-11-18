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

int initiate_bingo(int bingo[N][N])		//�ݹ��̷��۷��� ����ؾ��ϳ�..? 
	{
	
	int line[max]={0};
	int same1=0, same2=0;		//�ߺ��� Ȯ�ν����� ����  
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

	int one=0;
	int two=0;
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
			
	
	return bingo[N][N];
}
	

void print_bingo(int bingo[N][N])			//�������̺� ���� ��Ȳ�� ȭ�鿡 ��� 
{
	printf("<���� ������>\n");
	initiate_bingo(bingo);

	return;
}
int get_number_byMe(int bingo[N][N])
{
	int user_number;
	int plus=0;
	int one,two; 
	
	while(plus!=1)
	{
		printf("����(1~n^2)�� �Է��ϼ���:");
		scanf("%d",&user_number);
		
	
	
		for(one=0;one<N;one++)				// �迭�� ���ڸ� ã�Ƽ� �� 
		{
			for(two=0;two<N;two++)
			{
				if(bingo[one][two]==user_number)
				{
					bingo[one][two]=-1;
					plus++;					//���� plus�� �Ǹ� while�� ��������. 
				}
			
			}
		}
		if(plus==0)
		{
				printf("�߸��� �����Դϴ�.\n����(1~n^2)�� �ٽ� �Է��ϼ���:");			//�Է� ���ڰ� ���� �ۿ� �ְų� �ߺ��� ��� �ٽ� �ݺ�. 
				scanf("%d",&user_number);
		}
	}
	return;
}
int get_number_byCom();
int process_bingo(int bingo[N][N])			//���� ���̺��� ä�� ����/����/�밢�� �� ���� ����Ͽ� ��ȯ 
{
	int flag_v=0;			//���ι��� ���� ã�� ��� 
	int flag_h=0;			//���ι��� ���� ã�� ��� 
	int flag_cl=0;			//�밢�� ������ '/' ���� ã�� ��� 
	int flag_cr=0;			//�밢�� ���� '\' ���� ã�� ��� 
	
	
} 






int main(void)
{	
	int user_bingo[N][N]={{0},{0}};
	int computer_bingo[N][N]={{0},{0}};
	rand() % max + 1;
	
	printf("<���� ������>\n");
	initiate_bingo(user_bingo);
	get_number_byMe(user_bingo);
	print_bingo(user_bingo);


	
	

	
	
	return 0;
}







