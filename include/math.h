#ifndef MATH_AHHHH
#define MATH_AHHHH
//Yeeted form stack overflow
#define CEILING_POS(X) ((X-(long)(X)) > 0 ? (long)(X+1) : (long)(X))
#define CEILING_NEG(X) ((X-(long)(X)) < 0 ? (long)(X-1) : (long)(X))
#define CEILING(X) (((X) > 0) ? CEILING_POS(X) : CEILING_NEG(X))

#define FLOOR(X) (((X) > 0) ? CEILING_POS(X) : CEILING_NEG(X))
#endif
