/*-------------------------------------------------------------------------*/
/* yal-lin is developed on top of the SLS solver Yalsat (By Armin Biere). 
Algorithms, implmentation, and Experiments are presented in our NFM-2023 paper
"A Linear Weight Transfer Rule for Local Search" (Md Solimul Chowdhury, Cayden Codel, Marijn Heule) 
*/

/*-------------------------------------------------------------------------*/

#ifndef LIBYALS_H_INCLUDED
#define LIBYALS_H_INCLUDED

/*------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------*/

typedef struct Yals Yals;

/*------------------------------------------------------------------------*/

Yals * yals_new ();
void yals_del (Yals *);

/*------------------------------------------------------------------------*/

typedef void * (*YalsMalloc)(void*,size_t);
typedef void * (*YalsRealloc)(void*,void*,size_t,size_t);
typedef void (*YalsFree)(void*,void*,size_t);

Yals * yals_new_with_mem_mgr (void*, YalsMalloc, YalsRealloc, YalsFree);

/*------------------------------------------------------------------------*/

void yals_srand (Yals *, unsigned long long seed);
int yals_setopt (Yals *, const char * name, int val);
void yals_setprefix (Yals *, const char *);
void yals_setout (Yals *, FILE *);
void yals_setphase (Yals *, int lit);
void yals_setflipslimit (Yals *, long long);
void yals_setmemslimit (Yals *, long long);

int yals_getopt (Yals *, const char * name);
void yals_usage (Yals *);
void yals_showopts (Yals *);

/*------------------------------------------------------------------------*/

void yals_add (Yals *, int lit);

int yals_sat (Yals *);

/*------------------------------------------------------------------------*/

long long yals_flips (Yals *);
long long yals_mems (Yals *);

int yals_minimum (Yals *);
int yals_lkhd (Yals *);
int yals_deref (Yals *, int lit);

const int * yals_minlits (Yals *);


int yals_flip_count (Yals *yals);

int yals_nunsat_external (Yals *yals);

/*------------------------------------------------------------------------*/

void yals_stats (Yals *);

/*------------------------------------------------------------------------*/

void yals_seterm (Yals *, int (*term)(void*), void*);

void yals_setime (Yals *, double (*time)(void));

void yals_setmsglock (Yals *,
       void (*lock)(void*), void (*unlock)(void*), void*);

/*------------------------------------------------------------------------*/

#endif
