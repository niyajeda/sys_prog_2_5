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
#ifndef __KARTEI_KARTE_H__
#define __KARTEI_KARTE_H__

#include "macros.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Datum 
{
	int m_tag;
	int m_monat;
	int m_jahr;
} Datum;

typedef struct Karte 
{
	char* m_vorname;
	char* m_nachname;
	char* m_wohnort;
	Datum* m_datum;
} Karte;

typedef int (*cmp_fptr)(const Karte* a, const Karte* b);
char* make_mem(const char* info);
Datum* make_date(const int tag, const int monat, const int jahr);
Karte* make_karte(const char* vorname, const char* nachname, const char* wohnort, const int tag, const int monat, const int jahr);
int cmp_nachname(const Karte* a, const Karte* b);
int cmp_wohnort(const Karte* a, const Karte* b);
int cmp_datum(const Karte* a, const Karte* b);
void print_datum(const Datum* datum);
void print_karte(const Karte* info);
void delete_karte(Karte* info);

#endif /* __KARTEI_KARTE_H__ */
