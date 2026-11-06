/* sym: _vt$12Nod_0026DDF0 = 0x003763E0 */
/* sym: _$_12Mem_0026DDF0 = 0x001040A8 */
/* sym: _$_12Der_0026DDF0 = 0x0026DDF0 */
struct Pool_0026DDF0;
extern Pool_0026DDF0* D_00388A70;
extern "C" void func_0010A8D8(Pool_0026DDF0* p, void* m);

class Mem_0026DDF0 {
public:
    int m0;
    ~Mem_0026DDF0();
};

class Nod_0026DDF0 {
public:
    int m0;
    int m4;
    int m8;
    Nod_0026DDF0* mC;
    Nod_0026DDF0* m10;
    virtual void V0();
    virtual ~Nod_0026DDF0()
    {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

class Der_0026DDF0 {
public:
    Nod_0026DDF0 m0;
    Mem_0026DDF0 m18;
    ~Der_0026DDF0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Der_0026DDF0::~Der_0026DDF0()
{
}
