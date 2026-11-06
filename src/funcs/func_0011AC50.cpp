extern "C" void* func_0011AC30();
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_0019EBD0(void* comp);

extern "C" int func_0011AC50()
{
    void* c = func_00185578(func_0011AC30(), 0x222756D5);
    if (c) {
        return func_0019EBD0(c);
    }
    return 0;
}
