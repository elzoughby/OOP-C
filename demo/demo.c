/* **************************** OOP DEMO SOURCE ***************************** */


#include <stdio.h>
#include <string.h>
#include "image_button.h"



void buttons_click_action(Button * const b) {
    printf("%s %s ", Button_getText(b), Object_getClassName((Object *) b));
    if (Object_getClassId((Object *) b) == IMAGEBUTTON_CLASS_ID) {
        printf("containing %s ", ImageButton_getImage((ImageButton *) b));
    }
    printf("got pressed!\n\n");
}


int main() {
    Button okButton, cancelButton;
    ImageButton backButton, forwardButton;

    Button_construct(&okButton, 0, 110, 70, 16, "OK", &buttons_click_action);
    Button_construct(&cancelButton, 80, 110, 70, 16, "Cancel",
            &buttons_click_action);

    ImageButton_construct(&backButton, 0, 0, 100, 100, "Back",
            (void (*)(ImageButton * const)) &buttons_click_action,
            "left_arrow.png");
    ImageButton_construct(&forwardButton, 110, 0, 100, 100, "Forward",
            (void (*)(ImageButton * const)) &buttons_click_action,
            "right_arrow.png");

    Object * justObject;
    Widget * justWidget;

    justObject = (Object *) Button_create(0, 0, 100, 100, "Just an object",
            (void (*)(Button * const))  &buttons_click_action);
    justWidget = (Widget *) ImageButton_create(0, 0, 100, 100, "Just a widget",
            (void (*)(ImageButton * const)) &buttons_click_action,
            "just_image.png");

    ImageButton_emulateClick(&backButton);
    Button_emulateClick((Button *) &forwardButton);

    Button_emulateClick(&okButton);
    Button_emulateClick(&cancelButton);

    Object_toString(justObject);
    Widget_toString(justWidget);

    printf("=============================================================\n");
    printf("Total objects created: %u\n", Object_getCount());

    return 0;
}



/* ******************** (C) COPYRIGHT <AHMED ELZOUGHBY> ********************* */