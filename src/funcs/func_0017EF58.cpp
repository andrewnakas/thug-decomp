/* sym: _vt$13Prim_0017EF58 = 0x00361290 */

extern int D_003940B0;
extern int D_0038C10C;
extern "C" void func_0017F4C0(void* p, int* list);

class Prim_0017EF58 {
public:
    int m0;
    int m4;
    float m8;
    unsigned int mC;
    int* m10;
    int m14;

    Prim_0017EF58(int a, float f);
    virtual ~Prim_0017EF58();
    virtual void F2();
    virtual void P3() = 0;
    virtual void P4() = 0;
    virtual void P5() = 0;
};

Prim_0017EF58::Prim_0017EF58(int a, float f)
{
    m8 = f;
    mC = 0xFFFFFF;
    m10 = &D_003940B0;
    m0 = a;
    m4 = 0;
    m14 = 0;
    if (!a) {
        func_0017F4C0(this, &D_0038C10C);
    }
}
