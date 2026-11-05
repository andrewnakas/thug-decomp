extern "C" void func_00183CB8(void* obj, void* ref);

struct Ref_00259D70 {
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

struct Obj_00259D70 {
    Ref_00259D70 m[50];
    void Fn();
};

void Obj_00259D70::Fn()
{
    for (int i = 0; i < 50; i++) m[i].Set(0);
}
