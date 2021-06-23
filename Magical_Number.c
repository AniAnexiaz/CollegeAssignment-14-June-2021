#include <stdio.h>

int reverse_num(long n)
{
    long long int reverse=0;
    while(n!=0)    
  {    
     int rem=n%10;    
     reverse=reverse*10+rem;    
     n/=10;    
  }   
  return reverse;
}

int no_of_digits(long n)
{
    int c=0;
    while(n>0)
    {
        n=n/10;
        c++;
        if(c>10)
        {
            return 1;
        }
    }
    return 0;
}
void dom_magical(long n)
{
    int p=0,q=0,c=1;
    while(n>0)
    {
       int num=n%10;
       if(num>0)
       {
           if(c%2==0)
           {
               if(p==0)
               {
                   p++;
               }
               
               p=p*num;
           }
           else
           {
               if(q==0)
               {
                   q++;
               }
               
               q=q*num;
           }
       }
       n=n/10;
       c++; 
    }
    if(p>=q)
    printf("Dominant");
    else
    printf("Magical");
}

int main()
{
   
    int k;
    scanf("%d",&k);
    if(k<=0)
    {
        printf("Error");
    }
    else
    {
    long long int num[k];
    for(int i=0;i<k;i++)
    {
        scanf("%lld",&num[i]);
    }
    for(int j=0;j<k;j++)
    {
        if(num[j]>0 && no_of_digits(num[j])==0)
        {
            dom_magical(reverse_num(num[j]));
        }
        else
        {
            printf("Error");
        }
    }
    return 0;
}
}
