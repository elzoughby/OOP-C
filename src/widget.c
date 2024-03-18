#include <assert.h>
#include <string.h>
#include "widget.h"



static inline void __draw(Widget const * const self) {
    assert(0);
}

static inline char * __toString(Widget const * const self) {
    assert(0);
    return NULL;
}



void Widget_construct(Widget * const self, int x, int y) {
    static const ObjectVTable ovTable = {
        (char * (*) (Object const * const self)) &__toString,
    };
    static const WidgetVTable wvTable = {
        &__draw,
    };

    Object_construct(&self->super);
    strcpy(self->super.className, WIDGET_CLASS_NAME);
    self->super.classId = WIDGET_CLASS_ID;
    self->super.vTable = &ovTable;
    self->vTable = &wvTable;
    self->x = x;
    self->y = y;
}

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

void Widget_draw(Widget const * const self) {
    self->vTable->draw(self);
}

char * Widget_toString(Widget const * const self) {
    return self->super.vTable->toString((Object *) self);
}
