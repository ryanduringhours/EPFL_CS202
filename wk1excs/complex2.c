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
#include <math.h>

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
	if (todis.real == 0) ;
	else printf("%lf",todis.real);
	
	
	if(todis.imaginary!=0&&todis.real!=0) printf("+");
	else;
	
	if(todis.imaginary == 1) printf("i");
	else if (todis.imaginary == 0);
	else if (todis.imaginary == -1) printf("-i");
	else if (todis.imaginary <0) printf("-i%lf",-todis.imaginary);
	else printf("i%lf",todis.imaginary);
	//printf("\n");
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
	struct complex div;
	div.real = (a.real*b.real + a.imaginary*b.imaginary)/(b.real*b.real+b.imaginary*b.imaginary);
	div.imaginary = (a.imaginary*b.real-a.real*b.imaginary)/(b.real*b.real+b.imaginary*b.imaginary);
	return div;
}

struct complex squareroot(struct complex a)
{
	struct complex srt;
	srt.real=sqrt((sqrt(pow(a.real,2)+pow(a.imaginary,2))+a.real)/2);
	if (a.imaginary<0) srt.imaginary = -sqrt((sqrt(pow(a.real,2)+pow(a.imaginary,2))-a.real)/2);
	else srt.imaginary = sqrt((sqrt(pow(a.real,2)+pow(a.imaginary,2))-a.real)/2);
	return srt;
}


int main(int argc, char **argv)
{
	//enter values
	struct complex c1,c2,resultpos, resultneg, r ={0,0}, q = {4,0},s = {2,0};
	//double b = 0 , c = 0;
	printf("form quadratic equation\nEnter b: ");
	c1 = getcomplex();
	printf("Enter c: ");
	c2 = getcomplex();
	printf("Equation: x^2 + ");
	display_complex(c1);
	printf("x + ");
	display_complex(c2);
	printf("\n");
	
	//printf("Input second complex number:\n");
	//c2 = getcomplex();
	//operation
	resultpos = divide(add(subtract(r,c1),squareroot(subtract(multiply(c1,c1),multiply(q,c2)))),s);
	resultneg = divide(subtract(subtract(r,c1),squareroot(subtract(multiply(c1,c1),multiply(q,c2)))),s);
	if (resultpos.real == resultneg.real && resultpos.imaginary == resultneg.imaginary)
	{
		printf("There is 1 solution: ");
		display_complex(resultpos);
	}
	else 
	{
		printf("There are 2 solutions: ");
		display_complex(resultpos);
		printf(" and ");
		display_complex(resultneg);
	}
	
	return 0;
}

