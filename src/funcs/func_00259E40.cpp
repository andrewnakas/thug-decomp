extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_00183C98(void* obj, void* ref);

struct Ref_00259E40 {
    void* m0;
    int m4;
    int m8;
    bool IsFree() { return m0 == 0; }
    void Set(void* p)
    {
        if (m0) {
            func_00183CB8(m0, this);
            m0 = 0;
        }
        m0 = p;
        if (p) func_00183C98(p, this);
    }
};

struct Obj_00259E40 {
    Ref_00259E40 m[50];
    void Fn(void* p);
};

void Obj_00259E40::Fn(void* p)
{
    for (int i = 0; i < 50; i++) {
        if (m[i].IsFree()) {
            m[i].Set(p);
            return;
        }
    }
}
