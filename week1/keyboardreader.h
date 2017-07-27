#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#ifndef KEYBOARDREADER_H
#define KEYBOARDREADER_H
#define DECIMAL 10
#define ENDCHARS 2
#define LINELEN 80
enum input_result
{
    SUCCESS, FAILURE, EOB=EOF
};
void clear_buffer(void);
enum input_result get_int(const char *, int* /* out */);
enum input_result get_string(const char *, int len, char*);
enum input_result get_double(const char *, double*);
#endif /*  KEYBOARDREADER_H */
