#include "keyboardreader.h"

void clear_buffer(void)
{
    int ch;
    while(ch = getc(stdin), ch!='\n' && ch!=EOF)
        ;
    clearerr(stdin);
}

enum input_result get_string(const char * prompt, int len, 
    char * output)
{
    printf("%s", prompt);
    if(!fgets(output, len + ENDCHARS, stdin))
    {
        return EOB;
    }
    if(*output == '\n')
    {
        return EOB;
    }
    if(output[strlen(output)-1] != '\n')
    {
        fprintf(stderr, "Error: buffer overflow. try again.\n\n");
        clear_buffer();
        return get_string(prompt, len, output);
    }
    output[strlen(output)-1]=0;
    return SUCCESS;
}

enum input_result get_int(const char * prompt, int * output)
{
    char outputstr[LINELEN + ENDCHARS];
    enum input_result result;
    long lresult;
    char * end;
    
    while(result = get_string(prompt, LINELEN + ENDCHARS, outputstr), 
        result == FAILURE)
    if(result == EOB)
    {
        return EOB;
    }
    lresult = strtol(outputstr, &end, DECIMAL);
    while(isspace(*end))
    {
        end++;
    }
    if(*end != 0)
    {
        fprintf(stderr, "Error: invalid number entered. "
            "Please try again.\n");
        return get_int(prompt, output);
    }
    if(lresult < INT_MIN || lresult > INT_MAX)
    {
        fprintf(stderr, "Error: value out of range for an int entered."
            " Please try again.");
        return get_int(prompt, output);
    }
    *output = (int) lresult;
    return SUCCESS;
}

enum input_result get_double(const char * prompt, double * result)
{
    enum input_result i_result;
    char input[LINELEN + ENDCHARS];
    char * end;
    while (i_result = get_string(prompt, LINELEN, input), 
        i_result == FAILURE)
    {
        fprintf(stderr, "Error: line was too long. Please try again.\n\n");
    }
    *result = strtod(input, &end);
    while (isspace(*end))
    {
        ++end;
    }
    if(*end != 0)
    {
        fprintf(stderr, "Error: input was not a valid double. Please "
            "try again.\n\n");
        return get_double(prompt, result);
    }
    return SUCCESS;
}
