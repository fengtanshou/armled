// No need to run static destructors as application will never exit [1].
// [1] http://www.state-machine.com/arm/Building_bare-metal_ARM_with_GNU.pdf

extern "C" int __aeabi_atexit(void *object, void (*destructor)(void *), void *dso_handle)
{
   return 0;
}
