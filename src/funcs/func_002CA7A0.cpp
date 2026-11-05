typedef int qword __attribute__((mode(TI)));

struct Vec_002CA7A0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Params_002CA7A0 {
    char pad0[0x18];
    void* m18;
};

extern void* D_00392808;
extern "C" Vec_002CA7A0* func_002C7090(void* p);
extern "C" void func_001E7410(void* p, unsigned int key, float x, float y, float z);

extern "C" bool func_002CA7A0(void* unused, Params_002CA7A0* s)
{
    Vec_002CA7A0 v = *func_002C7090(D_00392808);
    func_001E7410(s->m18, 0x7F261953, v.x, v.y, v.z);
    return true;
}
