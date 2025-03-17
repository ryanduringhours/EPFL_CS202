/*
 * excs1.c
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

int main(int argc, char **argv)
{
	double const g = 9.81;
	double h0 = -1, h = 0, h1 = 0, eps = 2, v = 0, v1 = 0;
	int nbr = -1;
	//get initial ball height
	printf("Enter the initial height of the ball:");
	while(h0<0)
	{
		scanf("%lf",&h0);
		if (h0<0)
		{
			printf("invalid entry, must be more than zero \n");
			printf("Enter the initial height of the ball:");
		}
		else;
	}
	//get number of bounces
	printf("Enter the number of bounces:");
	while(nbr<0)
	{
		scanf("%d",&nbr);
		if (nbr<0)
		{
			printf("invalid entry, must be more than zero \n");
			printf("Enter the number of bounces to calculate:");
		}
		else;
	}
	//get rebound coefficient
	printf("Enter the rebound cooefficient:");
	while(eps<0||eps>1)
	{
		scanf("%lf",&eps);
		if (eps<0||eps>1)
		{
			printf("invalid entry, must be between 0 and 1 \n");
			printf("Enter the rebound cooefficient:");
		}
		else;
	}
	printf("ball dropped from %lfm and bounces %d times with rebound cooefficient %lf\n",h0,nbr,eps);
	
	h = h0;
	for(int i = 0; i < nbr; i++)
	{
		//parameters obtain, start calculation
		v = sqrt(h*2*g);
		//printf("velocity before hitting the ground %lf",v);
		v1 = eps*v;
		//printf("velocity after bounce %lf",v1);
		h1 = pow(v1,2)/(2*g);
		//printf("height after bounce %lf", h1);
		h = h1;
	}
	
	printf("the height after %d bounces is %lf",nbr,h1);

	

	
	return 0;
}



