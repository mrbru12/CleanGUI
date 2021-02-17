#include "Controller.h"

#include "Debug.h"
#include "Collision.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>

struct clean_controller
{
    GLFWwindow* window;
};

clean_controller* clean_controller_create(GLFWwindow* window)
{
    clean_controller* controller = malloc(sizeof(clean_controller));

    if (controller)
    {
        controller->window = window;
        
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            CLEAN_ERROR_VALUE("Glad", "Failed to initialize Glad!", NULL);

        int window_width, window_height;
        glfwGetWindowSize(window, &window_width, &window_height);
        glViewport(0, 0, window_width, window_height);

        return controller;
    }

    CLEAN_ERROR_VALUE("Button", "Failed to allocate memory for clean_button!", NULL);
}

void clean_controller_destroy(clean_controller* controller)
{
    free(controller);
}

int clean_cursor_on_rect(clean_controller* controller, clean_rect rect)
{
    clean_point window_mouse_point;
    glfwGetCursorPos(clean_controller_get_window(controller), &window_mouse_point.x, &window_mouse_point.y);
    
    // TODO: Talvez usar o viewport pra ficar mais dinâmico
    // int* viewport = malloc(4 * sizeof(int));
    // glGetIntegerv(GL_VIEWPORT, viewport);
    clean_rect viewport_rect; 
    glGetIntegerv(GL_VIEWPORT, &viewport_rect);
    
    clean_point ndc_mouse_point;
    ndc_mouse_point.x = (((2.0f * window_mouse_point.x) - (2.0f * viewport_rect.x)) / viewport_rect.w) - 1.0f;
    ndc_mouse_point.y = -((((2.0f * window_mouse_point.y) - (2.0f * viewport_rect.y)) / viewport_rect.h) - 1.0f);

    return clean_point_on_rect(ndc_mouse_point, rect);
}

int clean_cursor_click(clean_controller* controller)
{
    return glfwGetMouseButton(clean_controller_get_window(controller), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
}

GLFWwindow* clean_controller_get_window(clean_controller* controller)
{
    return controller->window;
}

int clean_controller_window_has_focus(clean_controller* controller)
{
    return glfwGetWindowAttrib(controller->window, GLFW_FOCUSED);
}