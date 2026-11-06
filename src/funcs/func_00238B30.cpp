/* sym: __nw__15Params_00238B30Ui = 0x001190D0 */
/* sym: __15Params_00238B30 = 0x001E6978 */
/* sym: _$_15Params_00238B30 = 0x001E6AE8 */
extern "C" float fabsf(float);

struct Elem_00238B30;
struct Handle_00238B30;

extern "C" void func_00183C98(Elem_00238B30* o, Handle_00238B30* h);
extern "C" void func_00183CB8(Elem_00238B30* o, Handle_00238B30* h);

struct Elem_00238B30 {
    char pad0[0x54];
    Elem_00238B30* m_child;
    char pad58[0x188 - 0x58];
    float m_w;
    float m_h;
};

struct Handle_00238B30 {
    Elem_00238B30* m_obj;
    Handle_00238B30* m_prev;
    Handle_00238B30* m_next;
    ~Handle_00238B30()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    operator Elem_00238B30*() const { return m_obj; }
};

struct Params_00238B30 {
    int m0;
    int m4;
    Params_00238B30();
    ~Params_00238B30();
    static void* operator new(unsigned int size);
};

struct Pt_00238B30 {
    float x;
    float y;
    float z;
};

extern void* D_0038FC78;
extern void* D_00389A30;
extern char D_0038FE80[];

extern "C" void* func_0022DF08(void* net, int id);
extern "C" int func_002041F8(void* s);
extern "C" Handle_00238B30 func_0012DB48(void* mgr, unsigned int id, int a);
extern "C" bool func_00184078(Elem_00238B30* o, unsigned int crc, int* out);
extern "C" void func_00184000(Elem_00238B30* o, unsigned int crc, unsigned int v);
extern "C" void func_001E73C8(Params_00238B30* p, char* name, unsigned int v);
extern "C" void func_001F0210(unsigned int crc, Params_00238B30* p, int a, int b, int c);
extern "C" void func_00123A18(Elem_00238B30* o, float x, float y, int a);
extern "C" void func_001288A8(Elem_00238B30* o, float r, int a);

struct Meter_00238B30 {
    short m0;
    short m2;
    char pad4[0x90 - 0x4];
    Pt_00238B30 m90[19];
    char pad174[0x17C - 0x174];
    float m17C;
    float m180;
    float m184;
    float m188;
    float m18C;
    float m190;
    float m194;
    float m198;
    float m19C;
    float m1A0;
    float m1A4;
    void Set(bool on, bool vert, float v);
};

void Meter_00238B30::Set(bool on, bool vert, float v)
{
    void* mgr = D_00389A30;
    void* s = func_0022DF08(D_0038FC78, m2);
    Elem_00238B30* o = func_0012DB48(mgr, func_002041F8(s) + 0xA4DB8A4B, 0);
    int cur = 0;
    func_00184078(o, 0xC22EB9A0, &cur);
    if (on != (cur != 0)) {
        Params_00238B30* p = new Params_00238B30;
        func_001E73C8(p, D_0038FE80, func_002041F8(s) + 0xA4DB8A4B);
        if (on)
            func_001F0210(0xBA95DA16, p, 0, 0, 0);
        else
            func_001F0210(0x58783B40, p, 0, 0, 0);
        delete p;
    }
    if (vert)
        func_00184000(o, 0x863A07E2, 0xEF24413B);
    else
        func_00184000(o, 0x863A07E2, 0x530BE001);
    float a = fabsf(v);
    int i = (int)(a / m17C);
    float f = a - i * m17C;
    m184 = m90[i].x + (m90[i + 1].x - m90[i].x) * f / m17C;
    m188 = m90[i].y + (m90[i + 1].y - m90[i].y) * f / m17C;
    m18C = -v * 45.0f;
    Elem_00238B30* c = o->m_child;
    if (vert) {
        func_00123A18(o, m1A0, m1A4, 1);
        func_001288A8(o, -90.0f, 1);
        if (v >= 0.0f)
            func_00123A18(c, o->m_w * 0.5f + m188, o->m_h * 0.5f - m184, 1);
        else
            func_00123A18(c, o->m_w * 0.5f + m188, o->m_h * 0.5f + m184, 1);
        func_001288A8(c, -m18C - 90.0f, 1);
    } else {
        func_00123A18(o, m194, m198, 1);
        func_001288A8(o, 0.0f, 1);
        if (v >= 0.0f)
            func_00123A18(c, o->m_w * 0.5f + m184, o->m_h * 0.5f + m188, 1);
        else
            func_00123A18(c, o->m_w * 0.5f - m184, o->m_h * 0.5f + m188, 1);
        func_001288A8(c, -m18C, 1);
    }
}
