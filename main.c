#include "my_string.h"
#include "linked_list.h"
#include "macros.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	char buf_vorname[MAX];
	char buf_nachname[MAX];
	char d_name[20];
	Node* head = NULL;
	
#ifdef TEST
	FILE* source = fopen("namen_liste.txt", "r");
#else
	fprintf(stdout, "Bitte Dateinamen angeben\n");
	scanf("%s", d_name); // stdin lesen
	FILE* source = fopen(d_name, "r"); // öffnet d_name im read modus
#endif

	if(!source) // fopen gibt null zurück wenn ein fehler beim öffnen aufgetreten ist
	{
		fprintf(stderr, "Datei konnte nicht geöffnet werden");
		return 0;
	}
	else 
	{ //formatiertes einlesen (immer bis ' ' oder '\n' und in variable schreiben) fscanf gibt falls EOF erreicht das auch zurück
		while(fscanf(source, "%s %s", buf_vorname, buf_nachname) != EOF) 
			head = insert_sorted(head, buf_vorname, buf_nachname); //einfügen in liste
	}

	print_list(head);
	delete_list(head); //speicher wieder freigeben

	fclose(source); //d_name wieder schliessen

	return 0;
}
