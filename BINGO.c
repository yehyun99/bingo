#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
   int max=N*N;
   int same1=0, same2=0,k=0;         //중복되는 것을 없애줄 변수  
   int line[N*N]={0};
   
	srand((int)time(NULL)); 
   
	while(same1<max)
	{
		line[same1]=rand()%max;		//난수 뽑기 
		if (same1==0)
		continue;
		
		while(1)						//break까지 무한 루프 
		{
			for(same2=0;same2<same1;same2++)		//같은지 확 인 
			{
				while(line[same1]==line[same2]){	//같으면 다시 뽑는다. 
				line[same1]=rand()%max;
				}
			}
			for(same2=0;same2<same1;same2++)		//이전 숫자들과 겹치는지 확인 
			{
				if(line[same1]!=line[same2])
				k++;
				 
			}
			if(k==(same1)){			//
			break;
			}
			k==0;
		}
		
		same1++;
	}
	
	for(same1=0;same1<max;same1++)
	{
		printf("%d ",line[same1]);
	}
   
  printf("lol");
   
   return 0;
}
