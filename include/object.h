#ifndef __OBJECT_H
#define __OBJECT_H



#include "common.h"



#define OBJECT_CLASS_ID 0x00000000
#define OBJECT_CLASS_NAME "Object"



typedef struct object Object;

typedef struct objectVTable ObjectVTable;


struct object {
    ObjectVTable const * vTable;
    char className[32];
    unsigned int classId;
    unsigned int id;
};

struct objectVTable {
    char * (*toString) (Object const * const self);
};



unsigned int Object_getCount();



void Object_construct(Object * const self);

const char * Object_getClassName(Object const * const self);

unsigned int Object_getClassId(Object const * const self);

unsigned int Object_getId(Object const * const self);

char * Object_toString(Object const * const self);



#endif /* __OBJECT_H */
