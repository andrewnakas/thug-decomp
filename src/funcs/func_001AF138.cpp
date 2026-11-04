extern "C" void* func_001E9378(void* scr, int arg);
extern "C" int func_0010FC30();
extern "C" int func_001E7DE8(void* params, unsigned int name, unsigned int* out, int req);

struct Script_001AF138 {
    int m_pad[3];
    int m_count;
};

extern "C" Script_001AF138* func_001E55B8(int id, int flags);

struct C_001AF138 {
    int m_pad[1213];
    int m12F4;
    int m12F8;
    int m12FC;
    int m1300;
    unsigned int m1304;
    int m1308;
    void Queue(int id, int arg);
};

extern "C" int func_001ADE78(C_001AF138* self, void* p);
extern "C" int func_001AB648(C_001AF138* self, void* p);
extern "C" int func_001AB6E8(C_001AF138* self, void* p);
extern "C" int func_001AC030(C_001AF138* self, int a, int b, unsigned int c);

void C_001AF138::Queue(int id, int arg)
{
    Script_001AF138* scr = func_001E55B8(id, 0);
    if (!scr) return;
    int n = scr->m_count;
    for (int i = 0; i < n; i++) {
        void* p = func_001E9378(scr, i);
        if (!func_001ADE78(this, p)) continue;
        int a = func_001AB648(this, p);
        int b = func_001AB6E8(this, p);
        if (func_001AC030(this, a, 8, 0xFFFFFFFB) || func_001AC030(this, b, 8, 0xFFFFFFFB)) {
            m12F8 = id;
            m12FC = i;
            m1300 = func_0010FC30();
            m1304 = 0xFFFFFFFF;
            m1308 = arg;
            func_001E7DE8(p, 0x79A07F3F, &m1304, 0);
            m12F4 = 1;
        }
    }
}
