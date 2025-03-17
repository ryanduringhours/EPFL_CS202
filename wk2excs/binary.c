/*
 * binary.c
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
#include <string.h>
typedef unsigned char byte;



void binary_print(byte hexi)
{/*
	int value = 0;
	if(hexi == '0') value = 0;
	else if(hexi == '1') value = 1;
	else if(hexi == '2') value = 2;
	else if(hexi == '3') value = 3;
	else if(hexi == '4') value = 4;
	else if(hexi == '5') value = 5;
	else if(hexi == '6') value = 6;
	else if(hexi == '7') value = 7;
	else if(hexi == '8') value = 8;
	else if(hexi == '9') value = 9;
	else if(hexi == 'a') value = 10;
	else if(hexi == 'b') value = 11;
	else if(hexi == 'c') value = 12;
	else if(hexi == 'd') value = 13;
	else if(hexi == 'e') value = 14;
	else if(hexi == 'f') value = 15;
	else value = -1;

	//convert from int to binary
	if (value == -1) printf("err!");
	else 
	{
	int b[4], div;
	b[0] = value%2;
	div = value/2;
	b[1] = div%2;
	div = div /2;
	b[2] = div %2;
	div = div / 2;
	b[3] = div % 2;
	printf("%d%d%d%d",b[3],b[2],b[1],b[0]);
	}
	return;
	*/
	int bit = 0;
	for(byte mask = 0x80; mask; mask>>=1) //size of mask, 1 byte, 8 bits, so 8 loops
	{
		bit = hexi&mask;
		//bitwise AND operation, returns full interger.
		//but functionally, 0 if the corresponding bit is 0
		//more than 1 if the correspinding bit is 1
		putchar(bit?'1':'0');
		// (condition)?(result if ture):(result if false)		
	} 
	return;
}

void display(size_t size, byte value)
{
	int number = value;
	char within_range;
	if (number <= 126 && number >= 32) within_range = 'P';
	else within_range = 'F';
	printf("%02zu : ",size);
	binary_print(value);
	printf (" %3u %c\n",number,within_range);
}

void dump_mem(byte *ptr, size_t N)
{
	printf("Starting from %p:\n", ptr);
	for (int i =0; i<N;i++)	display(i,ptr[i]);
}

int main(int argc, char **argv)
{
	int t1 = 0x50; // 80
	int t2 = -80;
	double t3 = 0.5;
	double t4 = 0.1;
	byte test = t1;
	byte *point = &test;
	//binary_print(test);
	dump_mem(point, sizeof(point));
	
	test = t2;
	dump_mem(point, sizeof(point));
	
	test = t3;
	dump_mem(point, sizeof(point));
	
	test = t4;
	dump_mem(point, sizeof(point));
	
	return 0;
}

