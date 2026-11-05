struct Arg_002D6FC0 {
    int m0;
    int m4;
};

extern "C" void func_002D7E10(void* p, int v);

void func_002D6FC0(void* a, Arg_002D6FC0* x, void* p)
{
    if (!x->m0)
        func_002D7E10(p, x->m4);
}
