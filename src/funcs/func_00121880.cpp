struct Pair_00121880 {
    int a;
    int b;
};

extern "C" void* func_0011FE18(void* mgr);
extern "C" Pair_00121880* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" int func_001E8310(void* params, unsigned int id, Pair_00121880* out, int req);
extern "C" void* func_00121960(int size);
extern "C" void* func_001EE428(void* mem);
extern "C" void func_001EE7F8(void* o, Pair_00121880* p, int a, void* mgr);
extern "C" int func_001EFDC0(void* o);
extern "C" void func_001EE4D8(void* o, int flags);

extern void* D_00388A70;
extern void* D_00389520;

int func_00121880(void* a0, void* a1, unsigned int id)
{
    void* params = func_0011FE18(D_00389520);
    if (params) {
        Pair_00121880* p = func_0010A638(D_00388A70, 8, 1, 0);
        p->a = 0;
        p->b = 0;
        if (func_001E8310(params, id, p, 0)) {
            void* o = func_001EE428(func_00121960(0xF4));
            func_001EE7F8(o, p, 0, D_00389520);
            while (func_001EFDC0(o))
                ;
            if (o)
                func_001EE4D8(o, 3);
        }
        func_0010A8D8(D_00388A70, p);
    }
    return 1;
}
