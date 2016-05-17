/* 
 * CS:APP Data Lab 
 * 
 * <Shannon Phu 404403562>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
/* Take into account cases 0 and -1. Then mask x so that only the left-most 1 will appear in x. Look at only the least-significant 16 bits and check for 0s. If the whole section contains only zeros, add 16 to the return value and shift right by 16 to now ignore those 0s and move onto the next portion of the 32-bit number. Else don't shift and examine a saller chunk of the number. Repeat this check for 0s and shfits for the next 16, 8, 4, 2, and 1-bit chunk. Add all the shifts that occured and return that count. */
   int mask16, mask8, mask4, mask2, sign, isZero, ifNotZero, m;
   int R16, R8, R4, R2, R1;
   int add16Right, add8Right, add4Right, add2Right, add1Right;

    sign = (x >> 31);
    x ^= sign;
    isZero = !x;
    ifNotZero = ((!!x) << 31) >> 31; 

    x |= (x>>1);
	  x |= (x>>2);
	  x |= (x>>4);
	  x |= (x>>8);
	  x |= (x>>16);
    m = (x >> 1) & (~0 ^ (1 << 31));
	  x ^= m;
   
    mask16 = 0xFF | (0xFF << 8); 
    R16 = x & mask16; 
    R16 = !R16;
    R16 = (R16 << 31) >> 31;
    add16Right = 16 & R16; 
    
    x = x >> add16Right; 
    
    mask8 = 0xFF;
    R8 = x & mask8;
    R8 = !R8; 
    R8 = (R8 << 31) >> 31;
    add8Right = 8 & R8;
    
    x = x >> add8Right;
    
    mask4 = 0xF;
    R4 = x & mask4;
    R4 = !R4;
    R4 = (R4 << 31) >> 31;
    add4Right = 4 & R4;
    
    x = x >> add4Right;
    
    mask2 = 1 << 1 | 1;
    R2 = x & mask2;
    R2 = !R2;
    R2 = (R2 << 31) >> 31;
    add2Right = 2 & R2;
    
    x = x >> add2Right;

    R1 = !(x & 1);
    R1 = (R1 << 31) >> 31;
    add1Right = (1 & R1);
    
    return isZero | ((add16Right + add8Right + add4Right + add2Right + add1Right + 2) & ifNotZero);
}
/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
/* I made a mask of the binary form 100000...0000 (32-bit) and masked that with x to check if x was negative after shifting the sign bit to the very right. I also checked if x was positive or not. Eventually because x was split into three parts, I added the negative, positive, and/or sign-bit parts to form x as a two's complement. */
  int toggle = (1 << 31);
  int n = ((toggle & x) >> 31) & x;
  int p = ~n & x;
  int a = toggle & x;
  n = ~(n + ~0);
  return (n + p + a);
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
/* Check the sign bit by shifting the most significant bit to the very right and do an AND operator comparison to check if it is 1 or 0. */
  return !((x >> 31) & 1);
}

/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31                       
 *   Examples: rotateRight(0x87654321,4) = 0x76543218     
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n) {  
/* First store the n bits at the least significant end before shifting x to the right by n bits. Make a mask that will make any x whether positive or negative have 0's in the left positions that it was shifted right. Add the right part that was shifted over to the front of x after it has been shifted to the right. */
   int mask, mask2, leftover;
   int negate = ~n + 1;
   int negOne = ~1 + 1;
   leftover = (x << (32 + negate)); 
  x = (x >> n);
  mask = ~0; 
  mask2 = (1 << 31) >> (n + negOne);
  mask = mask ^ mask2;
  x = mask & x;
  return leftover | x;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
/* I added a n-dependent constant to x if it was negative, but did not add it if x was positive. This sign check was done by checking the most significant bit of x and its AND comparison to n. */
   int negOne = ~1 + 1;
    int posneg = ((x >> 31) & ((1 << n) + negOne));
    return (x + posneg) >> n;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
/* I made a mask of the bit pattern 101010... for 32 bits which I would AND with x and check whether it was still equal to the 101010... pattern or not.  */
    int a = (0xAA << 24) | (0xAA << 16) | (0xAA << 8) | (0xAA);
    return !((a & x) ^ a);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /* I applied the AND operator to the two combinations of ~x & y and x & ~y to get the different cases which could occur in XOR. Then I flipped the bits using ~ for the different combinations of the AND comparisons above. */
  return ~(~(~x & y) & ~(x & ~y));
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
/* We are checking essentially if x == -x or if x is 0. */
   int negatedX = ~x + 1;
  return (!(x ^ negatedX)) & !!(x ^ 0);
}
