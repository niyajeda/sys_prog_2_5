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

#include "linked_list.h"

Node* make_node(Karte* info)
{
	Node* tmp;

	if(!(tmp = (Node*) malloc(sizeof(Node))))
		fprintf(stderr, "Nicht genügend Speicherplatz");

	tmp->m_daten = info;	
	return tmp;
}

Node* insert_sorted(Node* head, Karte* info, cmp_fptr t_fptr)
{
	Node* tmp;
	Node* prev = head;
	Node* ptr = head;
	
	if(!head)
	{
		tmp = make_node(info);
		tmp->next = head;
		return tmp;
	}
	else if((t_fptr(info, ptr->m_daten)) < 0)
	{
		tmp = make_node(info);
		tmp->next = head;
		return tmp;
	}
	
	while((ptr != NULL) && (t_fptr(info, ptr->m_daten) > 0))
	{
		prev = ptr;
		ptr = ptr->next;
	}
	
	tmp = make_node(info);
	prev->next = tmp;
	tmp->next = ptr;
	return head;
}

Node* read_into_list(FILE* source, cmp_fptr t_fptr)
{
	char buf_v[MAX];
	char buf_n[MAX];
	char buf_w[MAX];
	int buf_t;
	int buf_m;
	int buf_j;
	Node* head;
	Karte* tmp_Karte;
	
	if(!source)
	{
		fprintf(stderr, "Datei konnte nicht geöffnet werden");
		return NULL;
	}
	else
	{
		while(fscanf(source, "%s %s %d %d %d %s", buf_v, buf_n, &buf_t, &buf_m, &buf_j, buf_w) != EOF)
		{
			tmp_Karte = make_karte(buf_v, buf_n, buf_w, buf_t, buf_m, buf_j);
			head = insert_sorted(head, tmp_Karte, t_fptr);
		}
	}
	return head;
}

void print_list(Node* head)
{
	Node* ptr = head;
	while(ptr)
	{
		printf("\n");
		print_karte(ptr->m_daten);
		ptr = ptr->next;
	}
}

void delete_list(Node* head)
{
	Node* ptr, *last;
	ptr = head;

	while(ptr) // solange nicht am ende der liste
	{
		last = ptr; // akuelle node zum freigeben vorbereiten
		ptr = ptr->next; // zum nächsten node wechseln
		delete_karte(last->m_daten);
		free(last);
	}
	head = NULL;
}
