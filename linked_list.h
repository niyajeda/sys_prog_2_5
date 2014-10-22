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

/* inclusion guard */
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "macros.h"
#include "kartei_karte.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* next;
	Karte* m_daten;
} Node;

Node* make_node(Karte* info);	
Node* insert_sorted(Node* head, Karte* info, cmp_fptr t_fptr);
Node* read_into_list(FILE* source, cmp_fptr t_fptr); 

void print_list(Node* head);
void delete_list(Node* head);

#endif /* __LINKED_LIST_H__ */
