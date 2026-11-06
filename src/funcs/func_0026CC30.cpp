/* sym: _vt$12Der_0026CC30 = 0x00376380 */
/* sym: __12Der_0026CC30 = 0x0026CC30 */
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);

class Nod_0026CC30 {
public:
    int m0;
    Nod_0026CC30* m4;
    int m8;
    Nod_0026CC30* mC;
    Nod_0026CC30* m10;
    Nod_0026CC30()
    {
        m4 = this;
        m8 = 0;
        mC = this;
        m10 = this;
    }
    virtual void V0();
};

class Der_0026CC30 : public Nod_0026CC30 {
public:
    char pad18[0x24 - 0x18];
    int m24;
    int m28;
    char pad2C[0x34 - 0x2C];
    int m34;
    int m38;
    int m3C;
    int m40;
    char pad44[0x70 - 0x44];
    void* m70;
    Der_0026CC30();
    virtual void V1();
};

Der_0026CC30::Der_0026CC30()
{
    m24 = 0;
    m28 = 0;
    m34 = 0;
    m38 = 0;
    m70 = func_001E8DD0(func_00122CF8(0x10));
    m3C = 0;
    m40 = 0;
}
