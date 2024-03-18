#ifndef __IMAGE_BUTTON_H
#define __IMAGE_BUTTON_H



#include "button.h"



#define IMAGEBUTTON_CLASS_ID 0x00000003
#define IMAGEBUTTON_CLASS_NAME "ImageButton"



typedef struct imageButton ImageButton;
typedef struct imageButtonVTable ImageButtonVTable;


struct imageButton {
    Button super;
    struct imageButtonVTable const *vTable;
    char *image;
};

struct imageButtonVTable {
    void (*rotate) (ImageButton * const self);
};



void ImageButton_construct(ImageButton * const self, 
                           int x, int y, 
                           int width, int height, 
                           char * const text, 
                           void (*onClick) (ImageButton * const self),
                           char * const image);

char * ImageButton_getImage(ImageButton const * const self);

void ImageButton_setImage(ImageButton * const self, char * image);

void ImageButton_rotate(ImageButton * const self);

void ImageButton_emulateClick(ImageButton * const self);

void ImageButton_draw(ImageButton const * const self);

char * ImageButton_toString(ImageButton const * const self);




#endif /* __IMAGE_BUTTON_H */
