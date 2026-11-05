extern char D_0037A718[];
struct Obj_002BB3E0;
extern "C" void func_002BAAC0(Obj_002BB3E0* o);

struct Obj_002BB3E0 {
    int m0;
    int m4;
    unsigned int m8;
    int mC;
    char pad10[0x38 - 0x10];
    void* m38;
    Obj_002BB3E0* Init();
};

Obj_002BB3E0* Obj_002BB3E0::Init()
{
    func_002BAAC0(this);
    m38 = D_0037A718;
    m8 |= 1;
    mC = 0;
    return this;
}
