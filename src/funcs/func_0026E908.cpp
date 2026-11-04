/* sym: _$_11PA_0026E908 = 0x0026DFE0 */
/* sym: _$_11PB_0026E908 = 0x0026E418 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct PA_0026E908 {
    int m0;
    ~PA_0026E908();
};

struct PB_0026E908 {
    int m0;
    ~PB_0026E908();
};

struct Obj_0026E908 {
    int m0;
    PB_0026E908* m4;
    PB_0026E908* m8;
    PA_0026E908* mC;
    PA_0026E908* m10;
    PA_0026E908* m14;
    PA_0026E908* m18;
    ~Obj_0026E908();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0026E908::~Obj_0026E908()
{
    delete m10;
    delete m14;
    delete mC;
    delete m18;
    delete m8;
    delete m4;
}
