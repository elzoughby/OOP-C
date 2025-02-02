/* ************************** BUTTON CLASS HEADER *************************** */

#ifndef __BUTTON_H
#define __BUTTON_H



/* -------------------------------- INCLUDES -------------------------------- */

#include "widget.h"



/* ----------------------------- CLASS METADATA ----------------------------- */

#define BUTTON_CLASS_ID 0x00000002
#define BUTTON_CLASS_NAME "Button"



/* ----------------------------- CLASS TYPEDEFS ----------------------------- */

typedef struct button Button;

typedef struct buttonVTable ButtonVTable;


struct button {
    Widget super;
    ButtonVTable const * vTable;
    unsigned int width;
    unsigned int height;
    char * text;
    void (*onClick) (struct button * const self);
};

struct buttonVTable {
    void (*emulateClick) (Button * const self);
};



/* ------------------------- PUBLIC STATIC FUNCTIONS ------------------------ */



/* ----------------------- CONSTRUCTORS & DESTRUCTORS ----------------------- */

void Button_construct(Button * const self, 
                      int x, int y, 
                      int width, int height, 
                      char * const text, 
                      void (*onClick) (Button * const self));

Button * Button_create(int x, int y, 
                       int width, int height, 
                       char * const text, 
                       void (*onClick) (Button * const self));

void Button_destroy(Button * const self);



/* ----------------------------- CLASS METHODS ------------------------------ */

unsigned int Button_getWidth(Button const * const self);

void Button_setWidth(Button * const self, unsigned int width);

unsigned int Button_getHeight(Button const * const self);

void Button_setHeight(Button * const self, unsigned int height);

char * Button_getText(Button const * const self);

void Button_setText(Button * const self, char * text);



/* ---------------------------- VIRTUAL METHODS ----------------------------- */

void Button_emulateClick(Button * const self);



/* --------------------------- OVERRIDDEN METHODS --------------------------- */

void Button_draw(Button const * const self);

char * Button_toString(Button const * const self);



#endif /* __BUTTON_H */

/* ******************** (C) COPYRIGHT <AHMED ELZOUGHBY> ********************* */