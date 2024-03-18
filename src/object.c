#include <assert.h>
#include <string.h>
#include "object.h"



static unsigned int count = 0;



static inline char * __toString(Object const * const self) {
    assert(0);
    return NULL;
}



unsigned int Object_getCount() {
    return count;
}


void Object_construct(Object * const self) {
    static const ObjectVTable ovTable = {
        &__toString,
    };

    self->vTable = &ovTable;
    self->id = count;
    self->classId = OBJECT_CLASS_ID;
    strcpy(self->className, OBJECT_CLASS_NAME);

    count++;
}

const char * Object_getClassName(Object const * const self) {
    return self->className;
}

unsigned int Object_getClassId(Object const * const self) {
    return self->classId;
}

unsigned int Object_getId(Object const * const self) {
    return self->id;
}

char * Object_toString(Object const * const self) {
    return self->vTable->toString(self);
}
