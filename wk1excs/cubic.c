/*
 * cubic.c
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
#define PI 3.14159265358979323846

int main(int argc, char **argv)
{
	//declare variables
	double a0=0, a1=0,a2=0,q=0,r=0,d=0,z1=0,z2=0,z3=0;
	printf("Enter the 3 coefficients: ");
	scanf("%lf %lf %lf",&a2,&a1,&a0);
	printf("solving for x^3+%lfx^2+%lfx+%lf=0\n",a2,a1,a0);
	
	//solve cubic, get q and r
	q=(3*a1-pow(a2,2))/9;
	r=(9*a2*a1-27*a0-2*pow(a2,3))/54;
	d=pow(q,3)+pow(r,2);
	//printf("q=%lf, r=%lf, thus d=%lf\n",q,r,d);
	
	
	//check condition d
	if(d<0)//there are 3 real solutions
	{
		double theta=0;//, dunno=0;
		theta = acos(r/sqrt(-pow(q,3)));
		//printf("theta is %lf\n",theta);
		z1 = 2*sqrt(-q)*cos(theta/3)-(1.0/3.0)*a2;
		z2 = 2*sqrt(-q)*cos((theta+2*PI)/3)-(1.0/3.0)*a2;
		z3 = 2*sqrt(-q)*cos((theta+4*PI)/3)-(1.0/3.0)*a2;
		//dunno = (1.0/3.0)*a2;
		printf("there are 3 soluions: %lf,%lf,%lf\n",z1,z2,z3);
		//printf("checking the error%lf\n",dunno);
	}
	else
	{
		double s=0,t=0;
		s=cbrt(r+sqrt(d));
		t=cbrt(r-sqrt(d));
		//printf("check condition d=%lf and s+t=%lf\n",d,s+t);
		//printf("comparator flag %d\n",d==0.0);
		z1 = -1.0/3.0*a2+(s+t);
		if(fabs(d-0.0)< 0.0001 && (s+t)!=0.0)
		{
			z2 = -1.0/3.0*a2-0.5*(s+t);
			printf("there are 2 solutions: %f %f\n",z1,z2);
		}
		else printf("there is only 1 solution: %f",z1);	
	}
	return 0;
}

