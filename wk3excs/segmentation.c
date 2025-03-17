/*
 * segmentation.c
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
#include <string.h>
int nextToken(char const * str, size_t*from, size_t*len)
{
	int isword=0,endword=0,cursor = *from, endofline = 0;
	while ((isword == 0 || endword == 0 ) && cursor !=  *len)
	{	
		printf("starting from %ld of %ld\n",*from, *len);
		printf("checking char[%d]",cursor);
		if(endword == 0) //if end of word not detect, check if it still a word
		{
			if ((str[cursor] != ' ' || str[cursor]!='.') && isword == 0)
			{
				printf("start of word\n");
				isword = 1;
			}
			else if(isword == 1 && (str[cursor] == ' ' || str[cursor]=='.'))
			{
				printf("\nend of word \n");
				endword = 1;
			}
			else if (isword == 1) printf("%c",str[cursor]);
		}
		cursor ++;		
	}
	return endofline;
		
}

int main(int argc, char **argv)
{
	size_t from = 0, len = 0;
	size_t * from_ptr, *len_ptr;
	from_ptr = &from;
	len_ptr = &len;
	char const test_string[] = "This is a sentence to test for.";
	len = strlen(test_string);
	nextToken(test_string, from_ptr,len_ptr);
	
	
	
	return 0;
}

