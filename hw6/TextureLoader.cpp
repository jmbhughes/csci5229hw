#include "TextureLoader.h"
#include "Definitions.h"

/*
 *  Reverse n bytes
 */
static void reverse(void* x,const int n) {
    int k;
    char* ch = (char*)x;
    for (k=0;k<n/2;k++)
    {
        char tmp = ch[k];
        ch[k] = ch[n-1-k];
        ch[n-1-k] = tmp;
    }
}

unsigned int TextureLoader::get_name() {
    return texture;
}

TextureLoader::TextureLoader(const char* filename) {
    this->filename = filename;
    load_file();
    read_header();
    process_texture();
}

TextureLoader::TextureLoader(std::string filename) {
    this->filename = filename.c_str();
    load_file();
    read_header();
    process_texture();
}

void TextureLoader::fatal_error(const char* format , ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    exit(1);
}

void TextureLoader::load_file() {
    // Open file
    this->f = fopen(filename,"rb");
    if (!this->f) fatal_error("Cannot open file %s\n", filename);

    //  Check image magic
    if (fread(&magic,2,1,f)!=1) fatal_error("Cannot read magic from %s\n",filename);
    if (magic!=0x4D42 && magic!=0x424D) fatal_error("Image magic not BMP in %s\n",filename);
}

void TextureLoader::read_header() {
    //  Read header
    if (fseek(f,8,SEEK_CUR) || fread(&off,4,1,f)!=1 ||
        fseek(f,4,SEEK_CUR) || fread(&dx,4,1,f)!=1 || fread(&dy,4,1,f)!=1 ||
        fread(&nbp,2,1,f)!=1 || fread(&bpp,2,1,f)!=1 || fread(&k,4,1,f)!=1)
        fatal_error("Cannot read header from %s\n",filename);

    //  Reverse bytes on big endian hardware (detected by backwards magic)
    if (magic==0x424D)
    {
        reverse(&off,4);
        reverse(&dx,4);
        reverse(&dy,4);
        reverse(&nbp,2);
        reverse(&bpp,2);
        reverse(&k,4);
    }

    //  Check image parameters
    glGetIntegerv(GL_MAX_TEXTURE_SIZE,&max);
    if (dx<1 || dx>max) fatal_error("%s image width %d out of range 1-%d\n",filename,dx,max);
    if (dy<1 || dy>max) fatal_error("%s image height %d out of range 1-%d\n",filename,dy,max);
    if (nbp!=1)  fatal_error("%s bit planes is not 1: %d\n",filename,nbp);
    if (bpp!=24) fatal_error("%s bits per pixel is not 24: %d\n",filename,bpp);
    if (k!=0)    fatal_error("%s compressed files not supported\n",filename);

    #ifndef GL_VERSION_2_0
    //  OpenGL 2.0 lifts the restriction that texture size must be a power of two
    for (k=1;k<dx;k*=2);
    if (k!=dx) fatal_error("%s image width not a power of two: %d\n",filename,dx);
    for (k=1;k<dy;k*=2);
    if (k!=dy) fatal_error("%s image height not a power of two: %d\n",filename,dy);
    #endif
}

void TextureLoader::process_texture() {
    //  Allocate image memory
    size = 3*dx*dy;
    image = (unsigned char*) malloc(size);
    if (!image) fatal_error("Cannot allocate %d bytes of memory for image %s\n",size,filename);
    //  Seek to and read image
    if (fseek(f,off,SEEK_SET) || fread(image,size,1,f)!=1) fatal_error("Error reading data from image %s\n",filename);
    fclose(f);
    //  Reverse colors (BGR -> RGB)
    for (k=0;k<size;k+=3) {
        unsigned char temp = image[k];
        image[k]   = image[k+2];
        image[k+2] = temp;
    }

    //  Sanity check
    error_check("Before actually loading texture");

    //  Generate 2D texture
    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_2D,texture);

    //  Copy image
    glTexImage2D(GL_TEXTURE_2D,0,3,dx,dy,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    if (glGetError()) fatal_error("Error in glTexImage2D %s %dx%d\n",filename,dx,dy);

    //  Scale linearly when image size doesn't match
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    //  Free image memory
    free(image);
}