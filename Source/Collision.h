#ifndef CLEAN_COLLISION_H
#define CLEAN_COLLISION_H

typedef struct clean_point
{
    float x, y;
} clean_point;

typedef struct clean_rect
{
    float x, y, w, h;
} clean_rect;

int clean_point_on_rect(clean_point point, clean_rect rect);

// TODO: Talvez mudar o nome desse arquivo (para Input ou algo assim, algo que inclua e represente bem
//       tudo o que está aqui) e imbutir os códigos pra input da API do Windos aqui, pra não ficar mexendo
//       diretamente com a API em cada implementação de um Widget
int clean_cursor_on_rect(clean_rect rect);
int clean_cursor_click();

#endif