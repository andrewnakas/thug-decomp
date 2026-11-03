extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8180(void* params, unsigned int name, void** out, int req);
extern "C" void* func_001E55B8(int id, int flags);
extern "C" void* func_001E9378(void* scr, int arg);
extern "C" void* func_001E5548(unsigned int id, int flags);
extern "C" void func_00184A40(void* obj);
extern "C" void func_001EEF18(void* p, unsigned int a, void* b);
extern "C" void func_002919B0(void* p);
extern "C" void func_00184AB0(void* obj, unsigned int a, void* b);
extern "C" int func_001EFDC0(void* p);
extern "C" void func_001E6AC8(void* dst, void* src);

struct Params_001AE520 {
    int m0[4];
    Params_001AE520(const Params_001AE520& o);
    ~Params_001AE520();
    Params_001AE520& operator=(const Params_001AE520& o);
};

struct Obj_001AE520 {
    int m_pad[5];
    void* m14;
};

struct Flag_001AE520 {
    int m_pad[78];
    int m138;
};

struct C_001AE520 {
    int m_pad[3];
    Obj_001AE520* mC;
    int m10[8];
    void* m30;
    Flag_001AE520* m34;
    int m38[652];
    int mA68;
    void* mA6C;
    int mA70[527];
    int m12AC;
    int m12B0;
    int m12B4;
    int m12B8[2];
    int m12C0;
    void Resume(Params_001AE520* params);
};

extern "C" int func_001B0E78(C_001AE520* self);

void C_001AE520::Resume(Params_001AE520* params)
{
    unsigned int a = 0;
    void* b = 0;
    func_001E8398(params, 0x148FEE96, &a, 0);
    func_001E8180(params, 0x7031F10C, &b, 0);
    mA68 = 0;
    if (!m12AC) return;
    m12AC = 0;
    if (a) {
        Params_001AE520 saved(*params);
        func_00184A40(mC);
        func_001EEF18(mC->m14, a, b);
        *params = saved;
    }
    void* scr = func_001E55B8(m12B0, 0);
    if (!scr) return;
    void* p = func_001E9378(scr, m12B4);
    unsigned int n = 0;
    func_001E8398(p, 0xA92A2280, &n, 0);
    if (n) {
        unsigned int q = 0;
        func_001E8398(mA6C, n, &q, 0);
        if (q) {
            void* s = func_001E5548(q, 0);
            if (s) p = s;
        }
    }
    unsigned int id = 0;
    func_001E8398(p, 0xA6D2D890, &id, 0);
    if (!id) return;
    func_002919B0(m30);
    void* w = 0;
    mA68 = m12C0;
    func_001E8180(p, 0x7031F10C, &w, 0);
    Obj_001AE520* o = mC;
    if (params) {
        func_001E6AC8(params, w);
        func_00184AB0(o, id, params);
    } else {
        func_00184AB0(o, id, w);
    }
    func_001EFDC0(o->m14);
    m34->m138 = 1;
    func_001B0E78(this);
}
