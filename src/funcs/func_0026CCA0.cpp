/* sym: _vt$12Der_0026CCA0 = 0x00376380 */
/* sym: _vt$12Nod_0026CCA0 = 0x00376398 */
/* sym: _$_12Arr_0026CCA0 = 0x001E8DE8 */
struct Pool_0026CCA0;
extern Pool_0026CCA0* D_00388A70;
extern "C" void func_0010A8D8(Pool_0026CCA0* p, void* m);

class Arr_0026CCA0 {
public:
    int m0;
    ~Arr_0026CCA0();
};

extern "C" void func_001E6518(Arr_0026CCA0* a);

class Nod_0026CCA0 {
public:
    int m0;
    int m4;
    int m8;
    Nod_0026CCA0* mC;
    Nod_0026CCA0* m10;
    virtual void V0();
    virtual ~Nod_0026CCA0()
    {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

class Der_0026CCA0 : public Nod_0026CCA0 {
public:
    char pad18[0x70 - 0x18];
    Arr_0026CCA0* m70;
    virtual void V1();
    virtual ~Der_0026CCA0();
};

Der_0026CCA0::~Der_0026CCA0()
{
    if (m70) {
        func_001E6518(m70);
        delete m70;
    }
}
