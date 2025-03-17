/*
 * dynamicmemory.c
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
#include <stdlib.h>

int load_arr(int * pointer, int size)
{
	for (int i= 0; i < size; i ++) pointer[i] = i;
	return size;
}

int display_arr(int* pointer, int size)
{
	printf("array elements are: \n");
	for (int i=0;i<size;i++) printf("%d ",pointer[i]);
	printf("\n");
	return size;
}

int increase_by(int* pointer, int size)
{
	int size_after, increment;
	printf("Increase size of array by :");
	scanf("%d",&increment);
	size_after =  size + increment;
	pointer = realloc(pointer, size_after*sizeof(int));
	// note the new elemets will have whatever data that was there before preallocation
	// new elements will have to be reinitialised 
	for (int i = size; i < size_after; i++) pointer[i] = i-size;
	return size_after;
}

int decrease_by(int* pointer, int size)
{
	int size_after, increment;
	printf("Decrease size of array by :");
	scanf("%d",&increment);
	size_after =  size - increment;
	pointer = realloc(pointer, size_after*sizeof(int));//changes memory size
	return size_after;
}

int assign_value(int* pointer, int size)
{
	int element, assign, tries;
	printf("Which element to assign value: ");
	scanf("%d",&element);	
	tries = 0;
	while((element < 0 || element >=size) && tries < 3)
	{
		printf("invalid value, Try again: ");
		tries ++;
		scanf("%d",&element);
	}
	if (tries< 3)
	{
		printf("Value to assign: ");
		scanf("%d",&assign);
		pointer[element] = assign;
	}
	else printf("restart\n");
	return size;
}
int display_specific(int* pointer, int size)
{
	int element, tries;
	printf("Which element to view value: ");
	scanf("%d",&element);	
	tries = 0;
	while((element < 0 || element >=size) && tries < 2)
	{
		printf("invalid value, Try again: ");
		tries ++;
		scanf("%d",&element);
	}
	if (tries< 2)
	{
		printf("Value is : %d\n",pointer[element]);
	}
	else printf("restart\n");
	return size;
}

//void change value(int* pointer)

int main(int argc, char **argv)
{
	
	int *array; //creates int pointer
	int size, operation;
	printf("Creating dynamic memory, Define size: ");
	scanf("%d", &size); //gets size of array
	
	int (*func)(int*,int);
	
	array = (int*)malloc(size* sizeof(int)); // assigns size of array
	//malloc returns a void pointer, which could then be assigned using the (type*) parameter
	if (array == NULL) printf("Memory not allocated");
	else
	{
		printf("Allocated %d elements to array\n", size);
		load_arr(array, size);
		display_arr(array, size);
		while(1)
		{
			printf("What operation do you want to do operation:\n");
			printf("1: Initialise\n2:Display\n3:Expand\n4:Contract\n5:Assign\n6:View\n");
			scanf("%d",&operation);
			if(operation == 1) func = &load_arr;
			else if (operation == 2) func = &display_arr;
			else if (operation == 3) func = &increase_by;
			else if (operation == 4) func = &decrease_by;
			else if (operation == 5) func = &assign_value;
			else if (operation == 6) func = &display_specific;
			else ;
			size = func(array,size);
		}
		
	}
	
	
	return 0;
}

