#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 5
#define max 25

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
		  restart:									//goto again�������� �ٽ� ���ƿ�. 
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
	for (same1 = 0; same1 < max; same1++)
	{ 
		printf("%d ", line[same1]);
	} 

}


