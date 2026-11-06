struct Comp_001E6A50 {
    int m0;
    int m4;
    int m8;
    Comp_001E6A50* m_next;
};

struct Params_001E6A50 {
    int m0;
    Comp_001E6A50* m_first;
};

extern "C" void* func_001E8CD0(unsigned int size);
extern "C" Comp_001E6A50* func_001E4ED8(void* mem);
extern "C" void func_001E6360(Comp_001E6A50* dst, Comp_001E6A50* src);
extern "C" void func_001E6F90(Params_001E6A50* params, Comp_001E6A50* c);

extern "C" Params_001E6A50* func_001E6A50(Params_001E6A50* dst, Params_001E6A50* src)
{
    for (Comp_001E6A50* c = src->m_first; c; c = c->m_next) {
        Comp_001E6A50* n = func_001E4ED8(func_001E8CD0(0x10));
        func_001E6360(n, c);
        func_001E6F90(dst, n);
    }
    return dst;
}
