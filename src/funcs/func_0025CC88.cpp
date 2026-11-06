struct Comp_0025CC88 {
    char pad[0x288];
    int m288;
};

extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void* func_0019EBD0(void* p);
extern "C" void func_0011E1C8(void* p, int a);

void Fn_0025CC88(void* obj, int a)
{
    void* c = func_00185578(obj, 0x222756D5);
    if (c) {
        Comp_0025CC88* d = (Comp_0025CC88*)func_00185578(obj, 0x286A8D26);
        if (d->m288) func_0011E1C8(func_0019EBD0(c), a);
    }
}
