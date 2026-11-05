extern "C" void* func_002A52F0(void* p, unsigned short id);
extern "C" void func_002B2990(void* p);

struct Msg_002AD478 {
    signed char* m0;
    char pad4[0x18];
    void* m1C;
};

extern "C" bool func_002AD478(Msg_002AD478* m)
{
    void* e = func_002A52F0(m->m1C, *m->m0);
    if (e)
        func_002B2990(e);
    return true;
}
