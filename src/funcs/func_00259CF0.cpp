extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Ref_00259CF0 {
    void* m0;
    int m4;
    int m8;
    ~Ref_00259CF0()
    {
        if (m0) {
            func_00183CB8(m0, this);
            m0 = 0;
        }
    }
};

struct Obj_00259CF0 {
    Ref_00259CF0 m[50];
    ~Obj_00259CF0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_00259CF0::~Obj_00259CF0()
{
}
