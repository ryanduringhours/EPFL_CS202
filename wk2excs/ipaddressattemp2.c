/*
 * ipaddressattemp2.c
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
#define NB 4 //number of neighbours
#define ND 8 //number of nodes open
typedef unsigned char byte; 
typedef unsigned char address[4];
typedef struct
{
	address *home;
	address *nb[NB];
}node;

void init_node(node * pointer);
int empty_address(address * add);
void print_address(address* entry);
void display_node(node * display);
void write_address(address * pointer, byte a,byte b,byte c,byte d);


void init_node(node * pointer)
{
	pointer-> home = (address*)malloc(sizeof(address));
	write_address(pointer -> home,0,0,0,0);
	for (int i = 0 ; i < NB ; i++)
	{
		pointer-> nb[i] = (address*) malloc(sizeof(address));
		write_address(pointer-> nb[i],0,0,0,0);
	}
	//display_node(pointer);
	//printf("Created pointer %p\n",pointer);
}

int empty_address(address * add)
{
	int check = 0, flag = 0;
	for(int j = 0; j <4; j++)
	{
		if (*add[j] == 0x00) check ++;
		else;
	}
	if (check == 4) flag = 1;
	return flag;
}

int same_address(address * add1, address * add2)
{
	int check = 0, flag = 0;
	for(int j = 0; j <4; j++)
	{
		if (*add1[j] == *add2[j]) check ++;
		else;
	}
	if (check == 4) flag = 1;
	return flag;
}

void print_address(address* entry)
{
	if (empty_address(entry)) printf("Empty");
	else
	{
		for(int i = 0; i < 4; i ++)
		{
			printf("%d",*entry[i]);
			if(i<3) printf(".");
			else;
		}
	}
}

void display_node(node * display)
{
	printf("Node Address:");
	print_address(display->home);
	for(int i = 0; i <4; i++)
	{
		printf("\nNeighbour Node %d:",i);
		print_address(display->nb[i]);
	}
	printf("\n");
}

void write_address(address * pointer, byte a,byte b,byte c,byte d)
{
	*pointer[0] = a;
	*pointer[1] = b;
	*pointer[2] = c;
	*pointer[3] = d;
}

void list_nodes(node *(*list)[ND])
{
	//display_node((*list)[1]);
	printf("DISPLAYING ALL ACTIVE NODES\n===================\n");
	for (int i = 0; i < ND; i++)
	{
		if(empty_address((*list)[i]->home));
		else
		{
		
		 display_node((*list)[i]);
		 printf("===================\n");
		}
	 }
}

int first_empty_nb(node * n1)
{
	int number = NB;
	for(int i = NB-1; i > -1 ; i --) if(empty_address(n1->nb[i])) number = i;
	return number;
}

int no_empty_nb(node* n1)
{
	int number = 0;
	for(int i = NB-1; i > -1 ; i --) if(empty_address(n1->nb[i])) number++;
	return number;
}

byte extract_byte(address * pointer,int i)
{
	byte data = *pointer[i];
	return data;
}

void write_to_neighbour(node * n1, node *n2)
{
	byte b1,b2,b3,b4;
	b1 = extract_byte(n2->home,0);
	b2 = extract_byte(n2->home,1);
	b3 = extract_byte(n2->home,2);
	b4 = extract_byte(n2->home,3);
	write_address(n1->nb[first_empty_nb(n1)],b1,b2,b3,b4);
}

void link_nodes(node * n1, node * n2)
{
	//check compatibility
	if(first_empty_nb(n1) == NB || first_empty_nb(n2) == NB || empty_address(n1->home) || empty_address(n2->home) )
	{
		printf("Nodes incompatible \n");
	}
	else
	{
		write_to_neighbour(n1,n2);
		write_to_neighbour(n2,n1);
	}
	//check compatibility
}

void common_nb(node*n1,node*n2)
{
	int count = 0;
	int flag[NB];
	//initialise array
	for(int k = 0; k < NB ; k++) flag[k] = 0;
	for(int i = 0; i <NB ; i++)
	{
		for(int j = 0; j< NB; j++)
		{
			//for each i neighbour of n1, check all j neighbours of n1
			if(same_address(n1->nb[i], n2->nb[j]))
			{
				count++;
				flag[i] = 1;
			}
		}
	}
	//display data
	printf("Node ");
	print_address(n1->home);
	printf(" and Node ");
	print_address(n2->home);
	printf(" have %d common neighbour(s)\n", count);
	if(count > 0 )
	{
		for(int l = 0; l < NB ; l++)
		{
			if (flag[l] == 1) 
			{
				print_address(n1->nb[l]);
				printf("\n");
			}
		}
	}
}


int main(int argc, char **argv)
{
	node nodes[ND];
	node *node_pointer[ND];
	for (int i = 0; i < ND; i++) 
	{
		node_pointer[i] = &nodes[i];
		init_node(node_pointer[i]);
	}
	//test node 0
	write_address(node_pointer[0]->home,192,168,1,1);
	//write_address(node_pointer[0]->nb[0],192,168,2,21);
	//write_address(node_pointer[0]->nb[1],192,168,2,22);
	//write_address(node_pointer[0]->nb[2],192,168,2,23);
	//write_address(node_pointer[0]->nb[3],192,168,2,24);
	//test node 1
	write_address(node_pointer[1]->home,192,168,1,2);
	//write_address(node_pointer[1]->nb[0],192,168,2,21);
	//write_address(node_pointer[1]->nb[1],192,168,2,22);
	//write_address(node_pointer[1]->nb[2],192,168,2,23);
	//write_address(node_pointer[1]->nb[3],192,168,2,24);
	
	//test node 2
	write_address(node_pointer[2]->home,192,168,10,1);
	
	//test node 3
	write_address(node_pointer[3]->home,192,168,10,2);
	
	//test node 4
	write_address(node_pointer[4]->home,192,168,20,2);
	//test node 5
	write_address(node_pointer[5]->home,192,168,20,1);
	
	//test node 6
	write_address(node_pointer[6]->home,192,168,1,3);
	
	

	//display_node(node_pointer[1]);
	//printf("Recieved pointer %p\n",node_pointer[1]);
	list_nodes(&node_pointer);
	
	link_nodes(node_pointer[0],node_pointer[1]);
	link_nodes(node_pointer[1],node_pointer[2]);
	link_nodes(node_pointer[2],node_pointer[3]);
	link_nodes(node_pointer[4],node_pointer[5]);
	link_nodes(node_pointer[5],node_pointer[6]);
	link_nodes(node_pointer[6],node_pointer[0]);
	link_nodes(node_pointer[2],node_pointer[6]);
	link_nodes(node_pointer[1],node_pointer[5]);
	link_nodes(node_pointer[1],node_pointer[6]);
	link_nodes(node_pointer[2],node_pointer[5]);
	
	list_nodes(&node_pointer);
	common_nb(node_pointer[1],node_pointer[0]);
	
	
	return 0;
}

