#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 5         //N*N빙고 
#define max 25      //N*N
#define LINE 12       //빙고 줄을 세기 위한 라인 2*N(가로,세로)+2(대각선) 
#define M 4
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

void initiate_bingo(int bingo[N][N])      //초기 빙수 배정과 출력 
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

   int one=0;				//1차원에서 2차원 배열로 바꾸기 위한 변수 설정. 
   int two=0;
   plus=0;
      for (one=0;one<N;one++)               
      {
         for (two=0;two<N;two++)
         {
            
            bingo[one][two]=line[plus];
            
            printf("%3d ",bingo[one][two]);
            
            plus++;
         }
            printf("\n\n");
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
   	printf("\n\n");
	}
	printf("\n<컴퓨터의 빙고판>\n");
	
	for(one=0;one<N;one++)
	{
		for(two=0;two<N;two++)
			{
			printf("%3d ",computer_bingo[one][two]);
   			}
   		printf("\n\n");
	}
   

   return;
}
void get_number_byMe(int user_bingo[N][N], int computer_bingo[N][N])		//사용자가 숫자 입력하는 함수. 
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
void get_number_byCom(int user_bingo[N][N],int computer_bingo[N][N])			//컴퓨터가 숫자를 입력하는 함수. 
{
   int flag=0;
   int count,one,two=0;

   while(flag==0)
   {
      count= rand() % max + 1;
      for(one=0;one<N;one++)            // 배열속 숫자를 찾아서 비교 
      {
         for(two=0;two<N;two++)
         {
            if(user_bingo[one][two]==count)
            {   
               printf("==> 컴퓨터는 %d를(을) 선택했습니다.",count);
               user_bingo[one][two]=0;		//빙고 테이블을 수정(사용자) 
               
               flag++;               //값이 plus가 되면 while을 빠져나감.
			    
            }
            if(computer_bingo[one][two]==count)
            {
            	computer_bingo[one][two]=0;		//빙고테이블을 수정(컴퓨터) 
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
   
      sum[one]=0;			//초기화 
   
      for(one=0;one<N;one++)
      {
      		for(two=0;two<N;two++)
         	{
            sum[one] += bingo[one][two];		//0~N-1까지 세로 
            sum[one+N] += bingo[two][one];		//N~2N-1까지 가로 
         	}
        sum[LINE-2] += bingo[one][N-one-1];      //대각선 오른쪽 '/'  
        sum[LINE-1] += bingo[one][one];            //대각선 왼쪽 '\' 
            
      }
      for(one=0;one<LINE;one++)
      
         if(sum[one]==0)			//한줄이 모두 0이다. 
        
            count++;
    
      
      return count;
   }
   
int main(void)
{   
   int user_bingo[N][N]={{0},{0}};					//사용자의 빙고판 
   int computer_bingo[N][N]={{0},{0}};				//컴퓨터의 빙고판 
   int sum[LINE];									//빙고수를 세기위한 배열 
   int count_u,count_c=0;							//빙고숫자 변수 
   rand() % max + 1;
   int turn=0; 										//시도 횟수 변수 
   
   printf("<나의 빙고판>\n");
   initiate_bingo(user_bingo);						//사용자의 초기 빙고값 출력 
   printf("\n\n");
   printf("<컴퓨터의 빙고판>\n");
   initiate_bingo(computer_bingo);					//컴퓨터의 초기 빙고값 출력 
   
   while(1)		//break로 나가기 전까지 무한 반복 
   {
	get_number_byMe(user_bingo, computer_bingo);		//사용자의 숫자 입력 
		turn++;											//몇회 시도인지 세기. 
	print_bingo(user_bingo, computer_bingo);			//빙고 출력(컴퓨터,사용자 둘다) 
	count_u=process_bingo(user_bingo, sum, count_u);		//빙고수 세기. 
	printf("-> 당신의 빙고는 %d개 입니다.\n",count_u);		
	count_c=process_bingo(computer_bingo, sum,count_c);
	printf("-> 컴퓨터의 빙고는 %d개 입니다.\n",count_c);
        if(count_u==M)										//계산 후 빠져나갈 지 결정 (빙고 M개 성공시) 
			break;
        if(count_c==M)
            break;
          
	printf("\n\n");
	get_number_byCom(user_bingo, computer_bingo);		//컴퓨터의 숫자 입력 
	printf("\n\n");
	print_bingo(user_bingo,computer_bingo);				//빙고 출력 
		
	count_u=process_bingo(user_bingo, sum,count_u);		//빙고수 세기 
	printf("-> 당신의 빙고는 %d개 입니다.\n",count_u);

	count_c=process_bingo(computer_bingo, sum,count_c);
    printf("-> 컴퓨터의 빙고는 %d개 입니다.\n",count_c);
        if(count_u==M)										//계산 후 빠져나갈 지 결정 (빙고 M개 성공시) 
          break;
   		if(count_c==M)
   		  break;
   
   }
   printf("<<<< *%d번째 턴에서 승부가 났습니다* >>>>\n",turn);
   if(count_u==count_c)			//무승부 
   {
   		printf("무승부 입니다.");
   }
   else if(count_u>count_c)			//사용자 승리 
   {
   		printf("당신이 승리하였습니다:)");
   }
   else		//컴퓨터 승리 
   {
   		printf("컴퓨터가 승리하였습니다:(");
   }
   return 0;
}




