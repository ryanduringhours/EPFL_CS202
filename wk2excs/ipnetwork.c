/*
 * ipnetwork.c
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
#define N 4 //number of neighbours
typedef unsigned char byte;
void print_add(byte * address);

struct node
{
	byte add;
	byte nb[4];
}; //I give up this, i'm just gonna just an array of pointers

//allocates memory to store each address
byte* alloc_add(byte *pointer)
{
	int tempint;
	byte tempbyte;
	pointer = (byte*)malloc(4*sizeof(byte));
	for(int i = 0; i <4 ; i++)
	{
		tempint = 0x00;
		tempbyte = tempint;
		pointer[i] = tempbyte;
	}
	return pointer;
}
//manually enter address values
void write_address(byte *pointer)
{
	unsigned int tempint = 256;
	byte tempbyte;
	for(int i = 0; i<4; i++)
	{
		do
		{
		printf("%d : ",i);
		scanf("%ud", &tempint);
		if(tempint>255||tempint<0) printf("Invalid, retry\n");
		}
		while(tempint>255||tempint<0);
		tempbyte = tempint;
		pointer[i] = tempbyte;
		tempint = 256;
	}
	printf("Assigned address:");
	print_add(pointer);
}
//initialise nodes when created
struct node create_node(struct node construct)
{
	//initialise pointers to NULL
	construct.add = NULL;
	for(int j = 0;j<4;j++) construct.nb[j] = NULL;
	//ask allocate memory for address
	construct.add = alloc_add(construct.add);
	//ask to assign node address
	printf("Assign Node Address\n");
	write_address(construct.add);
	//allocate memory of 0x00 in neighbour addresses
	for(int i = 0;i<4;i++) construct.nb[i] = alloc_add(construct.nb[i]);
	return construct;
}
//checks if address is empty(all zeroes), returns 1 if so
int empty_address(byte * address)
{
	int check = 0, flag = 0;
	for(int j = 0; j <4; j++)
	{
		if (address[j] == 0x00) check ++;
		else;
	}
	if (check == 4) flag = 1;
	return flag;
}
//prints the address
void print_add(byte * address)
{
	//check for empty address
	if (empty_address(address)) printf("Empty\n");
	//if not empty, prints address to terminal
	else
	{	
		//printf("Writing to Node\n");
		for(int i = 0; i <4; i++)
		{
			printf("%d",address[i]);
			if(i<3) printf(".");
			else;
		}
		printf("\n");
	}
}
//returns number of free neighbour entrys a node has
int free_neighbours(struct node checked)
{
	int count;
	for(int i = 0; i <4; i++)
	{
		if(empty_address(checked.nb[i])) count ++;
		else;
	}
	return count;
}

//reads and displays a node
void read_node(struct node * display)
{
	printf("Node Address:");
	print_add(display->add);
	for(int i = 0; i <4; i++)
	{
		printf("Neighbour Node %d:",i);
		print_add(display->nb[i]);
	}
}
//adds n2's address to n1 neighbour list
void add_neighbour(struct node *n1, struct node *n2)
{
	//find first empty address
	printf("Adding neighbour\n");
	int first = 0, flag = 0;
	while(flag == 0 && first<3)
	{
		if (empty_address(n1->nb[first])) flag = 1;
		else;
		first++;
	}
	printf("Adding neighbour address ");
	print_add(n2->add);
	printf("To Node address ");
	print_add(n1->add);
	n1->nb[first] = n2->add;	
}
	
//exchanges details of neighbours
void link_nodes(struct node * n1, struct node * n2)
{
	//check if both nodes have a empty neighbour
	if ( free_neighbours(*n1) && free_neighbours(*n2))
	{
		printf("Both Nodes have space\n");
		add_neighbour(n1,n2);
		add_neighbour(n2,n1);		
	}
	else printf("Not compatible, operation cancled\n");
}

int main(int argc, char **argv)
{
	struct node node_list[8];
	struct node *n1,*n2;
	n1 = &node_list[1];
	n2 = &node_list[2];
	//int empty_node = 0;
	node_list[0] = create_node(node_list[0]);
	node_list[1] = create_node(node_list[1]);
	read_node(n1);
	read_node(n2);
	link_nodes(n1,n2);
	read_node(n1);
	read_node(n2); 
	

	
	
	return 0;
}

