#ifndef CLEAN_CONTROLLER_H
#define CLEAN_CONTROLLER_H

typedef struct GLFWwindow GLFWwindow;

typedef struct clean_controller clean_controller;

// int clean_init();

// TODO: Nessa função vão ser setadas várias constantes (como as shaders padrão dos Widgets, o glViewport(), a glBlendFunc(), etc...)
clean_controller* clean_controller_create(GLFWwindow* window); // Talvez inicializar tudo dentro dessa func
void clean_controller_destroy(clean_controller* controller);

// TODO: Talvez mudar o nome desse arquivo (para Input ou algo assim, algo que inclua e represente bem
//       tudo o que está aqui) e imbutir os códigos pra input da API do Windos aqui, pra não ficar mexendo
//       diretamente com a API em cada implementação de um Widget
int clean_controller_cursor_on_rect(clean_controller* controller, clean_rect rect);
int clean_controller_cursor_click(clean_controller* controller);

GLFWwindow* clean_controller_get_window(clean_controller* controller);
int clean_controller_window_has_focus(clean_controller* controller);

#endif