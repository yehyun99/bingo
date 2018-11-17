#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main(void) 
{ 
int num[10]; 
int i=0, j,a=0; 
srand((int)time(NULL)); 
while(i<10) 
{	
num[i]=rand()%10; 

while(1) 
{ 
for(j=0 ; j<i ;j++) 
{ 
while(num[i]==num[j]) 
num[i]=rand()%10;	
} 
for(j=0 ; j<i ; j++) 
{ 
if(num[i] != num[j]) 
a++;	
}	
if(a==(i)) 
break; 

a=0;	
} 
i++; 
}	

for(i=0 ; i<10 ; i++) 
{ 
printf("%d!", num[i]); 
}	
return 0;	
}
