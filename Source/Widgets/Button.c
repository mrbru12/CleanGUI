#include "Button.h"

#include "../Debug.h"
#include "../Color.h"
#include "../Collision.h"
#include "Label.h"

#include <Vendor/Glad/include/glad/glad.h>

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

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, button->body_ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, button->border_ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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

}

void clean_button_display(clean_button* button, float x, float y)
{
    // bind(button->vao)
    // 
    // bind(button->border_vbo)
    // bufferdata(button_border_vbo, x + border, y + border, border_color)
    // bind(button->border_ebo)
    // gldrawElements(button->border)
    //
    // bind(button->body_vbo)
    // if button_on_collide
    //     if button_click
    //         bufferdata(button->body_vbo, x, y, click_color)
    //         on_click_callback()
    //     else
    //         bufferdata(button->body_vbo, x, y, highlit_color)
    //         on_hover_callback()
    // else
    //     bufferdata(button->body_vbo, x, y, idle_color)
    // bind(button->body_ebo)
    // gldrawElements(button->body)
    //
    // clean_label_display(buton->title, x + margin + border, y + margin + border)
}