#include "Button.h"

#include "../Debug.h"
#include "../Color.h"
#include "../Collision.h"
#include "Label.h"

#include <glad/glad.h>

#include <stdlib.h>
#include <stdio.h>

// TODO: Colocar esses #define defaults em algum header pra incluir mais fácil. Fazer uns gerais ao invés de ser para 
//       um Widget específico(exemplo CLEAN_DEFAULT_MARGIN_SIZE ao invés de CLEAN_DEFAULT_BUTTON_MARGIN_SIZE)

#define CLEAN_DEFAULT_BUTTON_MARGIN_SIZE 0.1f

#define CLEAN_DEFAULT_BUTTON_BODY_ACTIVE_COLOR (clean_color){ 0.9f, 0.5f, 0.6f }
#define CLEAN_DEFAULT_BUTTON_BODY_INACTIVE_COLOR (clean_color){ 0.6f, 0.6f, 0.6f }
#define CLEAN_DEFAULT_BUTTON_BODY_HIGHLIGHT_COLOR (clean_color){ 0.8f, 0.8f, 0.8f }

#define CLEAN_DEFAULT_BUTTON_BORDER_SIZE 0.2f
#define CLEAN_DEFAULT_BUTTON_BORDER_COLOR (clean_color){ 0.0f, 0.0f, 0.0f }

struct clean_button
{
    clean_label* title;
    float margin_size;
    unsigned int vao;
    // unsigned int shader_program;

    // on_click_callback;
    // on_hover_callback;
    
    unsigned int body_vbo;
    unsigned int body_ebo;
    clean_color body_active_color;
    clean_color body_inactive_color;
    clean_color body_highlight_color;
    
    unsigned int border_vbo;
    unsigned int border_ebo;
    float border_size;
    clean_color border_color;
};

clean_button* clean_button_create(const char* title)
{
    clean_button* button = malloc(sizeof(clean_button));

    if (button)
    {
        // === [STYLE] ===

        button->title = clean_label_create(title);
        button->margin_size = CLEAN_DEFAULT_BUTTON_MARGIN_SIZE;
        
        button->body_active_color = CLEAN_DEFAULT_BUTTON_BODY_ACTIVE_COLOR;
        button->body_inactive_color = CLEAN_DEFAULT_BUTTON_BODY_INACTIVE_COLOR;
        button->body_highlight_color = CLEAN_DEFAULT_BUTTON_BODY_HIGHLIGHT_COLOR;

        button->border_size = CLEAN_DEFAULT_BUTTON_BORDER_SIZE;
        button->border_color = CLEAN_DEFAULT_BUTTON_BORDER_COLOR;

        // === [BUFFER GENERATION] ===

        glGenVertexArrays(1, &button->vao);

        glGenBuffers(1, &button->body_vbo);
        glGenBuffers(1, &button->body_ebo);

        glGenBuffers(1, &button->border_vbo);        
        glGenBuffers(1, &button->border_ebo);

        // === [VERTEX ARRAY] ===

        glBindVertexArray(button->vao);

        // Position attribute: (X, Y)
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);

        // Color attribute: (R, G, B, A)
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));

        // === [ELEMENT BUFFER] ===

        unsigned int indices_buffer[] = {
            0, 1, 2,
            2, 3, 0
        };

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, button->body_ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_buffer), indices_buffer, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, button->border_ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_buffer), indices_buffer, GL_STATIC_DRAW);

        // === [UNBIND BUFFERS] ===

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        return button;
    }
    else
        CLEAN_ERROR_VALUE("Button", "Failed to allocate memory for clean_button!", NULL);
}

void clean_button_destroy(clean_button* button)
{
    clean_label_destroy(button->title);

    glDeleteVertexArrays(1, &button->vao);

    glDeleteBuffers(1, &button->body_vbo);
    glDeleteBuffers(1, &button->body_ebo);

    glDeleteBuffers(1, &button->border_vbo);
    glDeleteBuffers(1, &button->border_ebo);

    free(button);
}

void clean_button_display(clean_button* button, float x, float y)
{    
    glBindVertexArray(button->vao);

    // TODO: glUseProgram(button->shader)

    // === [RENDER BORDER] ===

    // TODO: Usar as structs clean_point e clean_rect pra deixar esses buffers mais simples
    float border_buffer[] = {
        x, y, 
        button->border_color.r, button->border_color.g, button->border_color.b, button->border_color.a,

        x + clean_label_get_width(button->title) + button->margin_size * 2.0f + button->border_size * 2.0f, y, 
        button->border_color.r, button->border_color.g, button->border_color.b, button->border_color.a,

        x + clean_label_get_width(button->title) + button->margin_size * 2.0f + button->border_size * 2.0f, y + clean_label_get_height(button->title) + button->margin_size * 2.0f + button->border_size * 2.0f,
        button->border_color.r, button->border_color.g, button->border_color.b, button->border_color.a,

        x, y + clean_label_get_height(button->title) + button->margin_size * 2.0f + button->border_size * 2.0f, 
        button->border_color.r, button->border_color.g, button->border_color.b, button->border_color.a
    };

    glBindBuffer(GL_ARRAY_BUFFER, button->border_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(border_buffer), border_buffer, GL_DYNAMIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, button->border_ebo);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

    // === [CALL EVENTS AND RENDER BODY] ===

    clean_color body_state_color;

    clean_rect body_rect;
    body_rect.x = x + button->margin_size;
    body_rect.y = y + button->margin_size;
    body_rect.w = clean_label_get_width(button->title) + button->margin_size * 2;
    body_rect.h = clean_label_get_height(button->title) + button->margin_size * 2;

    if (clean_cursor_on_rect(body_rect))
    {
        if (clean_cursor_click())
        {
            body_state_color = button->body_active_color;

            // on_click_callback();
        }
        else
        {
            body_state_color = button->body_highlight_color;

            // on_hover_callback();
        }
    }
    else
        body_state_color = button->body_inactive_color;

    float body_buffer[] = {
        x + button->border_size, y + button->border_size, 
        body_state_color.r, body_state_color.g, body_state_color.b, body_state_color.a,

        x + clean_label_get_width(button->title) + button->margin_size * 2.0f + button->border_size, y + button->border_size, 
        body_state_color.r, body_state_color.g, body_state_color.b, body_state_color.a,

        x + clean_label_get_width(button->title) + button->margin_size * 2.0f + button->border_size, y + clean_label_get_height(button->title) + button->margin_size * 2.0f + button->border_size, 
        body_state_color.r, body_state_color.g, body_state_color.b, body_state_color.a,

        x + button->border_size, y + clean_label_get_height(button->title) + button->margin_size * 2.0f + button->border_size,
        body_state_color.r, body_state_color.g, body_state_color.b, body_state_color.a
    };

    glBindBuffer(GL_ARRAY_BUFFER, button->body_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(body_buffer), body_buffer, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, button->body_ebo);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

    // === [RENDER TITLE] ===

    clean_label_display(button->title, x + button->margin_size + button->border_size, y + button->margin_size + button->border_size);
}