/* sym: _vt$12Nod_0026DD78 = 0x00375D50 */
/* sym: _$_12Mem_0026DD78 = 0x001040A8 */
/* sym: _$_12Der_0026DD78 = 0x0026DD78 */
struct Pool_0026DD78;
extern Pool_0026DD78* D_00388A70;
extern "C" void func_0010A8D8(Pool_0026DD78* p, void* m);

class Mem_0026DD78 {
public:
    int m0;
    ~Mem_0026DD78();
};

class Nod_0026DD78 {
public:
    int m0;
    int m4;
    int m8;
    Nod_0026DD78* mC;
    Nod_0026DD78* m10;
    virtual void V0();
    virtual ~Nod_0026DD78()
    {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
};

class Der_0026DD78 {
public:
    Nod_0026DD78 m0;
    char pad18[0x50 - 0x18];
    Mem_0026DD78 m50;
    ~Der_0026DD78();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Der_0026DD78::~Der_0026DD78()
{
}
