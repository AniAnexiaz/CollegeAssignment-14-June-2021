#include <stdio.h>

int ValidYear(int year)
{
	if(year < 0)
		return 0;
		
    int count=0;
	int num = year;
	while(num != 0)
	{
		int dig = num % 10;
		count = count + 1;
		num = num / 10;
	}
	
	if(count != 4)
		return 0;
	else
		return 1;
}

int ValidMonth(int month)
{
    if( (month >= 1) && (month <= 12) )
	return 1;
	else
	return 0;
}

int LeapYear(int year)
{
	if(((year % 4 == 0) && (year % 100 != 0) ) || (year % 400 == 0))
	return 1;
	else
	return 0;
}

int DaysOfMonth(int month, int year)
{
	int days;
	
	if( (month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12) )
	{
	    days = 31;  	
	}
	
	if( (month == 4) || (month == 6) || (month == 9) || (month == 11) )
	{
	    days = 30;  	
	}
	
	if(month == 2)
	{
		if(LeapYear(year)==1)
			days = 29;
		else
			days = 28;
	}
	    
	 return days; 
	   
}

int main()
{
    float X,Y,Z,T,W;
    int month,year;
    scanf("%f%f%f%f%f%d%d",&X,&Y,&Z,&T,&W,&month,&year);
        if( ValidMonth(month)==0 || ValidYear(year)==0 )
        {
            printf("Error");
        }
        else if( (X==0) || (Y==0) || (Z==0) || (T==0) || (W==0) )
        {
            printf("Error");
        }
        else if( (Y < X) || (Y < Z) || (Y < T) || (Y < W) )
        {
            printf("Error");
        }
        else
        {
            float daily=X+Y+Z+T+W;
            printf("%f",daily);
            printf(" %f ",(daily*DaysOfMonth(month,year)));
            
        }
    

    return 0;
}
