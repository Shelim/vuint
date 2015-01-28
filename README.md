Variable length Unsigned INTeger

---

Needs C++11 compiler!
(GCC 4.7+, Visual Studio 2013+, not tested on CLang)

Should compile on any platform (tested on Win32/Win64)

Usage:
Put include/vuint.hpp in your include directory.

#include<vuint.hpp>

then:
	vuint<512> my_int; // 512 bit length integer
	
More info at the beginning of vuint.hpp

Samples should compile all by itself

Unit tests depends on Google Test Framework:
https://code.google.com/p/googletest/