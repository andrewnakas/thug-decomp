extern "C" void func_002669E0(void* it);
extern "C" void* func_002669F0(void* it, int a);
extern "C" int func_00265528(void* p, void* in);

struct Obj_00265EF0 {
    int m0;
    int m4;
    int m8[2];
    bool Read(void* in);
};

bool Obj_00265EF0::Read(void* in)
{
    func_002669E0(m8);
    void* p;
    while ((p = func_002669F0(m8, 0)) != 0) {
        if (!func_00265528(p, in))
            return false;
    }
    return true;
}
