extern "C" void func_001707D8(void* o, int v);

struct Src_0014E1D0 {
    char pad0[0x1C];
    int m1C;
};

struct Inst_0014E1D0 {
    char pad0[0x74];
    int m74;
};

struct Obj_0014E1D0 {
    char pad0[0x18];
    Inst_0014E1D0* m18;
    int m1C;
    void* m20;
    void Fn(Src_0014E1D0* s);
};

void Obj_0014E1D0::Fn(Src_0014E1D0* s)
{
    int v = 0;
    if (s)
        v = s->m1C;
    if (m20)
        func_001707D8(m20, v);
    else if (m18)
        m18->m74 = v;
}
