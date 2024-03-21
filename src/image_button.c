/* ************************ IMAGEBUTTON CLASS SOURCE ************************ */



/* -------------------------------- INCLUDES -------------------------------- */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "image_button.h"



/* ------------------------------ PRIVATE DATA ------------------------------ */



/* --------------------- VIRTUAL METHODS IMPLEMENTATION --------------------- */

static inline void __rotate(ImageButton * const self) {
    printf("ImageButton object with id %u got rotated!\n", Object_getId((Object *) self));
}

static inline void __emulateClick(ImageButton * const self) {
    printf("Emulating ImageButton Click...\n");
    self->super.onClick((Button *) self);
}

static inline void __draw(ImageButton const * const self) {
    assert(0);
}

static inline char * __toString(ImageButton const * const self) {
    assert(0);
    return NULL;
}



/* ------------------------ PRIVATE STATIC FUNCTIONS ------------------------ */



/* ------------------------- PUBLIC STATIC FUNCTIONS ------------------------ */



/* ------------------------- PRIVATE CLASS METHODS -------------------------- */



/* ----------------------- CONSTRUCTORS & DESTRUCTORS ----------------------- */

void ImageButton_construct(ImageButton * const self, 
                           int x, int y, 
                           int width, int height, 
                           char * const text, 
                           void (*onClick) (ImageButton * const self),
                           char * const image) {
    static const ObjectVTable ovTable = {
        (char * (*) (Object const * const self)) &__toString,
    };
    static const WidgetVTable wvTable = {
        (void (*)(Widget const *)) &__draw,
    };
    static const ButtonVTable bvTable = {
        (void (*)(Button *)) &__emulateClick,
    };
    static const ImageButtonVTable ibvTable = {
        &__rotate,
    };

    Button_construct(&self->super, x, y, width, height, text, (void (*)(Button *)) onClick);
    self->super.super.super.className = IMAGEBUTTON_CLASS_NAME;
    self->super.super.super.classId = IMAGEBUTTON_CLASS_ID;
    self->super.super.super.vTable = &ovTable;
    self->super.super.vTable = &wvTable;
    self->super.vTable = &bvTable;
    self->vTable = &ibvTable;
    self->image = image;
}

ImageButton * ImageButton_create(int x, int y, 
                                int width, int height, 
                                char * const text, 
                                void (*onClick) (ImageButton * const self),
                                char * const image) {
    ImageButton * const self = (ImageButton *) malloc(sizeof(ImageButton));
    ImageButton_construct(self, x, y, width, height, text, onClick, image);
    return self;
}

void ImageButton_destroy(ImageButton * const self) {
    free(self);
}



/* ----------------------------- CLASS METHODS ------------------------------ */

char * ImageButton_getImage(ImageButton const * const self) {
    return self->image;
}

void ImageButton_setImage(ImageButton * const self, char * image) {
    self->image = image;
}

void ImageButton_rotate(ImageButton * const self) {
    self->vTable->rotate(self);
}



/* ---------------------------- VIRTUAL METHODS ----------------------------- */

void ImageButton_emulateClick(ImageButton * const self) {
    self->super.vTable->emulateClick((Button *) self);
}



/* --------------------------- OVERRIDDEN METHODS --------------------------- */

void ImageButton_draw(ImageButton const * const self) {
    self->super.super.vTable->draw((Widget *) self);
}

char * ImageButton_toString(ImageButton const * const self) {
    return self->super.super.super.vTable->toString((Object *) self);
}



/* ******************** (C) COPYRIGHT <AHMED ELZOUGHBY> ********************* */