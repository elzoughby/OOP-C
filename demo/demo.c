#include <stdio.h>
#include <string.h>
#include "image_button.h"



void back_button_action(ImageButton * const ib) {
    printf("Back Button containing \"%s\" got Pressed!\n", ib->image);
}

void forward_button_action(ImageButton * const ib) {
    printf("Forward Button containing \"%s\" got Pressed!\n", ib->image);
}

void ok_button_action(Button * const b) {
    printf("OK button got Pressed!\n");
}

void cancel_button_action(Button * const b) {
    printf("Cancel button got Pressed!\n");
}

void buttons_click_action(Button * const b) {
    printf("%s %s %s%s got pressed!\n\n", 
            Button_getText(b), Object_getClassName((Object *) b), 
            (Object_getClassId((Object *) b) == IMAGEBUTTON_CLASS_ID)? "containing " : "",
            (Object_getClassId((Object *) b) == IMAGEBUTTON_CLASS_ID)? ImageButton_getImage((ImageButton *) b) : ""
    );
    
    // printf("%s %s ", Button_getText(b), Object_getClassName((Object *) b));
    // if (Object_getClassId((Object *) b) == IMAGEBUTTON_CLASS_ID) {
    //     printf("containing %s ", ImageButton_getImage((ImageButton *) b));
    // }
    // printf("got pressed!\n\n");
}


int main() {
    Button okButton, cancelButton;
    ImageButton backButton, forwardButton;

    // Button_construct(&okButton, 0, 110, 70, 16, "OK", &ok_button_action);
    // Button_construct(&cancelButton, 80, 110, 70, 16, "Cancel", &cancel_button_action);

    // ImageButton_construct(&backButton, 0, 0, 100, 100, "Back", &back_button_action, "left_arrow.png");
    // ImageButton_construct(&forwardButton, 110, 0, 100, 100, "Forward", &forward_button_action, "right_arrow.png");

    Button_construct(&okButton, 0, 110, 70, 16, "OK", &buttons_click_action);
    Button_construct(&cancelButton, 80, 110, 70, 16, "Cancel", &buttons_click_action);

    ImageButton_construct(&backButton, 0, 0, 100, 100, "Back", (void (*)(ImageButton * const)) &buttons_click_action, "left_arrow.png");
    ImageButton_construct(&forwardButton, 110, 0, 100, 100, "Forward", (void (*)(ImageButton * const)) &buttons_click_action, "right_arrow.png");

    ImageButton_emulateClick(&backButton);
    Button_emulateClick((Button *) &forwardButton);

    Button_emulateClick(&okButton);
    Button_emulateClick(&cancelButton);

    printf("=============================================================\n");
    printf("Total objects created: %u\n", Object_getCount());

    return 0;
}
