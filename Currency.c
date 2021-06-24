#include <stdio.h>

int main()
{
   int amt;
   printf("Enter amount:");
   scanf("%d",&amt);
   if((amt>25000) || (amt<0))
   {
       printf("Error");
   }
   else
   {
   int denomination[]={2000,500,100,50,10,5,2,1};
   int denomination_freq[10];
   
   for(int i=0;i<10;i++)
   {
       if(amt>=denomination[i])
       {
           denomination_freq[i]=amt/denomination[i];
           amt=amt%denomination[i];
       }
       else
       {
           denomination_freq[i]=0;
       }
       
   }
   for(int j=0;j<10;j++)
   {
       printf("%d ",denomination_freq[j]);
   }
   }
    return 0;
}
