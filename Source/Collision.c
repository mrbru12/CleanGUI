#include "Collision.h"

#include <Windows.h>

int clean_point_on_rect(clean_point point, clean_rect rect)
{
    return (point.x >= rect.x && point.x <= rect.x + rect.w) && (point.y >= rect.y && point.y <= rect.y + rect.h);
}

int clean_cursor_on_rect(clean_rect rect)
{
    POINT window_mouse_point;
    GetCursorPos(&window_mouse_point);

    HWND window_handle = GetActiveWindow();
    ScreenToClient(window_handle, &window_mouse_point);
    
    // TODO: Talvez usar o viewport pra ficar mais dinâmico
    // int* viewport = malloc(4 * sizeof(int));
    // glGetIntegerv(GL_VIEWPORT, viewport);
    RECT window_rect; 
    GetClientRect(window_handle, &window_rect);
    
    clean_point ndc_mouse_point;
    ndc_mouse_point.x = (((2.0f * window_mouse_point.x) - (2.0f * window_rect.left)) / window_rect.right) - 1.0f;
    ndc_mouse_point.y = (((2.0f * window_mouse_point.y) - (2.0f * window_rect.top)) / window_rect.bottom) - 1.0f;

    return clean_point_on_rect(ndc_mouse_point, rect);
}

int clean_cursor_click()
{
    // HWND window_handle = GetActiveWindow();
    
    // return DefWindowProc(window_handle, WM_LBUTTONDOWN, MK_LBUTTON, 0);

    return GetKeyState(VK_LBUTTON);
}