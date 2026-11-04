extern "C" void* func_001E9378(void* scr, int arg);
extern "C" int func_0010FC30();
extern "C" int func_001E7DE8(void* params, unsigned int name, unsigned int* out, int req);

struct Script_001AE708 {
    int m_pad[3];
    int m_count;
};

extern "C" Script_001AE708* func_001E55B8(int id, int flags);

struct C_001AE708 {
    int m_pad[1195];
    int m12AC;
    int m12B0;
    int m12B4;
    int m12B8;
    unsigned int m12BC;
    int m12C0;
    void Queue(int id, unsigned int mask, int arg);
};

extern "C" int func_001ADE78(C_001AE708* self, void* p);
extern "C" int func_001AB648(C_001AE708* self, void* p);
extern "C" int func_001AB6E8(C_001AE708* self, void* p);
extern "C" int func_001AC030(C_001AE708* self, int a, int b, unsigned int c);

void C_001AE708::Queue(int id, unsigned int mask, int arg)
{
    Script_001AE708* scr = func_001E55B8(id, 0);
    if (!scr) return;
    int n = scr->m_count;
    for (int i = 0; i < n; i++) {
        void* p = func_001E9378(scr, i);
        if (!func_001ADE78(this, p)) continue;
        int a = func_001AB648(this, p);
        int b = func_001AB6E8(this, p);
        if (func_001AC030(this, a, 4, mask) || func_001AC030(this, b, 4, mask)) {
            m12B0 = id;
            m12B4 = i;
            m12B8 = func_0010FC30();
            m12BC = 0xFFFFFFFF;
            m12C0 = arg;
            func_001E7DE8(p, 0x79A07F3F, &m12BC, 0);
            m12AC = 1;
        }
    }
}
