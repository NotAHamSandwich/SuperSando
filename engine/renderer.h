#ifndef RENDERER_H
#define RENDERER_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


namespace engine { namespace graphics{
    
    class Renderer {
        public:
            SDL_Renderer *m_renderer;
            Renderer(SDL_Window  *window);
            
            ~Renderer();
        private:
            SDL_Window *m_window;
            bool init();

        
        
    };
    class Rect {
            public:
                Rect(int x, int y, int Height, int Width);
                int m_x, m_y;
                int m_height, m_width;
                SDL_Rect m_rect;
    };
    

} }


#endif