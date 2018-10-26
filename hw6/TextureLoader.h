#ifndef HW6_TEXTURELOADER_H
#define HW6_TEXTURELOADER_H

#include <string>
#include <iostream>

class TextureLoader {
    // Loads a BMP texture
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
    void load_file();          // Open file and throw error if it does not exist
    void read_header();        // Read the bmp header and throw error if it loads incorrectly
    void process_texture();    // Process the image putting the texture contents in the appropriate data area
    void fatal_error(const char* format, ...); // throw a fatal error with a message
public:
    TextureLoader(const char* filename); // load a texture from a filename string
    TextureLoader(std::string filename); // load a texture from a filename string
    unsigned int get_name();  // return the unsigned int that is the texture name
};
#endif //HW6_TEXTURELOADER_H
