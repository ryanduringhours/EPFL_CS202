/*
 * zune.c
 * 
 * Copyright 2025 Ryan <ryan@Galvantula>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <time.h>

int IsLeapYear(int check)
{
	int isit = 0;
	if(check%4 == 0) isit = 1;
	else;
	return isit;
}

int DaysInMonth(int month,int leap)
{
	int daysforM = 0;
	switch (month){
	case 1:
		daysforM = 31;
		break;
	case 2:
		if(leap == 0)daysforM = 28;
		else daysforM = 29;
		break;
	case 3:
		daysforM = 31;
		break;
	case 4:
		daysforM =30;
		break;
	case 5:
		daysforM = 31;
		break;
	case 6:
		daysforM = 6;
		break;
	case 7:
		daysforM = 31;
		break;
	case 8:
		daysforM = 31;
		break;
	case 9:
		daysforM = 30;
		break;
	case 10:
		daysforM = 31;
		break;
	case 11:
		daysforM=30;
		break;
	case 12:
		daysforM = 31;
		break;
	}
	return daysforM;
	}
	
		
		
int main(int argc, char **argv)
{	
	//get time in seconds
	time_t seconds;
	seconds = time(NULL);
	printf("current time in seconds%ld\n",seconds);
	// starting conditions
	int days = 0, year = 1970, hours  = 0, minutes = 0, remainder_seconds = 0;
	long int seconds_year_365 = 365*24*60*60, seconds_year_366 = 365*24*60*60;
	//if done on a leap year and we hit day 366
	while ((IsLeapYear(year)==0&&seconds>seconds_year_365)||(IsLeapYear(year)==1&&seconds>seconds_year_366)) //6) still passes initial check, infinite loop.  // solution, seperate checks depending on the year.
	{//1)pass initial check
		//printf("%d",IsLeapYear(year));
		if(IsLeapYear(year))
		{//2)pass leap year check
			if (seconds>seconds_year_366) //fail year deduction check as it should
			{
				seconds-=seconds_year_366;
				year++;
				//printf("leap year, year %d,seconds %ld\n",year,seconds);
			}
		}//4)nothing is done
		else
		{
			seconds-=seconds_year_365;
			year++;
			//printf("year increases, year %d,seconds %ld\n",year,seconds);
		}//5)nothing is done, stays 366
	}
	printf("it is year%d with %ld seconds\n",year,seconds);
	//count down for months
	days = seconds/(60*60*24);
	//printf("%d days",days);
	hours = (seconds%(60*60*24))/(60*60);
	//printf("%d hours",hours);
	minutes = ((seconds%(60*60*24))%(60*60))/60;
	//printf("%d minutes",minutes);
	remainder_seconds = ((seconds%(60*60*24))%(60*60))%60;
	//printf("%d seconds",remainder_seconds);
	
	int month = 0, days_remainder = 0;
	days_remainder = days;
	printf("%d days\n",days_remainder);
	/*int daysinmonthhere = DaysInMonth(month,0);
	printf("%d days in month %d",daysinmonthhere, month);
	*/
	while (days_remainder>DaysInMonth(month+1,IsLeapYear(year)))
	{
		days_remainder-=DaysInMonth(month+1,IsLeapYear(year));
		month++;
		//printf("%d month and %d leap year",month,IsLeapYear(year));
		//printf("%d days\n",days_remainder);
	}
	//printf("%d month",month);
	//printf("%d days",days_remainder);
	
	char number[4][3]={"th","st","nd","rd"};
	int numberth = 0;
	if(days_remainder%10 ==1 && days_remainder!=11) numberth = 1;
	else if (days_remainder%10 ==2 && days_remainder!=12)numberth= 2;
	else if (days_remainder%10 == 3 && days_remainder!=13) numberth=3;
	else;
	
	char monthname[13][10] = {"Janvier", "Fevier", "Mars", "Avril", "Mai", "Juin", " Juilliet", "Aout","Septembre","Octobre","Novembre","Decembre"};
	int monthth = 0;
	if (month ==1) monthth = 1;
	else if(month == 2)monthth = 2;
	else if(month == 3)monthth = 3;
	else if(month == 4)monthth = 4;
	else if(month == 5)monthth = 5;
	else if(month == 6)monthth = 6;
	else if(month == 7)monthth = 7;
	else if(month == 8)monthth = 8;
	else if(month == 9)monthth = 9;
	else if(month == 10)monthth = 10;
	else if(month == 11)monthth = 11;
	else if(month == 12)monthth = 12;
	
	printf("It is the %d%s of %s %d, %d:%d:%d\n",days_remainder,number[numberth], monthname[monthth], year, hours,minutes,remainder_seconds);  
	
	
	return 0;
}

