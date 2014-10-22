#include "linked_list.h"
#include "macros.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	char d_name[20];
	int fptr_nr;
	cmp_fptr fptr;
	Node* head = NULL;
	
#ifdef TEST
	FILE* source = fopen("namen_liste.txt", "r");
#else
	fprintf(stdout, "Bitte Dateinamen angeben\n");
	scanf("%s", d_name); // stdin lesen
	FILE* source = fopen(d_name, "r"); // öffnet d_name im read modus
	fprintf(stdout, "Sortierkiterium wählen: [0]Nachname, [1]Wohnort, [2]Geburtsdatum\n");
	scanf("%d", &fptr_nr);
	switch(fptr_nr)
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
	
#endif

	head = read_into_list(source, fptr);
	print_list(head);
	delete_list(head); //speicher wieder freigeben

	fclose(source); //d_name wieder schliessen
											
	return 0;
}
