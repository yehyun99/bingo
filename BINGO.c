#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
   int max=N*N;
   int same1=0, same2=0,k=0;         //�ߺ��Ǵ� ���� ������ ����  
   int line[N*N]={0};
   
	srand((int)time(NULL)); 
   
	while(same1<max)
	{
		line[same1]=rand()%max;		//���� �̱� 
		if (same1==0)
		continue;
		
		while(1)						//break���� ���� ���� 
		{
			for(same2=0;same2<same1;same2++)		//������ Ȯ �� 
			{
				while(line[same1]==line[same2]){	//������ �ٽ� �̴´�. 
				line[same1]=rand()%max;
				}
			}
			for(same2=0;same2<same1;same2++)		//���� ���ڵ�� ��ġ���� Ȯ�� 
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
