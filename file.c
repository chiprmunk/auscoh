//
//	file.c: Anarchia Underground Society - Coherent 386 UNIX (auscoh) BBS
//	written by wayne a.j. craig
//	sept 22,2016
//      version: 1.0r0
//
// FILE open code
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "bbs.h"
#include "userdata.h"


int openfiles(void);

int openfiles(void) {

	FILE *myfp;
	myfp=fopen("FILE","rb+");
        if(!myfp)
        {
         
        } 


}

