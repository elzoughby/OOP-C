/* ************************** BUTTON CLASS SOURCE *************************** */



/* -------------------------------- INCLUDES -------------------------------- */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "button.h"



/* ------------------------------ PRIVATE DATA ------------------------------ */



/* --------------------- VIRTUAL METHODS IMPLEMENTATION --------------------- */

static inline void __emulateClick(Button * const self) {
    printf("Emulating Button Click...\n");
    self->onClick(self);
}

static inline void __draw(Button const * const self) {
    assert(0);
}

static inline char * __toString(Button const * const self) {
    printf("This is a Button with id %u and text \"%s\"!\n",
            Object_getId((Object *) self), self->text);
    return NULL;
}



/* ------------------------ PRIVATE STATIC FUNCTIONS ------------------------ */



/* ------------------------- PUBLIC STATIC FUNCTIONS ------------------------ */



/* ------------------------- PRIVATE CLASS METHODS -------------------------- */



/* ----------------------- CONSTRUCTORS & DESTRUCTORS ----------------------- */

void Button_construct(Button * const self, 
                      int x, int y, 
                      int width, int height, 
                      char * const text, 
                      void (*onClick) (Button * const self)) {
    static const ObjectVTable ovTable = {
        (char * (*) (Object const * const self)) &__toString,
    };
    static const WidgetVTable wvTable = {
        (void (*)(Widget const *)) &__draw,
    };
    static const ButtonVTable bvTable = {
        &__emulateClick,
    };

    Widget_construct(&self->super, x, y);
    self->super.super.className = BUTTON_CLASS_NAME;
    self->super.super.classId = BUTTON_CLASS_ID;
    self->super.super.vTable = &ovTable;
    self->super.vTable = &wvTable;
    self->vTable = &bvTable;
    self->width = width;
    self->height = height;
    self->text = text;
    self->onClick = onClick;
}

Button * Button_create(int x, int y, 
                       int width, int height, 
                       char * const text, 
                       void (*onClick) (Button * const self)) {
    Button * self = (Button *) malloc(sizeof(Button));
    Button_construct(self, x, y, width, height, text, onClick);
    return self;
}

void Button_destroy(Button * const self) {
    free(self);
}



/* ----------------------------- CLASS METHODS ------------------------------ */

unsigned int Button_getWidth(Button const * const self) {
    return self->width;
}

void Button_setWidth(Button * const self, unsigned int width) {
    self->width = width;
}

unsigned int Button_getHeight(Button const * const self) {
    return self->height;
}

void Button_setHeight(Button * const self, unsigned int height) {
    self->height = height;
}

char * Button_getText(Button const * const self) {
    return self->text;
}

void Button_setText(Button * const self, char * text) {
    self->text = text;
}



/* ---------------------------- VIRTUAL METHODS ----------------------------- */

void Button_emulateClick(Button * const self) {
    self->vTable->emulateClick(self);
}



/* --------------------------- OVERRIDDEN METHODS --------------------------- */

void Button_draw(Button const * const self) {
    self->super.vTable->draw((Widget *) self);
}

char * Button_toString(Button const * const self) {
    return self->super.super.vTable->toString((Object *) self);
}



/* ******************** (C) COPYRIGHT <AHMED ELZOUGHBY> ********************* */