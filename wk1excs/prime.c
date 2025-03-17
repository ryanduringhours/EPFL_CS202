/*
 * prime.c
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

#include <math.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	while(1)
	{
	//initialize variables
	int n=0,primeness=0, check = 0, sqrtn = 0, largestfactor = 0;//, smallestfactor = 0;
	//input
	printf("Enter number to check for primeness:");
	scanf("%d",&n);
	
	if(n%2==0&&n!=2)
	{
		primeness = 1;
		largestfactor = 2;
	}	
	else
	{
		sqrtn = sqrt(n);
		for(check = 3; check<=sqrtn;check+=2)
		{
			if (n%check==0)
			{
				printf("%d is divisable by %d\n",n,check);
				largestfactor = check;
				primeness = 1;
			}
			else;
			printf("checked %d\n",check);
		}
	}
	if(primeness == 1) printf("%d is not a prime, it is divisable by %d\n",n,largestfactor);
	else printf("%d is probably a prime\n",n);	
}
	return 0;

}

