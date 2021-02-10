#ifndef CLEAN_LABEL_H
#define CLEAN_LABEL_H

#include "../Font.h"

typedef struct clean_label clean_label;

// TODO: Usar a fonte padrão se o parâmetro for NULL
clean_label* clean_label_create(const char* text, clean_font* font, float x, float y);
void clean_label_destroy(clean_label* button);

#endif