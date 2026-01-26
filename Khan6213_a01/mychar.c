#include "mychar.h"
/*
--------------------------------------------------
Project: a1q1
File:    mychar.c
Author:  Ayaan Khan
Version: 2026-01-14
--------------------------------------------------
*/
/**
 * Determine the type of a character.
 *
 * @param c - input character
 * @return 0 if `c` is a digit
 *        1 if `c` is an arithmetic operator
 *        2 if `c` is the left parenthesis `(`
 *        3 if `c` is the right parenthesis `)`
 *        4 if `c` is an English letter
 *       -1 otherwise
 */
int mytype(char c){
int r = -1;
if(c >= '0' && c <= '9')
r = 0;
else if ((c == '+')|| (c == '-')|| (c == '*')|| (c == '/')|| (c == '%'))
r = 1;
else if (c == '(' )
r = 2;
else if (c == ')' )
r = 3;
else if ((c >= 'a' && c <= 'z' )|| (c >= 'A' && c <= 'Z'))
r = 4;

return r;
}


/**
 * Flip the case of an English letter.
 *
 * @param c - input character
 * @return the uppercase/lowercase counterpart if `c` is an English letter;
 *         otherwise returns `c` unchanged.
 */
char case_flip(char c){
int distance = 'a' - 'A';
if(c >= 'a' && c <= 'z')
c = ( c - distance );
else if(c >= 'A' && c <= 'Z')
c = (c + distance);
return c;
}

/**
 * Convert a digit character to its integer value.
 *
 * @param c - input character
 * @return the integer value if `c` is a digit character; otherwise -1.
 */
int digit_to_int(char c){
    if (c >= '0' && c <= '9')
    return ( c - '0');
    else
        return -1;

}
