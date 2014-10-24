#include "linked_list.h"
#include "macros.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	char buf_v[MAX];
	char buf_n[MAX];
	char buf_w[MAX];
	int buf_t, buf_m, buf_j;
	char d_name[20];
	int fptr_nr;
	cmp_fptr fptr;
	Node* head = NULL;
	
	fprintf(stdout, "Bitte Dateinamen angeben\n");
	scanf("%s", d_name); // stdin lesen
	FILE* source = fopen(d_name, "r"); // öffnet d_name im read modus
	fprintf(stdout, "Sortierkiterium wählen: [0]Nachname, [1]Wohnort, [2]Geburtsdatum\n");
	scanf("%d", &fptr_nr);
	
	switch(fptr_nr) // fptr auswählen und merken
	{
		case 0:
			fptr = &cmp_nachname;
			break;
		case 1:
			fptr = &cmp_wohnort;
			break;
		case 2:
			fptr = &cmp_datum;
			break;
	}

	if(!source)
	{
		fprintf(stderr, "Datei konnte nicht geöffnet werden");
		return 1;
	}
	else
	{
		while(fscanf(source, "%s %s %d %d %d %s", buf_v, buf_n, &buf_t, &buf_m, &buf_j, buf_w) != EOF)
			head = insert_sorted(head, make_karte(buf_v, buf_n, buf_w, buf_t, buf_m, buf_j), fptr);
	}
	print_list(head);
	delete_list(head); //speicher wieder freigeben

	fclose(source); //d_name wieder schliessen
											
	return 0;
}
