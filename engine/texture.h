#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace engine { namespace graphics {

    class Texture
    {
    private:
        SDL_Renderer *m_renderer;
    public:
        Texture(SDL_Renderer *renderer, const char *file_path);
        ~Texture();
        SDL_Texture *m_texture;
        SDL_Surface *m_surface;
    };
    

} }


#endif