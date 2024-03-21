/* ************************** OBJECT CLASS SOURCE *************************** */



/* -------------------------------- INCLUDES -------------------------------- */

#include <assert.h>
#include <stdio.h>
#include "object.h"



/* ------------------------------ PRIVATE DATA ------------------------------ */

static unsigned int count = 0;



/* --------------------- VIRTUAL METHODS IMPLEMENTATION --------------------- */

static inline char * __toString(Object const * const self) {
    assert(0);
    return NULL;
}



/* ------------------------ PRIVATE STATIC FUNCTIONS ------------------------ */



/* ------------------------- PUBLIC STATIC FUNCTIONS ------------------------ */

unsigned int Object_getCount() {
    return count;
}



/* ------------------------- PRIVATE CLASS METHODS -------------------------- */



/* ----------------------- CONSTRUCTORS & DESTRUCTORS ----------------------- */

void Object_construct(Object * const self) {
    static const ObjectVTable ovTable = {
        &__toString,
    };

    self->vTable = &ovTable;
    self->className = OBJECT_CLASS_NAME;
    self->classId = OBJECT_CLASS_ID;
    self->id = count;

    count++;
}



/* ----------------------------- CLASS METHODS ------------------------------ */

const char * Object_getClassName(Object const * const self) {
    return self->className;
}

unsigned int Object_getClassId(Object const * const self) {
    return self->classId;
}

unsigned int Object_getId(Object const * const self) {
    return self->id;
}



/* ---------------------------- VIRTUAL METHODS ----------------------------- */

char * Object_toString(Object const * const self) {
    return self->vTable->toString(self);
}



/* --------------------------- OVERRIDDEN METHODS --------------------------- */



/* ******************** (C) COPYRIGHT <AHMED ELZOUGHBY> ********************* */