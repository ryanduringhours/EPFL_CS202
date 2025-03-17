/*
 * integral.c
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

struct limits{
	double a;
	double b;
	int choice;
};

struct limits enterlimits()
{
	struct limits retrieve;
	printf("pick which function to integrate:\n(1)f(x)=x^2\t(2)f(x)=x^3\tf(x)=sinx\t(4)f(x)=1/x\n");
	scanf("%d",&retrieve.choice);
	printf("Enter parameters a and b: ");
	scanf("%lf %lf",&retrieve.a,&retrieve.b);
	return retrieve;
}

double func(double x,int option)
{
	double f = 0; 	
	switch(option)
	{
	case 1:
		scanf("function is x^2");
		f = pow(x,2);
		break;
	case 2:
		scanf("function is x^3");
		f = pow(x,3);
		break;
	case 3:
		scanf("function is sinx");
		f = sin(x);
		break;
	case 4:
		scanf("function is 1/x");
		f = pow(x,-1);
		break;
	}
	return f;
}

double integrate(struct limits input)
{
 double output = 0, a = input.a, b = input.b, c = input.choice;
 output = (b-a)/840.0*(41*func(a,c)+216*func((5*a+b)/6.0,c)+27*func((2*a+b)/3.0,c)+272*func((a+b)/2.0,c)+27*func((a+b*2)/3.0,c)+216*func((a+b*5)/6.0,c)+41*func(b,c));
 return output;
}

int main(int argc, char **argv)
{
	double sum;
	struct limits value = {0,0};
	value = enterlimits();
	printf("Parameters are as follows, a = %lf, b = %lf\n", value.a,value.b);
	sum = integrate(value);
	printf("The integral sum is %lf",sum);	
	return 0;
}



