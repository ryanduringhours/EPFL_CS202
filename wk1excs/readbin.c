/*
 * readbin.c
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
#include <math.h>
//#define buffersize 1
int main(int argc, char **argv)
{
	char const file_name[] = "secret.bin"; // declare file name
	FILE* fptr; 
	fptr = fopen(file_name,"rb");
	unsigned int buffer;
	int val, square;
	if (fptr == NULL) // check if the file is opened properly, if not, end program
	{
		fprintf(stderr,"Error, file was not opened\n"); 
		return 1;
	}
	printf("File open successfully\n");
	while((val= fread(&buffer,sizeof(buffer),1,fptr))!= 0)
	{
		square = sqrt(buffer);
		printf("%c", square);		
	}
	
	fclose(fptr);
	return 0;
}

