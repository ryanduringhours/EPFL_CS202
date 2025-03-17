/*
 * complex.c
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

struct complex{
	double real;
	double imaginary;
};

struct complex getcomplex()
{
	struct complex read;
	printf("Real value:");
	scanf("%lf",&read.real);
	printf("Imaginary value:");
	scanf("%lf",&read.imaginary);
	return read;
}

struct complex subtract(struct complex a, struct complex b)
{
	struct complex sub;
	sub.real = a.real - b.real;
	sub.imaginary = a.imaginary - b.imaginary;
	return sub;
}

void display_complex(struct complex todis)
{
	printf("(%lf,%lf)",todis.real,todis.imaginary);
}

struct complex add(struct complex a, struct complex b)
{
	struct complex sum;
	sum.real = a.real+b.real;
	sum.imaginary = a.imaginary + b.imaginary;
	return sum;
}

struct complex multiply(struct complex a, struct complex b)
{
	struct complex mult;
	mult.real = a.real*b.real - a.imaginary*b.imaginary;
	mult.imaginary = a.real*b.imaginary + a.imaginary*b.real;
	return mult;

}

struct complex divide(struct complex a, struct complex b)
{
	struct complex div2;
	div.real = (a.real*b.real + a.imaginary*b.imaginary)/(b.real*b.real+b.imaginary*b.imaginary);
	div.imaginary = (a.imaginary*b.real-a.real*b.imaginary)/(b.real*b.real+b.imaginary*b.imaginary);
	return div;
}


int main(int argc, char **argv)
{
	//enter values
	struct complex c1,c2,result;
	printf("Input first complex number:\n");
	c1 = getcomplex();
	printf("Input second complex number:\n");
	c2 = getcomplex();
	//operation
	result = divide(c1,c2);
	display_complex(result);
	
	
	return 0;
}

