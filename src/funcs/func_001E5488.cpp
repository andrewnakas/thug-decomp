struct Obj_001E5488 {
    char pad[0xC];
    void* mC;
};

extern char D_0038E490[];
extern "C" Obj_001E5488* func_001E5040();

extern "C" void* func_001E5488()
{
    Obj_001E5488* p = func_001E5040();
    void* r;
    if (p)
        r = p->mC;
    else
        r = D_0038E490;
    return r;
}
