#ifndef HW6_TEXTURELOADER_H
#define HW6_TEXTURELOADER_H

#include <string>
#include <iostream>

class TextureLoader {
private:
    const char*    filename;   // name of where to load string from
    unsigned int   texture;    // Texture name
    FILE*          f;          // File pointer
    unsigned short magic;      // Image magic
    unsigned int   dx,dy,size; // Image dimensions
    unsigned short nbp,bpp;    // Planes and bits per pixel
    unsigned char* image;      // Image data
    unsigned int   off;        // Image offset
    unsigned int   k;          // Counter
    int            max;        // Maximum texture dimensions
    void load_file();
    void read_header();
    void process_texture();
    void fatal_error(const char* format, ...);
public:
    TextureLoader(const char* filename);
    TextureLoader(std::string filename);
    unsigned int get_name();
};
#endif //HW6_TEXTURELOADER_H
