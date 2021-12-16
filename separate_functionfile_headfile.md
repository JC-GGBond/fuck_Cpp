# How to separate .h file and function file

in test_to_use_Class:
```
#include "JC00.h"
#include "JC00.cpp"//must add this file
```

if only #include "JC00.h"

there will not chain the JC00.cpp file

Actually is :

g++ -c test_to_use_Class.cpp -o test_to_use_Class.exe

there will be error:undefined reference to XXX

After #include "JC00.cpp"

```
g++ -c test_to_use_Class.cpp -
g++ -c JC00.cpp
g++ -o test_to_use_Class.exe test_to_use_Class.o JC00.o
```

compile separately and chain them

So,it's uneasy

makefile is what VScode do for us.

cmake can auto create makefile.

