/* ************************** WIDGET CLASS SOURCE *************************** */



/* -------------------------------- INCLUDES -------------------------------- */

#include <assert.h>
#include <stdio.h>
#include "widget.h"



/* ------------------------------ PRIVATE DATA ------------------------------ */



/* --------------------- VIRTUAL METHODS IMPLEMENTATION --------------------- */

static inline void __draw(Widget const * const self) {
    assert(0);
}

static inline char * __toString(Widget const * const self) {
    assert(0);
    return NULL;
}



/* ------------------------ PRIVATE STATIC FUNCTIONS ------------------------ */



/* ------------------------- PUBLIC STATIC FUNCTIONS ------------------------ */



/* ------------------------- PRIVATE CLASS METHODS -------------------------- */



/* ----------------------- CONSTRUCTORS & DESTRUCTORS ----------------------- */

void Widget_construct(Widget * const self, int x, int y) {
    static const ObjectVTable ovTable = {
        (char * (*) (Object const * const self)) &__toString,
    };
    static const WidgetVTable wvTable = {
        &__draw,
    };

    Object_construct(&self->super);
    self->super.className = WIDGET_CLASS_NAME;
    self->super.classId = WIDGET_CLASS_ID;
    self->super.vTable = &ovTable;
    self->vTable = &wvTable;
    self->x = x;
    self->y = y;
}



/* ----------------------------- CLASS METHODS ------------------------------ */

int Widget_getX(Widget const * const self) {
    return self->x;
}

void Widget_setX(Widget * const self, int x) {
    self->x = x;
}

int Widget_getY(Widget const * const self) {
    return self->y;
}

void Widget_setY(Widget * const self, int y) {
    self->y = y;
}



/* ---------------------------- VIRTUAL METHODS ----------------------------- */

void Widget_draw(Widget const * const self) {
    self->vTable->draw(self);
}



/* --------------------------- OVERRIDDEN METHODS --------------------------- */

char * Widget_toString(Widget const * const self) {
    return self->super.vTable->toString((Object *) self);
}



/* ******************** (C) COPYRIGHT <AHMED ELZOUGHBY> ********************* */