extern "C" void func_00183CB8(void* obj, void* ref);

struct Ref_00259DD0 {
    void* m0;
    int m4;
    int m8;
    void Set(void* p)
    {
        if (m0) {
            func_00183CB8(m0, this);
            m0 = 0;
        }
        m0 = p;
    }
};

struct Obj_00259DD0 {
    Ref_00259DD0 m[50];
    void Fn(void* p);
};

void Obj_00259DD0::Fn(void* p)
{
    for (int i = 0; i < 50; i++) {
        if (m[i].m0 == p) m[i].Set(0);
    }
}
