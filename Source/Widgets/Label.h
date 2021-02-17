#ifndef CLEAN_LABEL_H
#define CLEAN_LABEL_H

#include "../Font.h"

typedef struct clean_label clean_label;

// TODO: Usar a fonte padrão se o parâmetro for NULL
clean_label* clean_label_create(/* clean_controller* controller, */ const char* text);
void clean_label_destroy(clean_label* label);

void clean_label_display(clean_label* label, float x, float y);

// void clean_label_set_font(clean_label* label, clean_font* font);

float clean_label_get_width(clean_label* label);
float clean_label_get_height(clean_label* label);

#endif