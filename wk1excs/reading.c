/*
 * reading.c
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

int main(int argc, char **argv)
{
	char const file_name[] = "data.dat"; // declare file name
	FILE* fptr; //declare file pointer, where the "cursor" is looking at the file, stream to and from the file
	
	//char FromFile[128]; //variable to hold names
	char name[16];
	unsigned int age;
	int minage,maxage,count = 0;
	double average, sum = 0;
	//unsigned int size; //holds size of input data
	int val;
	
	fptr = fopen(file_name,"r"); //open file address with file name and mode parameters, sent to file pointer, ppened in read mode
	if (fptr == NULL) // check if the file is opened properly, if not, end program
	{
		fprintf(stderr,"Error, file was not opened\n"); // stderr = standard error ( raises an error flag in the error stream, usually have error messages)
		//fprintf: write to a specific data stream, printf sends to the standard output stream
		return 1; //other than zero due to an error, terminates process and report to parent process, thus no need for else, similar to exit
	}
	printf("+---------------+-----+\n");
	/*
	fgets(FromFile,128,fptr);
	name = strtok(FromFile,"\t");
	age = strtok(NULL,"\t");
	// This takes the whole line as a string, then split string with delimiter \t to get data
	*/
	//altertively, if everything is formatted properly, can use scanf
	do{
		if ((val = fscanf(fptr,"%15s\t%3u",name,&age)) == 2) //the file might end, but EOF is not triggered 
		{ // this makes sure that if the input isn't matching, it won't print and output
			printf("|%-15s| %3u |\n",name,age);
			//printf("%d\n",val);
			fflush(fptr);
			if(count == 0)
			{
				minage = age;
				maxage = age;
			}
			else 
			{
				if (minage > age) minage = age;
				if (maxage < age) maxage = age;
			}
			sum += age;
			count ++;
		}
		//printf("\n");
	}while (!feof(fptr));
	printf("+---------------+-----+\n");
	printf("\tminimum age\t:\t%d\n",minage);
	printf("\tmaximum age\t:\t%d\n",maxage);
	average = sum/count;
	printf("%d people, average age: %lf",count,average);
	
	fclose(fptr);
	
	return 0;
}

