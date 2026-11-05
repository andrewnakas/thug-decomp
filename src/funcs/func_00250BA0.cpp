/* sym: _$_12Str_00250BA0 = 0x001040A8 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Str_00250BA0 {
    int m0[4];
    ~Str_00250BA0();
};

struct Entry_00250BA0 {
    Str_00250BA0 m0;
    int m10[5];
};

struct Obj_00250BA0 {
    int m0;
    void* m4;
    int m8;
    Entry_00250BA0 mC[8];
    ~Obj_00250BA0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_00250BA0::~Obj_00250BA0()
{
}
