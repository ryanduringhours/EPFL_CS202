/*
 * untitled.c
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

void write_gender(int gender)
{
	if(gender == 1) printf("Mr.")  ;
	else if (gender == 1) printf("Ms.");
}

void write_subject(int subject)
{
	if (subject == 1) printf("your course");
	else if(subject == 2) printf("your meeting request");
}

void write_polite(int polite)
{
	if (polite == 1) printf("Kind regards");
	else if (polite == 2) printf("Sincerely");
}
void generate_letter(int gender, char* recipient, int subject, int *date, int polite, char* author)
{
	
	printf("Dear ");
	write_gender(gender);
	printf(" %s\n",recipient);
	printf("I am writing to you regarding ");
	write_subject(subject);
	printf("\nWe should see each other on %d/%d to discuss it\n", date[0],date[1]);
	printf("Let me know!\n");
	write_polite(polite);
	printf(", %s\n", author);
}



int main(int argc, char **argv)
{
	char name1[] = "Mireille";
	char name2[] = "John";
	int date1[2] = {12,18};
	int date2[2] = {12,16};
	
	
	//name person1;
	//person1.text = &name1;
	//person2.text = strlen(name1);
	
	generate_letter(2,name1,1,date1,1,name2);
	printf("==========================\n");
	generate_letter(1,name2,2,date2,2,name1);
	return 0;
}

