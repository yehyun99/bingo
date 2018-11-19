#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 4         //N*N���� 
#define max 16      //N*N
#define LINE 10       //���� ���� ���� ���� ���� 2*N(����,����)+2(�밢��) 
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

void initiate_bingo(int bingo[N][N])      //�ݹ��̷��۷��� ����ؾ��ϳ�..? 
   {
   
   int line[max]={0};
   int same1=0, same2=0;      //�ߺ��� Ȯ�ν����� ����  


   for (same1 = 0; same1 < max; same1++)
   {
      line[same1] = rand() % max + 1;   
   }
    
   for (same1 = 0; same1 < max; same1++)      //�ߺ��� ã���ִ� �ݺ��� 
   {
      for (same2 = 0; same2 < max; same2++)      //same1�� 0�϶��� ���. 
      {
        restart:                           //goto restart�������� �ٽ� ���ƿ�. 
         if (same1 != same2)
         {
            if (line[same1] == line[same2])
            {
               line[same1] = rand() % max + 1;
               same1--;                  //�ٽ� �̾����� �ٽ� �ߺ�Ȯ��.  
               goto restart;
            }
         }
      }                                 //�ٸ��� for�� ��� ���� 
   
   }   

   int one=0;
   int two=0;
   plus=0;
      for (one=0;one<N;one++)               
      {
         for (two=0;two<N;two++)
         {
            
            
           // if(one==0)                     //�����Ҷ��� 0���� �����ؼ� N^2���� 1������ ��� 
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
   

void print_bingo(int user_bingo[N][N], int computer_bingo[N][N])         //�������̺� ���� ��Ȳ�� ȭ�鿡 ��� 
{	
	int one,two=0;
	printf("<���� ������>\n");
	for(one=0;one<N;one++)
	{
		for(two=0;two<N;two++)
			{
				printf("%3d ",user_bingo[one][two]);
			}
   	printf("\n");
	}
	printf("\n<��ǻ���� ������>\n");
	
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
      printf("����(1~n^2)�� �Է��ϼ���:");
      scanf("%d",&user_number);
      
   
   
      for(one=0;one<N;one++)            // �迭�� ���ڸ� ã�Ƽ� �� 
      {
         for(two=0;two<N;two++)
         {
            if(user_bingo[one][two]==user_number)
            {
               user_bingo[one][two]=0;
               
               plus++;               //���� plus�� �Ǹ� while�� ��������. 
            }
            if(computer_bingo[one][two]==user_number)
            {
               computer_bingo[one][two]=0;        //���� plus�� �Ǹ� while�� ��������. 
            }
         
         }
      }
      if(plus==0)
      {
            printf("�߸��� �����Դϴ�.\n");         //�Է� ���ڰ� ���� �ۿ� �ְų� �ߺ��� ��� �ٽ� �ݺ�. 
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
      for(one=0;one<N;one++)            // �迭�� ���ڸ� ã�Ƽ� �� 
      {
         for(two=0;two<N;two++)
         {
            if(user_bingo[one][two]==count)
            {   
               printf("��ǻ�ʹ� %d��(��) �����߽��ϴ�.",count);
               user_bingo[one][two]=0;
               computer_bingo[one][two]=0;
               flag++;               //���� plus�� �Ǹ� while�� ��������. 
            }
         
         }
      }
      
    } 
    return;
}
int process_bingo(int bingo[N][N], int sum[LINE], int count)         //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����Ͽ� ��ȯ 
{
   int one,two=0;         //2�� for���� ������ ���� ���� 
   count=0;           //line�� ���� �����ϱ� ���� ���� 

   for(one=0;one<LINE;one++)
   
      sum[one]=0;
   
      for(one=0;one<N;one++)
      {
      		for(two=0;two<N;two++)
         	{
            sum[one] = sum[one]+bingo[one][two];
            sum[one+N] = sum[one+N]+bingo[two][one];
         	}
        sum[LINE-1] += bingo[one][N-one-1];      //�밢�� ������ '/' ���� ã�� ��� 
        sum[LINE] += bingo[one][one];            //�밢�� ���� '\' ���� ã�� ��� 
            
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
   
   printf("<���� ������>\n");
   initiate_bingo(user_bingo);
   printf("\n\n");
   printf("<��ǻ���� ������>\n");
   initiate_bingo(computer_bingo);
   
   while(1)
   {
   
   get_number_byMe(user_bingo, computer_bingo);
   print_bingo(user_bingo, computer_bingo);

   count_u=process_bingo(user_bingo, sum, count_u);
   printf("����� ����� %d�� �Դϴ�.\n",count_u-1);		//�� �ڲ� 1�� ������... 
        if(count_u==M+1)
          break;
   count_c=process_bingo(computer_bingo, sum,count_c);
   printf("��ǻ���� ����� %d�� �Դϴ�.\n",count_c-1);
        if(count_c==M+1)
          break;
          
	printf("/n/n");
   get_number_byCom(user_bingo, computer_bingo);
   print_bingo(user_bingo,computer_bingo);
		
   count_u=process_bingo(user_bingo, sum,count_u-1);
   printf("����� ����� %d�� �Դϴ�.\n",count_u-1);
        if(count_u==M+1)
          break;
   count_c=process_bingo(computer_bingo, sum,count_c-1);
    printf("��ǻ���� ����� %d�� �Դϴ�.\n",count_c-1);
   		if(count_c==M+1)
   		  break;
   
   }
   

   
   
   return 0;
}




