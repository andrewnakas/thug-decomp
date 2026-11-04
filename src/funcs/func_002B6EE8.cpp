typedef int qword __attribute__((mode(TI)));

struct Vec_002B6EE8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

extern "C" void* func_001317D0(int id);
extern "C" void func_00135160(void* o, Vec_002B6EE8* v);

struct Elem_002B6EE8 {
    int m0;
    char pad4[0x1C];
    Vec_002B6EE8 m20;
    void SetPos(Vec_002B6EE8* v, int apply);
};

void Elem_002B6EE8::SetPos(Vec_002B6EE8* v, int apply)
{
    m20 = *v;
    if (apply == 1)
        func_00135160(func_001317D0(m0), v);
}
