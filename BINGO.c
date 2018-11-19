#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 4         //N*N빙고 
#define max 16      //N*N
#define LINE 10       //빙고 줄을 세기 위한 라인 2*N(가로,세로)+2(대각선) 
#define M 3
void initiate_bingo();
void print_bingo();
int one_two();
void get_number_byMe();
void get_number_byCom();
int process_bingo();
int plus;
int user_line[max];
int computer_bingo[N][N];
int user_bingo[N][N];

void initiate_bingo(int bingo[N][N])      //콜바이레퍼런스 사용해야하나..? 
   {
   
   int line[max]={0};
   int same1=0, same2=0;      //중복을 확인시켜줄 변수  


   for (same1 = 0; same1 < max; same1++)
   {
      line[same1] = rand() % max + 1;   
   }
    
   for (same1 = 0; same1 < max; same1++)      //중복을 찾아주는 반복문 
   {
      for (same2 = 0; same2 < max; same2++)      //same1이 0일때는 통과. 
      {
        restart:                           //goto restart을만나면 다시 돌아옴. 
         if (same1 != same2)
         {
            if (line[same1] == line[same2])
            {
               line[same1] = rand() % max + 1;
               same1--;                  //다시 뽑았으니 다시 중복확인.  
               goto restart;
            }
         }
      }                                 //다르면 for문 계속 진행 
   
   }   

   int one=0;
   int two=0;
   plus=0;
      for (one=0;one<N;one++)               
      {
         for (two=0;two<N;two++)
         {
            
            
           // if(one==0)                     //시작할때만 0으로 시작해서 N^2까지 1차원을 명시 
            //{
            //int   plus=0;
            //}
            bingo[one][two]=line[plus];
            
            printf("%3d ",bingo[one][two]);
            
            plus++;
         }
            printf("\n");
      }
         
   
   return ;
}
   

void print_bingo(int user_bingo[N][N], int computer_bingo[N][N])         //빙고테이블 현재 상황을 화면에 출력 
{	
	int one,two=0;
	printf("<나의 빙고판>\n");
	for(one=0;one<N;one++)
	{
		for(two=0;two<N;two++)
			{
				printf("%3d ",user_bingo[one][two]);
			}
   	printf("\n");
	}
	printf("\n<컴퓨터의 빙고판>\n");
	
	for(one=0;one<N;one++)
	{
		for(two=0;two<N;two++)
			{
			printf("%3d",computer_bingo[one][two]);
   			}
   		printf("\n");
	}
   

   return;
}
void get_number_byMe(int user_bingo[N][N], int computer_bingo[N][N])
{
   int user_number;
   plus=0;
   int one,two; 
   printf("\n\n");
   while(plus!=1)
   {
      printf("숫자(1~n^2)를 입력하세요:");
      scanf("%d",&user_number);
      
   
   
      for(one=0;one<N;one++)            // 배열속 숫자를 찾아서 비교 
      {
         for(two=0;two<N;two++)
         {
            if(user_bingo[one][two]==user_number)
            {
               user_bingo[one][two]=0;
               
               plus++;               //값이 plus가 되면 while을 빠져나감. 
            }
            if(computer_bingo[one][two]==user_number)
            {
               computer_bingo[one][two]=0;        //값이 plus가 되면 while을 빠져나감. 
            }
         
         }
      }
      if(plus==0)
      {
            printf("잘못된 숫자입니다.\n");         //입력 숫자가 범위 밖에 있거나 중복된 경우 다시 반복. 
      }
   }
   return;
}
void get_number_byCom(int user_bingo[N][N],int computer_bingo[N][N])
{
   int flag=0;
   int count,one,two=0;

   while(flag!=0)
   {
      count= rand() % max + 1;
      for(one=0;one<N;one++)            // 배열속 숫자를 찾아서 비교 
      {
         for(two=0;two<N;two++)
         {
            if(user_bingo[one][two]==count)
            {   
               printf("컴퓨터는 %d를(을) 선택했습니다.",count);
               user_bingo[one][two]=0;
               computer_bingo[one][two]=0;
               flag++;               //값이 plus가 되면 while을 빠져나감. 
            }
         
         }
      }
      
    } 
    return;
}
int process_bingo(int bingo[N][N], int sum[LINE], int count)         //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산하여 반환 
{
   int one,two=0;         //2중 for문을 돌리기 위한 변수 
   count=0;           //line의 값을 지정하기 위한 변수 

   for(one=0;one<LINE;one++)
   
      sum[one]=0;
   
      for(one=0;one<N;one++)
      {
      		for(two=0;two<N;two++)
         	{
            sum[one] = sum[one]+bingo[one][two];
            sum[one+N] = sum[one+N]+bingo[two][one];
         	}
        sum[LINE-1] += bingo[one][N-one-1];      //대각선 오른쪽 '/' 빙고를 찾는 깃발 
        sum[LINE] += bingo[one][one];            //대각선 왼쪽 '\' 빙고를 찾는 깃발 
            
      }
      for(one=0;one<LINE;one++)
      
         if(sum[one]==0)
        
            count++;
    
      
      return count;
   }
   
   



int main(void)
{   
   int user_bingo[N][N]={{0},{0}};
   int computer_bingo[N][N]={{0},{0}};
   int sum[LINE];
   int count_u,count_c=0;
   rand() % max + 1;
   
   printf("<나의 빙고판>\n");
   initiate_bingo(user_bingo);
   printf("\n\n");
   printf("<컴퓨터의 빙고판>\n");
   initiate_bingo(computer_bingo);
   
   while(1)
   {
   
   get_number_byMe(user_bingo, computer_bingo);
   print_bingo(user_bingo, computer_bingo);

   count_u=process_bingo(user_bingo, sum, count_u);
   printf("당신의 빙고는 %d개 입니다.\n",count_u-1);		//왜 자꾸 1이 나오지... 
        if(count_u==M+1)
          break;
   count_c=process_bingo(computer_bingo, sum,count_c);
   printf("컴퓨터의 빙고는 %d개 입니다.\n",count_c-1);
        if(count_c==M+1)
          break;
          
	printf("/n/n");
   get_number_byCom(user_bingo, computer_bingo);
   print_bingo(user_bingo,computer_bingo);
		
   count_u=process_bingo(user_bingo, sum,count_u-1);
   printf("당신의 빙고는 %d개 입니다.\n",count_u-1);
        if(count_u==M+1)
          break;
   count_c=process_bingo(computer_bingo, sum,count_c-1);
    printf("컴퓨터의 빙고는 %d개 입니다.\n",count_c-1);
   		if(count_c==M+1)
   		  break;
   
   }
   

   
   
   return 0;
}




