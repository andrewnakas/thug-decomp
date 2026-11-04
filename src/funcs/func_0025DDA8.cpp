struct Vec_0025DDA8 {
    float x, y, z, w;
    Vec_0025DDA8() {}
    Vec_0025DDA8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_0025DDA8& operator+=(const Vec_0025DDA8& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

struct Model_0025DDA8 {
    char pad[0xC];
    int mC;
};

struct Inst_0025DDA8 {
    int m0;
    int m4;
};

struct Entry_0025DDA8 {
    int flag;
    Inst_0025DDA8* inst;
    int id;
    char pad[0x20 - 0xC];
};

extern char D_004522D0[];
extern Vec_0025DDA8 D_004528D0[];
extern "C" void* func_00185578(int id, unsigned int name);
extern "C" Model_0025DDA8* func_0019EBD0(void* o);
extern "C" void func_0011EAA0(Model_0025DDA8* m, float t);
extern "C" int func_0011EA80(Model_0025DDA8* m);
extern "C" void func_00144D30(int a, void* b, Vec_0025DDA8* c, int d, int e, float f);
extern "C" int func_0011D9E8(Model_0025DDA8* m);
extern "C" int func_0011D798(Model_0025DDA8* m, unsigned int name);
extern "C" void func_0011E4A8(Model_0025DDA8* m, void* b, Vec_0025DDA8* c);

struct Obj_0025DDA8 {
    char pad[0x60];
    Entry_0025DDA8 m_entries[(0x854 - 0x60) / 0x20];
    char pad2[0x854 - 0x60 - ((0x854 - 0x60) / 0x20) * 0x20];
    int m_count;
    char pad3[0xB70 - 0x858];
    float mB70;
    void Update();
};

void Obj_0025DDA8::Update()
{
    for (int i = 0; i < m_count; i++) {
        if (m_entries[i].inst) {
            void* o = func_00185578(m_entries[i].id, 0x222756D5);
            if (o) {
                Model_0025DDA8* m = func_0019EBD0(o);
                int a = m_entries[i].inst->m4;
                func_0011EAA0(m, 0.0f);
                func_00144D30(a, D_004522D0, D_004528D0, func_0011EA80(m), m->mC, mB70);
                if (m_entries[i].flag && func_0011D9E8(m) == 0x37) {
                    int idx = func_0011D798(m, 0x7268C230);
                    Vec_0025DDA8 off(0.0f, -0.2041729689f, 0.5167190433f, 1.0f);
                    D_004528D0[idx] += off;
                }
                func_0011E4A8(m, D_004522D0, D_004528D0);
            }
        }
    }
}
