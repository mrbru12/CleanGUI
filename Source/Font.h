#ifndef CLEAN_FONT_H
#define CLEAN_FONT_H

typedef struct clean_font clean_font;

clean_font* clean_font_create(const char* path, float size);
void clean_font_destroy(clean_font* font);

#endif