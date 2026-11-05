struct Comp_00256BD8 {
    char pad[0x260];
    int m260;
};

extern "C" Comp_00256BD8* func_00185578(void* obj, unsigned int name);

int Fn_00256BD8(void* obj)
{
    Comp_00256BD8* c = func_00185578(obj, 0x286A8D26);
    if (c) return c->m260;
    return 0;
}
