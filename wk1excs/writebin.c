/*
 * writebin.c
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
#include <string.h>
#define length 50

int main(int argc, char **argv)
{
	char const file_name[] = "secret.bin"; // declare file name
	FILE* fptr; 
	fptr = fopen(file_name,"wb");
	//unsigned int buffer;
	char message[length];
	unsigned int encoded[length], temp;
	//unsigned int byte;
	//int val, square;
	if (fptr == NULL) // check if the file is opened properly, if not, end program
	{
		fprintf(stderr,"Error, file was not opened\n"); 
		return 1;
	}
	printf("Message to encode into bin file:\n");
	fgets(message,length, stdin);
	printf("Message has %ld characters\n", strlen(message));
	for(int i = 0; i < strlen(message); i ++)
	{
		temp = message[i];
		encoded[i] = pow(temp,2);
	}
	
	size_t nb_ok; //represents the size of the object
	nb_ok = fwrite(encoded,sizeof(int),strlen(message),fptr); //writes and returns size of message
	
	if (nb_ok != strlen(message)) fprintf(stderr, "Unable to write %zu elements, wrote only %zu", strlen(message),nb_ok);
	//if size of message does not correspond with what's written, something went wrong, get error message
	fclose(fptr);
	return 0;
}

