/*
 * ecriture.c
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
#define LENGTH 1024 //sets the longest lenght of name

int main(int argc, char **argv)
{// initialisations
	char const file_name[] = "data.dat"; // declare file name
	FILE* fptr; //declare file pointer
	
	char name[LENGTH+1]; //variable to hold names
	int size; //variable to hold age
	unsigned int age; //holds size of input data
	
	fptr = fopen(file_name,"w"); //open file address with file name and mode parameters, sent to file pointer
	if (fptr == NULL) // check if the file is opened properly, if not, end program
	{
		fprintf(stderr,"Error, file was not opened\n"); // stderr = standard error ( raises an error flag in the error stream, usually have error messages)
		//fprintf: write to a specific data stream, printf sends to the standard output stream
		return 1;
	}
	//else; you could put remaining program here, after passing the check, alternatively the while loop method is used
	while(!feof(stdin)) // feof checks given stream for the EOF flag, non zero if EOF is detected (ctrl+D in linux, Ctrl+z then Enter on Windows
	{
		do // varient of while loop, does operations once, then check for while conditions before going forward, use it
		{
			printf("Enter Name: ");
			fflush(stdout); // fflush : flushes the output buffer of a stream, forces write of all buffered data, ensures any data buffered in memory is written out to the output file or device.
			fgets(name, LENGTH+1,stdin); //gets next character from stream and advance position indicator of said stream. used to read input from standard input(stdin). +1 is to account for null character at the end of strings
			size= strlen(name)-1; //length of name with out null character
			if (size >=0 && name[size] == '\n') name[size]='\0'; // if end of string is "enter", replace with null character
		}while(!feof(stdin) && (size <1)); // repeat if name is invalid
		if(!feof(stdin))
		{
			printf("Enter age: ");
			fflush(stdout); // seems like habit after outputs?
			size = scanf("%u", &age);
			if (size != 1) //error handing, makes sure the entry is a single integer
			{
				printf("Invalid data, entry cancled");
				while(getc(stdin) != '\n'); // waits for enter key
			}
			else
			{
				getc(stdin); //getc reads single line entry of stream, scanf reads data type specified by parameters
				fprintf(fptr,"%s\t%d\n",name,age);
			}
		}
	}
	
	putchar('\n'); //writes character to stdout
	fclose(fptr); //always close file at end of program
	return 0;
}


			
		
	
