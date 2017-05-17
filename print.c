
/* =====[ print.c ]=========================================================

   Description:  Printer routines for pcalc.

   Revisions:

      REV     DATE     BY           DESCRIPTION
      ----  --------  ----------    --------------------------------------
      0.00  mm/dd/95  Peter Glen    Initial version.
      1.00  22/9/98   Peter Glen    Unix port

   ======================================================================= */

/* -------- System includes:  -------------------------------------------- */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* -------- Includes:  --------------------------------------------------- */

#include "convert.h"
#include "hocdecl.h"
#include "symbol.h"

/* -------- Implementation: ---------------------------------------------- */

static char work_str[128];

extern int fOctal;

void    print_num(double var)

{
    Symbol *msx  = lookup_sym("DEC");
    
    // compatibility variable:

    if(!msx)
      msx  = lookup_sym("DECIMAL");
    
    if(msx && msx->u.val == 1)
      {
	printf("%g" , var);
      }
    else if(msx && msx->u.val == 2)
      {
	printf("%llx" , (unsigned long long)var);
      }
    else if(msx && msx->u.val == 3)
      {
	long_to_bin_str((unsigned long long)var, work_str);
	printf("%s", work_str);
      }
    else if(msx && msx->u.val == 4)
      {
	printf("%llo", (unsigned long long)var);
      }
    else
      {
	long_to_bin_str((unsigned long long)var, work_str);
	printf("\t%-16.16g", var);
	if (fOctal)
	  printf("\t0o%-16llo", (unsigned long long)var);
	printf("\t0x%-16llx", (unsigned long long)var);
	printf("\t0b%s\n", work_str);
      }
}

/* EOF */
