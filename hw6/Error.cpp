#include "Definitions.h"

/*
 *  Print any errors encountered
 *  copied from Schreuder's example 5
 */
void error_check(const char* where) {
    int err = glGetError();
    if (err) fprintf(stderr,"ERROR: %s [%s]\n",gluErrorString(err),where); //TODO: change to iostream
}
