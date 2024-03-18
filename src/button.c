#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "button.h"



static inline void __emulateClick(Button * const self) {
    printf("Emulating Button Click...\n");
    self->onClick(self);
}

static inline void __draw(Button const * const self) {
    assert(0);
}

static inline char * __toString(Button const * const self) {
    assert(0);
    return NULL;
}



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
    strcpy(self->super.super.className, BUTTON_CLASS_NAME);
    self->super.super.classId = BUTTON_CLASS_ID;
    self->super.super.vTable = &ovTable;
    self->super.vTable = &wvTable;
    self->vTable = &bvTable;
    self->width = width;
    self->height = height;
    self->text = text;
    self->onClick = onClick;
}

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

void Button_emulateClick(Button * const self) {
    self->vTable->emulateClick(self);
}

void Button_draw(Button const * const self) {
    self->super.vTable->draw((Widget *) self);
}

char * Button_toString(Button const * const self) {
    return self->super.super.vTable->toString((Object *) self);
}
