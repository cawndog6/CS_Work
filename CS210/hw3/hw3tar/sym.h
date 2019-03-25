#ifndef SYMTBL_H
#define SYMTBL_H

#define NSYMS   (1)

struct sym {
    char * name;
    double value;
	struct sym *next;
}sym_tbl[NSYMS];
struct sym * sym_lookup(char *);
void DisplayVars();
void selectionSort(struct sym* arr, int n);

#endif /* SYMTBL_H */
