/* ************************ IMAGEBUTTON CLASS HEADER ************************ */

#ifndef __IMAGE_BUTTON_H
#define __IMAGE_BUTTON_H



/* -------------------------------- INCLUDES -------------------------------- */

#include "button.h"



/* ----------------------------- CLASS METADATA ----------------------------- */

#define IMAGEBUTTON_CLASS_ID 0x00000003
#define IMAGEBUTTON_CLASS_NAME "ImageButton"



/* ----------------------------- CLASS TYPEDEFS ----------------------------- */

typedef struct imageButton ImageButton;
typedef struct imageButtonVTable ImageButtonVTable;


struct imageButton {
    Button super;
    ImageButtonVTable const * vTable;
    char * image;
};

struct imageButtonVTable {
    void (*rotate) (ImageButton * const self);
};



/* ------------------------- PUBLIC STATIC FUNCTIONS ------------------------ */



/* ----------------------- CONSTRUCTORS & DESTRUCTORS ----------------------- */

void ImageButton_construct(ImageButton * const self, 
                           int x, int y, 
                           int width, int height, 
                           char * const text, 
                           void (*onClick) (ImageButton * const self),
                           char * const image);

ImageButton * ImageButton_create(int x, int y, 
                                int width, int height, 
                                char * const text, 
                                void (*onClick) (ImageButton * const self),
                                char * const image);

void ImageButton_destroy(ImageButton * const self);



/* ----------------------------- CLASS METHODS ------------------------------ */

char * ImageButton_getImage(ImageButton const * const self);

void ImageButton_setImage(ImageButton * const self, char * image);

void ImageButton_rotate(ImageButton * const self);



/* ---------------------------- VIRTUAL METHODS ----------------------------- */

void ImageButton_emulateClick(ImageButton * const self);



/* --------------------------- OVERRIDDEN METHODS --------------------------- */

void ImageButton_draw(ImageButton const * const self);

char * ImageButton_toString(ImageButton const * const self);



#endif /* __IMAGE_BUTTON_H */

/* ******************** (C) COPYRIGHT <AHMED ELZOUGHBY> ********************* */