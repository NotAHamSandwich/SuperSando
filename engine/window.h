#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "renderer.h"

namespace engine { namespace graphics {

    class Window {
        private:
            const char *m_Title;
            int m_Width, m_Height;
            SDL_Window *m_window;
            SDL_Renderer *m_renderer;
            bool m_Closed;
            bool init();
        public:
            Window(const char *m_Title, int width, int height);
            ~Window();
            bool closed() const;
            void refresh();
            void draw();
            int loadTexture(char* fileName);

            inline int getWidth() const { return m_Width; }
            inline int getHeight() const { return m_Height; }
    };

} }

#endif