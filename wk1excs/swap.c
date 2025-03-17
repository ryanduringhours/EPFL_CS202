/*
 * swap.c
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

void swap(int *a, int *b) //* points to the address
{
	int temp = *a;
	*a = *b;
	*b = temp;
}// value inside the address is altered within function, without having to return values back to main
 
int main(int argc, char **argv)
{
	int i = 10;
	int j = 55;
	
	printf("Before: i=%d and j=%d\n",i,j);
	swap(&i,&j); //address of the variable is passed as parameter instead of content
	printf("After: i=%d and j=%d\n",i,j);
	return 0;
}
// used when passing large amounts of data to a fucntion without copying everything
//pass arrays and strings into functions

