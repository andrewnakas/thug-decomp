struct Rec_0029A770 {
    char pad0[0xC];
    void* mC;
};

extern "C" void* func_00299BA8(void* a, void* b);
extern "C" Rec_0029A770* func_0029B378(void* o);

extern "C" bool func_0029A770(void* o, void* a, void* b)
{
    void* p = func_00299BA8(a, b);
    if (p) {
        func_0029B378(o)->mC = p;
        return true;
    }
    return false;
}
