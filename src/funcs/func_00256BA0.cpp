extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_0019EBD0(void* p);

extern "C" int func_00256BA0(void* obj)
{
    void* p = func_00185578(obj, 0x222756D5);
    if (p) return func_0019EBD0(p);
    return 0;
}
