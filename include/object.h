/* ************************** OBJECT CLASS HEADER *************************** */

#ifndef __OBJECT_H
#define __OBJECT_H



/* -------------------------------- INCLUDES -------------------------------- */

#include "common.h"



/* ----------------------------- CLASS METADATA ----------------------------- */

#define OBJECT_CLASS_ID 0x00000000
#define OBJECT_CLASS_NAME "Object"



/* ----------------------------- CLASS TYPEDEFS ----------------------------- */

typedef struct object Object;

typedef struct objectVTable ObjectVTable;


struct object {
    ObjectVTable const * vTable;
    char const * className;
    unsigned int classId;
    unsigned int id;
};

struct objectVTable {
    char * (*toString) (Object const * const self);
};



/* ------------------------- PUBLIC STATIC FUNCTIONS ------------------------ */

unsigned int Object_getCount();



/* ----------------------- CONSTRUCTORS & DESTRUCTORS ----------------------- */

void Object_construct(Object * const self);



/* ----------------------------- CLASS METHODS ------------------------------ */

const char * Object_getClassName(Object const * const self);

unsigned int Object_getClassId(Object const * const self);

unsigned int Object_getId(Object const * const self);



/* ---------------------------- VIRTUAL METHODS ----------------------------- */

char * Object_toString(Object const * const self);



/* --------------------------- OVERRIDDEN METHODS --------------------------- */



#endif /* __OBJECT_H */

/* ******************** (C) COPYRIGHT <AHMED ELZOUGHBY> ********************* */