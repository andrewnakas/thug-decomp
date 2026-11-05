struct Obj_00203128 {
    int m0;
    char m4[4];
};

extern "C" void* func_001E5548(void* p, int a);
extern "C" void func_001E6AC8(void* dst, void* src);

extern "C" bool func_00203128(Obj_00203128* o, void* p)
{
    void* v = func_001E5548(p, 1);
    func_001E6AC8(o->m4, v);
    return true;
}
