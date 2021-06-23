#include <stdio.h>


struct date
{
	int years;
	int months;
	int days;
};

int days_on_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; 

int days_date(struct date s)     
{
	int sum=0;                      
	for (int i = 1; i < s.years; i++)      
	{
		if (s.years % 4 == 0 && s.years % 100 != 0 || s.years % 400 == 0)   
			sum += 366;
		else sum += 365;
	}

	for (int k = 1; k < s.months; k++)    
		sum += days_on_month[k];

	return sum+s.days;      
}

int diff(struct date s1, struct date s2)
{
	return days_date(s2)-days_date(s1);
}

int isPrime(int n)
{
    int i;

    if(n == 1)
        return 0;

    for(i=2;i*i<=n;i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
	struct date s1, s2;
	printf("Enter birthday (dd-mm-yyyy):\n");
	scanf("%d%d%d",&s1.days,&s1.months,&s1.years);
	printf("Enter Current date (dd-mm-yyyy):\n");
	scanf("%d%d%d", &s2.days,&s2.months,&s2.years );
	int diff_in_days=diff(s1,s2);

	int weeks=diff_in_days/7;
	
	int sum_of_primes=0,sum_of_nonprimes=0;
	int a=0,b=0;
	
	for(int i=2;i*i<=weeks;i++)
    {

        if(weeks%i == 0)
        {
            if(weeks/i == i)
            {
                a = i;
                if(isPrime(a)==1) 
                {
                    sum_of_primes+=a;
                    printf("%d",sum_of_primes);
                }
                else
                {
                    sum_of_nonprimes+=a;
                }
            }
            else
            {
                a = i;
                b = weeks/i;

                 if(isPrime(a)==1) 
                {
                    sum_of_primes+=a;
                }
                else
                {
                    sum_of_nonprimes+=a;
                }
                 if(isPrime(b)==1) 
                {
                    sum_of_primes+=b;
                }
                else
                {
                    sum_of_nonprimes+=b;
                }

            }
        }
    }
    printf("Sum of primes:%d\n ",sum_of_primes);
    printf(" sum of non primes:%d\n ",sum_of_nonprimes);
    if(sum_of_primes>sum_of_nonprimes)
	{
	    printf("Grant");
	}
	else
	{
	    printf("Not Grant");
	}
	
	return 0;
}
