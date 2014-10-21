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
#include "linked_list.h"

// fügt argumente in Node ein, alloziert speicher für entstandene Node und gibt sie zurück
Node* make_node(const char* vorname, const char* nachname)
{
	Node* tmp;

	if(!(tmp = (Node*) malloc(sizeof(Node))))
		fprintf(stderr, "Nicht genügend Speicherplatz");

	char_cpy(tmp->vorname, vorname);
	char_cpy(tmp->nachname, nachname);

	return tmp;
}

int check_insertion_point(Node* ptr, const char* vorname, const char* nachname) //gibt 0 wenn punkt erreicht
{
	if(char_cmp(nachname, ptr->nachname) < 0 || (ptr == NULL)) { return 0; } // einfügen wenn nachname<listen name oder liste zu ende
	else if(char_cmp(nachname, ptr->nachname) > 0) { return 1; } // nicht einfügen wenn nachname>listen name
	else // nachname und listen name sind gleich
	{
		if(char_cmp(vorname, ptr->vorname) <= 0 || (ptr == NULL)) { return 0; } // einfügen wenn vorname<=listen vorname
		else { return 1; } // nicht einfügen: vorname>listen vorname 
	}
}

Node* insert_sorted(Node* head, const char* vorname, const char* nachname)
{
	Node* tmp;
	Node* prev = head;
	Node* ptr = head;

	if(!head) // leere liste - head wird ende und neue node wird head
	{
		tmp = make_node(vorname, nachname);
		tmp->next = head;
		return tmp;
	}
	else if(char_cmp(nachname, head->nachname) < 0) //vor dem ersten einfügen nach nachname
	{
			tmp = make_node(vorname, nachname);
			tmp->next = head;
			return tmp;
	}

	while((ptr != NULL) && (check_insertion_point(ptr, vorname, nachname))) //bedingte auswertung, richtige stelle zum einfügen suchen
	{
		prev = ptr;
		ptr = ptr->next;
	}

	tmp = make_node(vorname, nachname);
	prev->next = tmp; // vor gefundener stelle einfügen
	tmp->next = ptr;
	return head;
}

void print_list(Node* head)
{
	Node* ptr = head;
	while(ptr)
	{
		printf("%s %s\n", ptr->vorname, ptr->nachname);
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
		free(last); 
	}
	head = NULL;
}
