#include <string>
#include <sstream>
#include <cassert>
#include <time.h>

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
//#include <GL/glut.h>         // OpenGL library we copied
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // _WIN32

#include "uiDraw.h"
#include "uiInteract.h"

using namespace std;

// Colors of game elements
const int RGB_WHTIE[] = {255, 255, 255}; // for the background
const int RGB_BLCAK[] = {0, 0, 0}; // for the dashes, pole and shapes
const int RGB_RED[] = { 256, 0, 0 }; // for wrong letters

/*************************************************************************
 * DRAW TEXT
 * Draw text using a simple bitmap font
 *   INPUT  topLeft   The top left corner of the text
 *          text      The text to be displayed
 ************************************************************************/

