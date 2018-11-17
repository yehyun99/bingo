#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 5
#define max 25

int main(void)
{
	int same1, same2;		//중복을 확인시켜줄 변수  
	int line[max];			//한줄로 우선 배열을 만듦 
	srand(time(NULL));

	for (same1 = 0; same1 < max; same1++)
	{
		line[same1] = rand() % max + 1;   
	}
	 
	for (same1 = 0; same1 < max; same1++)		//중복을 찾아주는 반복문 
	{
		for (same2 = 0; same2 < max; same2++)		//same1이 0일때는 통과. 
		{
		  restart:									//goto again을만나면 다시 돌아옴. 
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
	for (same1 = 0; same1 < max; same1++)
	{ 
		printf("%d ", line[same1]);
	} 

}


