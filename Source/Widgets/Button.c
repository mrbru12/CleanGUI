#include "Button.h"

#include "../Debug.h"
#include "../Color.h"
#include "Label.h"

#include <stdlib.h>
#include <stdio.h>

struct clean_button
{
    clean_label* title;
    // float x, y, w, h; 
    float margin_size;
    int vao;
    
    int body_vbo;
    int body_ebo;
    clean_color body_active_color;
    clean_color body_inactive_color;
    clean_color body_highlight_color;

    int border_vbo;
    int border_ebo;
    float border_size;
    clean_color border_color;
};

clean_button* clean_button_create(const char* title) // , float x, float y)
{

}

void clean_button_destroy(clean_button* button)
{

}