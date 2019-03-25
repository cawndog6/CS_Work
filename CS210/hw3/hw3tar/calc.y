%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sym.h"
%}

%union {
    double dval;
    struct sym * symptr;
}
%token QUERY
%token <dval> PI
%token <dval> PHI
%token <symptr> NAME
%token <dval> NUMBER
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS

%type <dval> expression
%%
statement_list
    : statement '\n'
    | statement_list statement '\n'
    ;

statement
    : NAME '=' expression { $1->value = $3; }
	| PI '=' expression { printf("assign to constant\n= 3.14159\n"); }
	| PHI '=' expression { printf("assign to constant\n= 1.61803\n"); }
	| QUERY { DisplayVars(); }
    | expression { printf("= %g\n", $1); }
    ;

expression
    : expression '+' expression { $$ = $1 + $3; }
    | expression '-' expression { $$ = $1 - $3; }
    | expression '*' expression { $$ = $1 * $3; }
    | expression '/' expression { if($3 == 0){ $$ = $1; printf("divide by zero\n");}else{$$ = $1 / $3; }}
    | '-' expression %prec UMINUS { $$ = -$2; }
    | '(' expression ')' { $$ = $2; }
	| PI
	| PHI
    | NUMBER
    | NAME { $$ = $1->value; }
    ;
%%

struct sym * sym_lookup(char * s)
{
	struct sym* temp = sym_tbl;
	struct sym* prev;
	if (!temp->name)
	{
		temp->name = strdup(s);
		temp->next = NULL;
		return temp;
	}
	while(temp != NULL)
	{
		if (strcmp(temp->name, s) == 0)
			return temp;
		prev = temp;
		temp = temp->next;
	}
	prev->next = (struct sym*)malloc(sizeof(struct sym));
	temp = prev->next;
	temp->name = strdup(s);
	temp->next = NULL;
	return temp;
	
}
void DisplayVars()
{
	int num_syms = 0;
	struct sym *temp = sym_tbl;
	if (!temp->name)
	{
		printf("num-syms: 2\n");
		printf("\tPHI => 1.61803\n");
		printf("\tPI => 3.14159\n");
		return;
	}
	while(temp != NULL)
	{
		num_syms++;
		temp = temp->next;
	}
	temp = sym_tbl;
	// Place symbols into a dynamically allocated array of sym pointers to sort them alphabetically
	struct sym *sorted_syms = (struct sym*)malloc(sizeof(struct sym)*num_syms); //allocate array
	int index = 0;
	while (index < num_syms)
	{
		sorted_syms[index] = *temp;
		temp = temp->next;
		index++;
	}
	selectionSort(sorted_syms, num_syms);
	printf("num_syms: %i\n", num_syms + 2);
	printf("\tPHI => 1.61803\n");
	printf("\tPI => 3.14159\n");
	index = 0;
	while(index < num_syms)
	{
		printf("\t%s => %f\n", sorted_syms[index].name, sorted_syms[index].value);
		index++;
	}
}
void selectionSort(struct sym* arr, int n)
{
    int i, j, min_idx;
	int MAX_LEN = 30;
    // One by one move boundary of unsorted subarray
    char minStr[MAX_LEN];
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        strcpy(minStr, arr[i].name);
        for (j = i+1; j < n; j++)
        {
            // If min is greater than arr[j]
            if (strcmp(minStr, arr[j].name) > 0)
            {
                // Make arr[j] as minStr and update min_idx
                strcpy(minStr, arr[j].name);
                min_idx = j;
            }
        }
  
        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
			struct sym* tempsym = sym_lookup(arr[i].name);
			struct sym* tempsym2 = sym_lookup(arr[min_idx].name);
            char tempname[MAX_LEN];
			double tempval = 0;
			struct sym* tempnext;
			
            strcpy(tempname, arr[i].name); //swap name[pos] and item[i]
			tempval = arr[i].value;
            
			strcpy(arr[i].name, arr[min_idx].name);
			arr[i].value = arr[min_idx].value;
			tempsym->value = tempsym2->value;
            
			strcpy(arr[min_idx].name, tempname);
			arr[min_idx].value = tempval;
			tempsym2->value = tempval;
        }
    }
}

