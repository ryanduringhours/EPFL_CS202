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
#define N 4

struct Matrix
{
	int rows;
	int coulumns;
	int matrix[N][N];
};

int GetLessThanN(){
	int entry = 0;
	scanf("%d",&entry);
	while(entry>N || entry<=0){
		printf("Out of limits, try again:");
		scanf("%d",& entry);
	}
	return entry;
}

void display_matrix(struct Matrix m)
{
	for(int i=0;i<m.rows;i++)
	{
		for(int j=0;j<m.coulumns;j++)
		{
			printf("%d\t",m.matrix[i][j]);
		}
	printf("\n");
	}
}

struct Matrix read_matrix(){
	struct Matrix construct = {0,0,{}};
	printf("Enter Rows: ");
	construct.rows = GetLessThanN();
	printf("Enter Coulumns: ");
	construct.coulumns = GetLessThanN();
	for(int i=0;i<construct.rows;i++)
	{
		for(int j=0;j<construct.coulumns;j++)
		{
			printf("For element [%d][%d], enter integer: ",i,j);
			scanf("%d",&construct.matrix[i][j]);
		}
	}
	return construct;
}

struct Matrix multiply(struct Matrix a,struct Matrix b){
	struct Matrix product = {a.rows,b.coulumns,{}};
	int sum = 0;
	for(int i = 0; i < a.rows ; i++)
	{
		for(int j =0; j<b.coulumns;j++)
		{
			sum = 0;
			for(int k=0;k<a.coulumns;k++)
			{
				sum+=a.matrix[i][k]*b.matrix[k][j];
				product.matrix[i][j] = sum;
			}
		}
	}
	return product;
}

int main(int argc, char **argv)
{
	struct Matrix m1 = {0,0,{}}, m2 = {0,0,{}}, result = {0,0,{}};
	int compatible = 0;
	while(compatible == 0)
	{
		//user enters matrix values
		printf("Matrix 1\n________\n");
		m1 = read_matrix();
		printf("\nMatrix 2\n________\n");
		m2 = read_matrix();
		//display_matrix(m1);
		//display_matrix(m2);
		//compatibility check
		if (m1.coulumns==m2.rows) compatible = 1;
		else printf("Incompatible matrices, try again.\n");
	}
	//multiply matrices
	result = multiply(m1,m2);
	display_matrix(result);
	
	return 0;
}


