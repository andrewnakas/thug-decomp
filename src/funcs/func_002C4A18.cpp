/* sym: __10A_002C4A18 = 0x001829A8 */
/* sym: __10B_002C4A18 = 0x00187DA0 */
/* sym: _vt$12Obj_002C4A18$10B_002C4A18 = 0x0037AE00 */
/* sym: _vt$12Obj_002C4A18 = 0x0037AE20 */
/* sym: _vt$10C_002C4A18 = 0x0037AE48 */
/* sym: Set__10B_002C4A18i = 0x00187E38 */
extern char D_0037AE60[];
extern char D_0037AE88[];
extern "C" void* func_001046B0(int size);
extern "C" void* func_001047F8(void* p, int v);
extern "C" int func_002BA990(int v);
extern "C" void func_002C6F98();
extern "C" void func_002C6FE0();
extern "C" void func_002C6DB0();

struct Cb_002C4A18 {
    char pad[0x18];
    void* vt;
    void* fn;
    void* owner;
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Cb_002C4A18(void* f, void* o, int pri) { func_001047F8(this, pri); vt = D_0037AE88; fn = f; owner = o; }
};

struct Cb2_002C4A18 {
    char pad[0x18];
    void* vt;
    char pad1C[0x24 - 0x1C];
    int m24;
    void* fn;
    void* owner;
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Cb2_002C4A18(void* f, void* o) { func_001047F8(this, 0); vt = D_0037AE60; fn = f; owner = o; m24 = 0; }
};

struct A_002C4A18 {
    char pad0[0x14];
    virtual void f();
    A_002C4A18();
};
struct B_002C4A18 {
    char pad18[0x18];
    virtual void g();
    B_002C4A18();
    void Set(int v);
};
struct C_002C4A18 {
    virtual void h();
    C_002C4A18() {}
};
struct Obj_002C4A18 : public A_002C4A18, public B_002C4A18 {
    virtual void k();
    int m34;
    int m38;
    Cb_002C4A18* m3C;
    Cb_002C4A18* m40;
    Cb2_002C4A18* m44;
    float m48;
    float m4C;
    char pad50[0x60 - 0x50];
    int m60;
    int m64;
    int m68;
    float m6C;
    float m70;
    int m74;
    char pad78[0x80 - 0x78];
    int m80;
    C_002C4A18 m84;
    char pad88[0xA0 - 0x88];
    int mA0;
    int mA4;
    char padA8[0xAC - 0xA8];
    unsigned int mAC;
    int mB0;
    float mB4;
    int mB8;
    int mBC;
    Obj_002C4A18();
};

Obj_002C4A18::Obj_002C4A18()
    : m84()
{
    m60 = 0;
    m80 = func_002BA990(1);
    m3C = new Cb_002C4A18((void*)func_002C6F98, this, 0);
    m40 = new Cb_002C4A18((void*)func_002C6FE0, this, -1000);
    m44 = new Cb2_002C4A18((void*)func_002C6DB0, this);
    m64 = 0;
    m68 = 0;
    m74 = 0;
    mB0 = 0;
    mA0 = 0;
    mA4 = 0;
    m34 = 0;
    mB8 = 0;
    mBC = 0;
    m38 = 0;
    m48 = 480.0f;
    m4C = 120.0f;
    m70 = 1400.0f;
    m6C = 10.0f;
    mAC = 0xD443A2BC;
    mB4 = 1.0f;
    Set(0);
}
