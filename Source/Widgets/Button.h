#ifndef CLEAN_BUTTON_H
#define CLEAN_BUTTON_H

#include "../Controller.h"

// TODO:
/* O Button, por padrão, vai ter o seu tamanho de acordo com a regra geral para todos os Widgets (dependete da fonte e da margem)
 * Talvez dar a opção de setar os callbacks do Button e dos outros Widgets no próprio contrutor deles
 */

typedef struct clean_button clean_button;

// TODO: Por enquanto as posições vão ser em NDC pra ficar mais fácil de debugar com o OpenGL
clean_button* clean_button_create(clean_controller* controller, const char* title); // , float x, float y);
void clean_button_destroy(clean_button* button);

void clean_button_display(clean_button* button, float x, float y);

// void clean_button_set_callback(clean_button* button, clean_event event, [lambda]);

// TODO: Talvez usar enums (clean_property) em uma função como clean_button_set(clean_button* button, clean_property property, void* value) 
//       para não ter 500 funções diferentes para cada propriedade. Talvez fazer isso pras de "get" também
// void clean_button_set_vertex_shader(clean_button* button, const char* source);
// void clean_button_set_fragment_shader(clean_button* button, const char* source);
// void clean_button_set_shader_program(clean_button* button, unsigned int id);
// void clean_button_set_...(clean_button* button, ...);
// void clean_button_set_...(clean_button* button, ...);
// void clean_button_set_...(clean_button* button, ...);
// ...

// ... clean_button_get_...(clean_button* button);
// ... clean_button_get_...(clean_button* button);
// ... clean_button_get_...(clean_button* button);
// ...

#endif