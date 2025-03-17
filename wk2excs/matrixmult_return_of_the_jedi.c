/*
 * matrixmult.c
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
#define N 3

struct Matrix
{
	int rows;
	int coulumns;
	int *matrix;
};
/*
int GetLessThanN(){
	int entry = 0;
	scanf("%d",&entry);
	while(entry>N || entry<=0){
		printf("Out of limits, try again:");
		scanf("%d",& entry);
	}
	return entry;
}
*/
int get_index(int row, int column, int maxcol)
{
	return row*maxcol+column;
	}

void display_matrix(struct Matrix m)
{
	for(int i=0;i<m.rows;i++)
	{
		for(int j=0;j<m.coulumns;j++)
		{
			printf("%d\t",m.matrix[get_index(i,j,m.coulumns)]);
		}
	printf("\n");
	}
}



struct Matrix write_matrix(struct Matrix construct)
{
	printf("Matrix Entry\n________\n");
	int value;
	printf("Enter Rows: ");
	scanf("%d",&construct.rows);
	printf("Enter Coulumns: ");
	scanf("%d",&construct.coulumns);
	//printf("pointer NULL creating pointer\n");
	construct.matrix = (int*)malloc(construct.coulumns*construct.rows*sizeof(int));
	for(int i=0;i<construct.rows;i++)
	{
		for(int j=0;j<construct.coulumns;j++)
		{
			printf("For element [%d][%d], enter integer: ",i,j);
			scanf("%d",&value);
			construct.matrix[get_index(i,j,construct.coulumns)] = value;
		}
	}
	return construct;
}

struct Matrix multiply(struct Matrix a,struct Matrix b, struct Matrix result)
{
	while(a.coulumns!=b.rows||a.coulumns == 0)
	{
		if (b.matrix == NULL) b = write_matrix(b);
		else printf("Incompatible matrices, re enter Matrix 2\n________\n");
		//user enters matrix values
		b = write_matrix(b);
		//printf("\nMatrix 2\n________\n");
		//m2 = write_matrix(m2);
		printf("Checking compatibility of the two matrices\n");
		display_matrix(a);
		display_matrix(b);
		//compatibility check
		
	}
	printf("Matrices compatible\n");
	int sum = 0;
	result.rows = a.rows;
	result.coulumns = b.coulumns;
	if (result.matrix == NULL)
		result.matrix = (int*)malloc(result.coulumns*result.rows*sizeof(int));
	else result.matrix = realloc(result.matrix,result.coulumns*result.rows*sizeof(int));
	for(int i = 0; i < a.rows ; i++)
	{
		for(int j =0; j<b.coulumns;j++)
		{
			sum = 0;
			for(int k=0;k<a.coulumns;k++)
			{
				sum+=a.matrix[get_index(i,k,a.coulumns)]* b.matrix[get_index(k,j,b.coulumns)];
				result.matrix[get_index(i,j,result.coulumns)] = sum;
			}
		}
	}
	return result;
}

int main(int argc, char **argv)
{
	struct Matrix m1 = {0,0,NULL},m2 = {0,0,NULL},m = {0,0,NULL};//mult;
	//multiply matrices
	m1 = write_matrix(m1);
	m = multiply(m1,write_matrix(m2),m);
	display_matrix(m);
	
	free(m1.matrix);
	free(m2.matrix);
	free(m.matrix);
	return 0;
}


