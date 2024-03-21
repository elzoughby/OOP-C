/* ************************** WIDGET CLASS HEADER *************************** */

#ifndef __WIDGET_H
#define __WIDGET_H



/* -------------------------------- INCLUDES -------------------------------- */

#include "object.h"



/* ----------------------------- CLASS METADATA ----------------------------- */

#define WIDGET_CLASS_ID 0x00000001
#define WIDGET_CLASS_NAME "Widget"



/* ----------------------------- CLASS TYPEDEFS ----------------------------- */

typedef struct widget Widget;

typedef struct widgetVTable WidgetVTable;


struct widget {
    Object super;
    WidgetVTable const * vTable;
    int x;
    int y;
};

struct widgetVTable {
    void (*draw) (Widget const * const self);
};



/* ------------------------- PUBLIC STATIC FUNCTIONS ------------------------ */



/* ----------------------- CONSTRUCTORS & DESTRUCTORS ----------------------- */

void Widget_construct(Widget * const self, int x, int y);



/* ----------------------------- CLASS METHODS ------------------------------ */

int Widget_getX(Widget const * const self);

void Widget_setX(Widget * const self, int x);

int Widget_getY(Widget const * const self);

void Widget_setY(Widget * const self, int y);



/* ---------------------------- VIRTUAL METHODS ----------------------------- */

void Widget_draw(Widget const * const self);



/* --------------------------- OVERRIDDEN METHODS --------------------------- */

char * Widget_toString(Widget const * const self);



#endif /* __WIDGET_H */

/* ******************** (C) COPYRIGHT <AHMED ELZOUGHBY> ********************* */