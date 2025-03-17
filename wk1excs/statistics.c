/*
 * statistics.c
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
#define FiNaLe 64 //file name length
#define NuOfTr 5//Number of tries
typedef unsigned long int ULI;

FILE* request_file()
{// declare variables
	int tries = 0;//val;
	char file_name[FiNaLe];
	FILE* fptr; 
//retrieve file to be opened
	do
	{
		printf("Enter the file to be opened :");
		scanf("%s",file_name);
		fptr = fopen(file_name,"r");
		if (fptr == NULL)
		{
			if (tries >= NuOfTr) printf("This isn't working out\n"); 
			else fprintf(stderr,"Cannot read file with name %s\n",file_name);
			tries ++;
		}
		else printf("Successfully opened file named %s\n",file_name);
		//val=fptr;
		//printf("fptr = %d  tries : %d\n", val, tries);
	}while (fptr == NULL && tries <= NuOfTr);
	return fptr;

}

void initialise_stats(ULI statist[254])
{
	for(int i = 0; i <254; i ++) statist[i] = 0;
}

int collect_stats(ULI statist[254], FILE* fptr)
{
	int count = 0;
	char store;
	while(!feof(fptr))
	{
		store = getc(fptr);
		//printf("%c-",store);
		for(int i = 0; i <254; i ++)
		{
			if(store == i) statist[i] ++;
			else;
		}
		count++;
	}
	return count;
}

void display(ULI statist[254],int count)
{
	char character;
	double percentage;
	for(int i = 0; i <254; i ++)
		{
			if (statist[i] > 0)
			{
				character = i;
				percentage = ((1.0*statist[i])/(count*1.0))*100;
				printf("%c:%11lu - %5.2lf%%\n", character, statist[i], percentage);
			}
		}	
}


int main(int argc, char **argv)
{
	ULI statistics[254];
	ULI *address = statistics;
	initialise_stats(address);
	//printf("check if statistics is initialised:\n");
	//for(int i = 0; i <254; i ++) printf("%lu", statistics[i]);
	int length = 0;
	FILE* FiPo = request_file(); //file pointer, open file
	if (FiPo != NULL)
	{
		length = collect_stats(address,FiPo);
		printf("\nThere are a total of %d characters\n",length);
		display(address,length);
		fclose(FiPo);
	}
	else;
	return 0;
}

