#include <stdio.h>

int main()
{
   int N,egg_count=0;
   scanf("%d",&N);
   int swan_ages[N];
   for(int i=0;i<N;i++)
   {
       scanf("%d",&swan_ages[i]);
        if(swan_ages[i]>0)
       {
       if(swan_ages[i]>=52)
       {
           egg_count=egg_count+16;
       }
       else
       {
           int rem=4-(52-swan_ages[i]);
           if(rem>0)
           {
               egg_count=egg_count+(rem*4);
           }
       }
       
     }
       
   }
   printf("%d", egg_count);

}
