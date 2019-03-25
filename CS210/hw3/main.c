#include <stdio.h>
#include "sym.h"
#include <string.h>
main(){
	struct sym* pi = &sym_tbl[0];
	struct sym* phi = &sym_tbl[1];
	pi->name = strdup("PI");
	pi->value = 3.14159;
	phi->name = strdup("PHI");
	phi->value = 1.61803;
	return( yyparse() );
    }

yyerror(s) char *s; {
	fprintf( stderr, "%s\n", s );
        }
