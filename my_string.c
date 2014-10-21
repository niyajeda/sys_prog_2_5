/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014  Niklas Beck <s6nnbeck@uni-bonn.de>
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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "my_string.h"

void char_cpy(char* p, const char* q)
{
	if(p && q) // p und q nicht NULL
		while((*p++ = *q++)); //solange *q != '\0', inhalt von q nach p - danach eine pos weiter 
}

/*
 * p < q return <0
 * p > q return >0
 * p == q return 0
 * p && q == NULL return >0
 */
int char_cmp(const char* p,const char* q)
{ 
	if(p && q) // p und q nicht NULL
	{
		while(*p == *q) // solange inhalt von p und q gleich
		{
			if(*p == '\0') return (0); // wenn p am ende dann auch q und somit gleich
			p++;
			q++; // eine position weiter
		}
		return (*p - *q); // *p und *q sind nicht mehr gleich: welcher ist "größer"
	}
	return +1; // tritt hoffentlich nicht ein
}