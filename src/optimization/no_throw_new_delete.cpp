#include <cstddef>
//#include <cstdlib>
#include <new>

// Static constructors will use the heap [1]. This code replace new and delete with no-throw versions so that exception handling does not need to be pulled in.
// I think this will make a mess if allocation fails.
// I guess avoiding static constructors (i.e. variables) would be the best.
// [1] http://www.state-machine.com/arm/Building_bare-metal_ARM_with_GNU.pdf

void *operator new(std::size_t size)
{
   return operator new(size, std::nothrow);
//   return malloc(size);
}

void operator delete(void *ptr)
{
   operator delete(ptr, std::nothrow);
//   return free(ptr);
}
