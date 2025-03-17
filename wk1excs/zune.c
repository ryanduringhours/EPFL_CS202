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

int IsLeapYear(int check)
{
	int isit = 0;
	if(check%4 == 0) isit = 1;
	else;
	return isit;
}
		
int main(int argc, char **argv)
{	
	while(1)
	{
		int days = 0, year = 1980;
		printf("Enter days: ");
		scanf("%d",&days);
		//if done on a leap year and we hit day 366
		while ((IsLeapYear(year)==0&&days>365)||(IsLeapYear(year)==1&&days>366)) //6) still passes initial check, infinite loop.  // solution, seperate checks depending on the year.
		{//1)pass initial check
			//printf("%d",IsLeapYear(year));
			if(IsLeapYear(year))
			{//2)pass leap year check
				if (days>366) //fail year deduction check as it should
				{
					days-=366;
					year++;
					printf("leap year, year %d,days %d\n",year,days);
				}
			}//4)nothing is done
			else
			{
				days-=365;
				year++;
				printf("year increases, year %d,days %d\n",year,days);
			}//5)nothing is done, stays 366
		}
		printf("it is day %d on the year %d\n",days,year);
	}
	return 0;
}

