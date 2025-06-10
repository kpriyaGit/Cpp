# Multi digit counter

## Single Modulo n Counter

Class ModuloNCounter is implemented for counting from 0 to n-1. The class contains integer members for:\
• the maximum count value (n)\
• the current count value 

Constructors and destructors are defined for the class.
A member function is added that counts i.e. increases the current count value of a passed counter by 1 or reset it to 0, in case of the value becomes greater than n-1 (overflow). It returns 1 if an overflow had occurred otherwise 0.


## Multi digit Counter

This class is an expansion of previous section in order to handle not only counters with one digit but with m digits.A new class ModuloNDigit is implemented consisting of:\
• the number of digits m \
• a pointer to array of the Single Modulo n Counter

Constructors and destructors are defined for the class. Also, a member function is created that increases the actual count value of a multiple digit counter by 1 or resets it to 0 in case of an overflow.

The counter works for any type of number system - Binary, Octal, Decimal, Hexadecimal


## Overloading increment operators

Additionally, the functionality to increment the values of instances of the two counter types by overloading the prefix and postfix increment operators is also added, thus making it possible to write counter++ and ++counter.

Sample Output:

```
Please enter the parameters of your counter:
number of digits: 4
type (2/8/10/16): 2

4 digit binary counter
0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111
0000 0001


Please enter the parameters of your counter:
number of digits: 2
type (2/8/10/16): 16

2 digit hexadecimal counter
00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F
10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F
20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F
…
A0 A1 A2 A3 A4 A5 A6 A7 A8 A9 AA AB AC AD AE AF
B0 B1 B2 B3 B4 B5 B6 B7 B8 B9 BA BB BC BD BE BF
…
F0 F1 F2 F3 F4 F5 F6 F7 F8 F9 FA FB FC FD FE FF
00 01


Please enter the parameters of your counter:
number of digits: 2
type (2/8/10/16): 8

2 digit octal counter
00 01 02 03 04 05 06 07
10 11 12 13 14 15 16 17
20 21 22 23 24 25 26 27
…
70 71 72 73 74 75 76 77
00 01


Please enter the parameters of your counter:
number of digits: 2
type (2/8/10/16): 10

2 digit decimal counter
00 01 02 03 04 05 06 07 08 09
10 11 12 13 14 15 16 17 18 19
20 21 22 23 24 25 26 27 28 29
30 31 32 33 34 35 36 37 38 39
40 41 42 43 44 45 46 47 48 49
50 51 52 53 54 55 56 57 58 59
60 61 62 63 64 65 66 67 68 69
70 71 72 73 74 75 76 77 78 79
80 81 82 83 84 85 86 87 88 89
90 91 92 93 94 95 96 97 98 99
00 01

Please enter the parameters of your counter:
number of digits: 0
type (2/8/10/16): 0
End of the test!

```
