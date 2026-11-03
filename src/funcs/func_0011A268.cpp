extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* o, int n);
extern "C" void func_001E7360(void* s, unsigned int id, int v);
extern "C" void func_001E7200(void* s, unsigned int id, int v);
extern "C" void func_001E72B0(void* s, unsigned int id, float v);
extern "C" void func_001E7268(void* s, void* id, int v);
extern char D_00389310[];

struct Node11A268 {
    int m_pad[5];
    virtual ~Node11A268();
    virtual void F1();
    virtual void F2();
    virtual bool Send(unsigned int id, void* params, int flag);
};

struct C_0011A268 {
    char pad[0x38];
    int m38;
    Node11A268* m3C[4];
    int m4C;
    float m50;
    void Init(int a, int type, int b, float f0, float f1, float f2, float f3);
};

extern "C" void func_0011A590(C_0011A268* self);
extern "C" void func_0011A608(C_0011A268* self, int a);
extern "C" void func_00119A70(C_0011A268* self, void* s);

void C_0011A268::Init(int a, int type, int b, float f0, float f1, float f2, float f3)
{
    func_0011A590(this);
    func_0011A608(this, a);
    m38 = 2;
    m50 = f3 * 0.016666668f;
    void* s;
    if (type == 3) {
        s = func_001E6978(func_001190D0(8));
        func_001E7360(s, 0x7321A8D6, 0x6D941203);
        func_00119A70(this, s);
        if (s)
            func_001E6AE8(s, 3);
    } else {
        s = func_001E6978(func_001190D0(8));
        func_001E7360(s, 0x7321A8D6, 0xCB4533FF);
        func_00119A70(this, s);
        if (s)
            func_001E6AE8(s, 3);
    }
    s = func_001E6978(func_001190D0(8));
    func_001E7360(s, 0x7321A8D6, 0xDF5C091A);
    func_001E7268(s, D_00389310, b);
    func_00119A70(this, s);
    if (s)
        func_001E6AE8(s, 3);
    int i;
    s = func_001E6978(func_001190D0(8));
    func_001E72B0(s, 0x4D747FA0, 0.0f);
    for (i = 0; i < m4C; i++)
        m3C[i]->Send(0xD0209498, s, 0);
    if (s)
        func_001E6AE8(s, 3);
    s = func_001E6978(func_001190D0(8));
    func_001E7360(s, 0x6C2BFB7F, a);
    func_001E72B0(s, 0xD16B61E6, f0);
    func_001E72B0(s, 0xAB81BB3D, f1);
    func_001E7200(s, 0xCD8D7C1B, type);
    func_001E72B0(s, 0x8F0D24ED, f2);
    func_001E72B0(s, 0xF0D90109, f3);
    for (i = 0; i < m4C; i++)
        m3C[i]->Send(0xAF2FAE19, s, 0);
    if (s)
        func_001E6AE8(s, 3);
}
