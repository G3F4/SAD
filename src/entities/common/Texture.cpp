//#include "Texture.hpp"
//
//Texture::Texture(void){
//	m_texture = nullptr;
//    m_surface = nullptr;
//	m_file = "assets/images/no-img.png";
//	m_id = "no-img";
//    m_pixels = 0;
//    m_bpp = 0;
//}
//
//bool Texture::create_empty_from_surface(std::string id,SDL_Surface* surface, int x, int y) {
//    m_id = id;
////    m_surface = SDL_CreateRGBSurface(
////            SDL_SWSURFACE,
////            width,
////            height,
////            surface->format->BitsPerPixel,
////            surface->format->Rmask,
////            surface->format->Gmask,
////            surface->format->Bmask,
////            0 );
//    m_surface = SDL_CreateRGBSurfaceFrom(
//            surface->pixels,//void*  pixels,
//            surface->w,//int    width,
//            surface->h,//int    height,
//            surface->format->BitsPerPixel,//int    depth,
//            surface->pitch,//int    pitch,
//            surface->format->Rmask,//Uint32 Rmask,
//            surface->format->Gmask,//Uint32 Gmask,
//            surface->format->Bmask,//Uint32 Bmask,
//            surface->format->Amask);//Uint32 Amask)
//    m_texture = SDL_CreateTextureFromSurface(Application::Instance().get_render(), m_surface);
//
//    // create SDL_Surface. We will be using this to create texture and to manipulate pixels
//    if ( m_surface == NULL) {
//        std::cout << "Surface loading error! Error message: " << SDL_GetError() << std::endl;
//    } else {
////        m_texture = IMG_LoadTexture(Application::Instance().get_render(),
////                file_path.c_str());
//        // get the set of all pixels from surface in form of array
//        m_pixels = (Uint32 *)m_surface->pixels;
//        m_bpp = m_surface->format->BytesPerPixel;
//        m_texture = SDL_CreateTextureFromSurface(Application::Instance().get_render(), m_surface);
//
//        if(m_texture == nullptr) {
//            std::cout << "Texture loading error! Error message: " << IMG_GetError() << std::endl;
//            return false;
//        } else {
//            this->set_x_position(x);
//            this->set_y_position(y);
//            SDL_QueryTexture(m_texture, NULL, NULL, &m_box.w, &m_box.h);
//            std::cout << "Empty texture created | "
//                    << "Id: " << get_id()
//                    << " | Size: " << get_width() << " x " << get_height()
//                    << " | Position: " << get_x_position() << " x " << get_y_position()
//                    << std::endl;
//            return true;
//        }
//    }
//    // if we get here means somothing went wrong!
//    return false;
//}
//
//void Texture::update() {
//    m_texture = SDL_CreateTextureFromSurface(Application::Instance().get_render(), m_surface);
//}
//
//void Texture::set_pixel(Uint32 pixel, int x, int y) {
//    //Convert the pixels to 32 bit
////    Uint32 *pixels = (Uint32 *)surface->pixels;
//
//    //Set the pixel
////    pixels[ ( y * surface->w ) + x ] = pixel;
////    m_pixels[ ( y * m_surface->w ) + x ] = pixel;
//}
//
//void Texture::set_pixel(int R, int G, int B, int x, int y) {
////    m_pixels[ ( y * m_surface->w ) + x ] = SDL_MapRGB(m_surface->format, (Uint8)R, (Uint8)G, (Uint8)B);
//}
//
//Uint32 Texture::get_pixel(int x, int y) {
//    /* Here p is the address to the pixel we want to retrieve */
//    Uint8 *p = (Uint8 *)m_surface->pixels + y * m_surface->pitch + x * m_bpp;
//
//    switch(m_bpp) {
//        case 1:
//            return *p;
//        case 2:
//            return *(Uint16 *)p;
//        case 3:
////        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
//            return p[0] << 16 | p[1] << 8 | p[2];
////            else
////            return p[0] | p[1] << 8 | p[2] << 16;
////            break;
//        case 4:
//            return *(Uint32 *)p;
//        default:
//            return 0;       /* shouldn't happen, but avoids warnings */
//    }
//}
//
//void Texture::move_pixel(int x1, int y1, int x2, int y2) {
//
//}
//
//void Texture::copy_pixel(int x1, int y1, int x2, int y2) {
//
//}
//
//bool Texture::load_to_manipulate(std::string id, std::string file){
//    m_id = id;
//    m_file = file;
//    std::string file_path = "assets/images/" + m_file;
//    //The final texture
//    m_texture = NULL;
//
//    //Load image at specified path
//    SDL_Surface* loadedSurface = IMG_Load( file_path.c_str() );
//    if( loadedSurface == NULL )
//    {
//        std::cout << "Unable to load image " << file_path.c_str() << " !SDL_image Error: "  << IMG_GetError() << std::endl;
//    }
//    else
//    {
//        //Convert surface to display format
//        SDL_Surface* formattedSurface = SDL_ConvertSurface( loadedSurface, SDL_GetWindowSurface( Application::Instance().get_window())->format, NULL );
//        if( formattedSurface == NULL )
//        {
//            std::cout << "Unable to convert loaded surface to display format! SDL Error: " << SDL_GetError() << std::endl;
//        }
//        else
//        {
//            //Create blank streamable texture
//            m_texture = SDL_CreateTexture( Application::Instance().get_render(), SDL_GetWindowPixelFormat( Application::Instance().get_window()), SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h );
//            if( m_texture == NULL )
//            {
//                std::cout << "Unable to create blank texture! SDL Error: " << SDL_GetError() << std::endl;
//            }
//            else
//            {
//                //Lock texture for manipulation
//                SDL_LockTexture( m_texture, NULL, &m_pixels, &m_pitch );
//
//                //Copy loaded/formatted surface pixels
//                memcpy( m_pixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h );
//
//                //Unlock texture to update
//                SDL_UnlockTexture( m_texture );
//                m_pixels = NULL;
//
//                //Get image dimensions
//                this->set_width(formattedSurface->w);
//                this->set_height(formattedSurface->h);
//            }
//
//            //Get rid of old formatted surface
//            SDL_FreeSurface( formattedSurface );
//        }
//
//        //Get rid of old loaded surface
//        SDL_FreeSurface( loadedSurface );
//    }
//
//    //Return success
//    return m_texture != NULL;
//
//}
//bool Texture::load(std::string id, std::string file){
//	m_id = id;
//	m_file = file;
//	std::string file_path = "assets/images/" + m_file;
//    // create SDL_Surface. We will be using this to create texture and to manipulate pixels
//    m_surface = IMG_Load(file_path.c_str());
//    if ( m_surface == NULL) {
//        std::cout << "Surface loading error! Error message: " << SDL_GetError() << std::endl;
//    } else {
////        m_texture = IMG_LoadTexture(Application::Instance().get_render(),
////                file_path.c_str());
//        // get the set of all pixels from surface in form of array
//        m_pixels = (Uint32 *)m_surface->pixels;
//        m_bpp = m_surface->format->BytesPerPixel;
//        m_texture = SDL_CreateTextureFromSurface(Application::Instance().get_render(), m_surface);
//
//        if(m_texture == nullptr) {
//            std::cout << "Texture loading error! Error message: " << IMG_GetError() << std::endl;
//            return false;
//        } else {
//            SDL_QueryTexture(m_texture, NULL, NULL, &m_box.w, &m_box.h);
//            std::cout << "Texture loaded | "
//                    << "Id: " << get_id()
//                    << " | Size: " << get_width() << " x " << get_height()
//                    << " | Position: " << get_x_position() << " x " << get_y_position()
//                    << " | File: " << file_path << std::endl;
//            return true;
//        }
//    }
//    // if we get here means somothing went wrong!
//    return false;
//
//}
//
//void Texture::render(void) {
//	SDL_RenderCopy(Application::Instance().get_render(), m_texture, NULL, &m_box);
//}Texture::Texture(string ID, string file, int x, int y, int width, int height, int state){


#include "../../singletons/Application.hpp"
#include "Texture.hpp"

Texture::Texture(std::string ID, std::string file, int x, int y, int width, int height, std::string window_ID, double angle, SDL_RendererFlip flip, bool state):
                BaseObject(ID,x,y,width,height,state), m_file(file), m_angle(angle), m_flip(flip)
{
    m_texture = nullptr;
    m_window_ID = window_ID;
    m_pivot_point.x = m_box.w / 2;
    m_pivot_point.y = m_box.h / 2;
    load(); // has to called always after initialization of ALL FIELDS!!
    if( m_texture == nullptr) {
        std::cout << "Texture not loaded." << std::endl;
    }
}

bool Texture::load() {
    m_texture = IMG_LoadTexture(Application::Instance().get_window(m_window_ID)->get_renderer(), m_file.c_str());
    if (m_texture == NULL) {
        std::cout << IMG_GetError() << std::endl;
        return false;
    } else {
        std::cout << "File: " << m_file << " loaded." << std::endl;
        return true;
    }
}

void Texture::render() {
    SDL_RenderCopyEx(Application::Instance().get_window(m_window_ID)->get_renderer(), m_texture, NULL, &m_box, m_angle, &m_pivot_point, m_flip);
}

void Texture::flip_vertiacally() {
    if (m_flip == SDL_FLIP_NONE) {
        m_flip = SDL_FLIP_VERTICAL;
    } else if ( m_flip == SDL_FLIP_VERTICAL) {
        m_flip = SDL_FLIP_NONE;
    } else if ( m_flip == SDL_FLIP_HORIZONTAL) {
        m_flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
    }
}

void Texture::flip_horizontally() {
    if (m_flip == SDL_FLIP_NONE) {
        m_flip = SDL_FLIP_HORIZONTAL;
    } else if ( m_flip == SDL_FLIP_HORIZONTAL) {
        m_flip = SDL_FLIP_NONE;
    } else if ( m_flip == SDL_FLIP_VERTICAL) {
        m_flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
    }
}
