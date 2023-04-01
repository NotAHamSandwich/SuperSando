#include "texture.h"

namespace engine { namespace graphics {
    Texture::Texture(SDL_Renderer *renderer, const char *file_path)
    {
        m_surface = IMG_Load(file_path);
        //printf(file_path);
        if (m_surface == NULL)
        {
            printf( "unable to load image %s! SDL_image Error: %s\n", IMG_GetError() );
            return;
        }
        m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
        if (m_texture == NULL)
        {
            printf("poh no your texture cant load");
            return;
        }
        SDL_FreeSurface (m_surface);
    }
    Texture::~Texture()
    {

    }
} }