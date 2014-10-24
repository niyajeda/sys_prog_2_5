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

#include "kartei_karte.h"

char* make_mem(const char* info)
{
	size_t len = strlen(info) + 1; // wie lang ist char* mit '\0'
	char* tmp;
	
	if(!(tmp = (char*) malloc(len*sizeof(char)))) // platz schaffen
		fprintf(stderr, "Fehler in make_mem");
	return strcpy(tmp, info); // platz beschreiben
}

Datum* make_date(const int tag,const int monat,const int jahr)
{
	Datum* tmp;

	if(!(tmp = (Datum*) malloc(sizeof(Datum)))) 
		fprintf(stderr, "Fehler in make_date");
	tmp->m_tag = tag;
	tmp->m_monat = monat;
	tmp->m_jahr = jahr;
	return tmp;
}

Karte* make_karte(const char* vorname, const char* nachname, const char* wohnort, const int tag, const int monat, const int jahr)
{
	Karte* tmp;
	
	if(!(tmp = (Karte*) malloc(sizeof(Karte)))) 
		fprintf(stderr, "Fehler in make_karte");
	// platz für werte der karte schaffen und speichern
	tmp->m_vorname 	= make_mem(vorname);
	tmp->m_nachname 	= make_mem(nachname);
	tmp->m_wohnort 	= make_mem(wohnort);
	tmp->m_datum 		= make_date(tag, monat, jahr);
	return tmp;
}

int cmp_nachname(const Karte* a, const Karte* b) 	{ return strcmp(a->m_nachname, b->m_nachname); }
int cmp_wohnort(const Karte* a, const Karte* b) 	{ return strcmp(a->m_wohnort, b->m_wohnort); }
int cmp_datum(const Karte* a, const Karte* b) // 0 wenn a und b gleichalt sind, a < b = -1, a > b = 1
{
	if(a->m_datum->m_jahr < b->m_datum->m_jahr) return -1;
	else if(a->m_datum->m_jahr > b->m_datum->m_jahr) return 1;
	else
	{
		if(a->m_datum->m_monat < b->m_datum->m_monat) return -1;
		else if(a->m_datum->m_monat > b->m_datum->m_monat) return 1;
		else
		{
			if(a->m_datum->m_tag < b->m_datum->m_tag) return -1;
			else if(a->m_datum->m_tag > b->m_datum->m_tag) return 1;
			else return 0;
		}
	}
}

void print_karte(const Karte* info)
{
	printf("%s %s ", info->m_vorname, info->m_nachname);
	print_datum(info->m_datum);
	printf(" %s", info->m_wohnort);
}

void print_datum(const Datum* datum) // hilfsfkt
{
	printf("%d %d %d", datum->m_tag, datum->m_monat, datum->m_jahr);
}

void delete_karte(Karte* info) // linked_list kennt karte nicht
{
	if(info) // zur sicherheit
	{
		free(info->m_vorname);
		free(info->m_nachname);
		free(info->m_wohnort);
		free(info->m_datum);
		free(info);
	}
}
