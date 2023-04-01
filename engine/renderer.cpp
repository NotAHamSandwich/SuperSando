#include "renderer.h"

namespace engine { namespace graphics {
    
    Renderer::Renderer(SDL_Window *window)
    {
        m_window = window;
        if (!init())
        {
            printf("sorry, the renderer broke probably a code leak");
            return;
        }
    }

    Renderer::~Renderer()
    {

    }

    Rect::Rect(int x, int y, int Height, int Width)
    {

        m_x = x;
        m_y = y;
        m_height = Height;
        m_width = Width;
        m_rect.x = m_y;
        m_rect.y = m_y;
        m_rect.h = m_height;
        m_rect.w = m_width;

    }

    bool Renderer::init()
    {
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_SOFTWARE);
        if (m_renderer == NULL)
        {
            printf("something went wrong with the sdl renderer");
            return false;
        }
        return true;
    }

} }
