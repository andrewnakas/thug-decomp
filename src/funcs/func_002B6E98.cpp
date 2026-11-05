extern char D_0037A3C0[];
struct Obj_002B6E98;
extern "C" void func_002B6C00(Obj_002B6E98* o);

struct Obj_002B6E98 {
    int m0;
    unsigned int m4;
    int m8;
    void* mC;
    int m10;
    int m14;
    Obj_002B6E98* Init();
};

Obj_002B6E98* Obj_002B6E98::Init()
{
    func_002B6C00(this);
    mC = D_0037A3C0;
    m4 |= 2;
    m10 = 0;
    m14 = 0;
    return this;
}
