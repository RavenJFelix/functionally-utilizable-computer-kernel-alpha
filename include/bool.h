#ifndef BOOL_H
#define BOOL_H
/* Many years ago, when the earth was still cooling, we used this: */

typedef enum
{
    false = ( 1 == 0 ),
    true = ( ! false )
} bool;



/* It has always worked for me. */


#endif
