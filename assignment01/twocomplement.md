**Two's Complement Represent Negative Number:**
Why use two’s complement to represent negative numbers? Two's complement is an invert and adding one to a
binary number.  Using two's complement to represent negative number has advantages because there will be 
no negative zero like 1's complement.  8-bit singed integer will represent 256 numbers.  
0 to 127 (00000000 - 01111111) and -128 to -1 (10000000 - 11111111).  Total of an integer number represented
by N-bits and its 2's complement is 2^N.  Adding and subtraction operations are straight 
forward like adding or subtraction binary number (as long as the inputs are represented in the same number 
of bits as the output, and any overflow beyond those bits is discarded from the result).  This will 
simplify adding and subtraction circuit logic.