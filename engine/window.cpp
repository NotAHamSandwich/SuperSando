#include "window.h"

#include <stdio.h>
#include <iostream>

namespace engine { namespace graphics {    

    Window::Window(const char *title, int width, int height) 
    {
        m_Title = title;
        m_Width = width;
        m_Height = height;
        if(!init())
        {
            SDL_Quit();
        }
    }

    bool Window::init()
    {
        if(SDL_Init( SDL_INIT_EVERYTHING ) < 0) 
        {
            printf( " SDL Could not initialize! SDL_Error: %s\n", SDL_GetError() );
            return false;
        }
        else
        {
            //SDL_Surface* screenSurface = NULL;
            m_window = SDL_CreateWindow(m_Title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED , m_Width, m_Height, SDL_WINDOW_OPENGL);
            if( m_window == NULL)
            {
                printf( "Window could not be create! SDL_Error %s\n", SDL_GetError() );
                SDL_Quit();
                return false;
            }
            Renderer renderer(m_window);
            m_renderer = renderer.m_renderer;
            std::cout << m_renderer << " no :(" << std::endl;
            
        }
        return true;
    }

    Window::~Window()
    {
        SDL_Quit();
    }
    bool Window::closed() const
    {
        return false;
    }
    void Window::refresh()
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        SDL_UpdateWindowSurface(m_window);
    }
    void Window::draw()
    {
        SDL_RenderClear(m_renderer);
        Rect rect(50, 50, 200, 200);
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(m_renderer, &rect.m_rect);
        SDL_SetRenderDrawColor(m_renderer, 0,0,0,255);
        SDL_RenderPresent(m_renderer);
    }

} }