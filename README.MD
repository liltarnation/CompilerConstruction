# Program

The file lexer.fl contains the lexer, the file parser.y contains the parser and necessary arithmetic alongside
helper functions arith.c and arith.h to carry out the conversion.

# Array implementation

Since arrays are declared differently in Minipas, I had to take the range between the 2 bounds and convert them to
ANSI C bounds. This is done by taking both bounds and converting them to start with 0 alongside the upperBound
being the difference between the 2. Then, whenever the array is being called with an index, I use a function
to convert it to the C index by subtracting it by the miniPas lower bound.

# If and While loops

This was done by following the format that ANSI C requires, by converting if and while loops to labels and goto statements. Also, whenever an assignment is being done, I use a temporary variable _t to first carry out the assignment, then assign the initial variable to this temporary variable.

# readln and writeln

This proved challenging as you first had to save all the used variables in the readln and writeln functions to a temporary array, that will check with another array the types that are being called.

# Variable initialization

All variables were saved into a variable array, alongside useful information about them, such as the type. This could then be used later throughout the parsing to make sure the formatting is correct.
