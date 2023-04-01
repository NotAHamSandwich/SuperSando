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
            void makeImage();
            void input(SDL_Event e);
            void displayTexture(const char *file_path);
            int loadTexture(char* fileName);

            inline int getWidth() const { return m_Width; }
            inline int getHeight() const { return m_Height; }
    };

} }

#endif