extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" void* func_001E9378(void* scr, int arg);
extern "C" void* func_001E5548(unsigned int id, int flags);

struct Script_001AE978 {
    int m_pad[3];
    int m_count;
};

extern "C" Script_001AE978* func_001E55B8(int id, int flags);

struct C_001AE978 {
    int m_pad[667];
    void* mA6C;
    int mA70[551];
    int m130C;
    int Trigger(int id, unsigned int mask);
};

extern "C" int func_001ADE78(C_001AE978* self, void* p);
extern "C" int func_001AB648(C_001AE978* self, void* p);
extern "C" int func_001AB6E8(C_001AE978* self, void* p);
extern "C" int func_001AC030(C_001AE978* self, int a, int b, unsigned int c);
extern "C" int func_001ADF90(C_001AE978* self, void* p, unsigned int name, int d);

int C_001AE978::Trigger(int id, unsigned int mask)
{
    int found = 0;
    Script_001AE978* scr = func_001E55B8(id, 0);
    if (scr) {
    int n = scr->m_count;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) continue;
        void* p = func_001E9378(scr, i);
        if (!func_001ADE78(this, p)) continue;
        int a = func_001AB648(this, p);
        int b = func_001AB6E8(this, p);
        if (func_001AC030(this, a, 2, 0xFFFFFFFB) || func_001AC030(this, b, 2, 0xFFFFFFFB)) {
            if (!func_001ADF90(this, p, 0x7A16ACA0, 0)) {
                unsigned int n2 = 0;
                func_001E8398(p, 0xA92A2280, &n2, 0);
                if (n2) {
                    unsigned int q = 0;
                    func_001E8398(mA6C, n2, &q, 0);
                    if (q) {
                        void* s = func_001E5548(q, 0);
                        if (s) {
                            if (func_001ADF90(this, s, 0x7A16ACA0, 0)) found = 1;
                        }
                    }
                }
            } else {
                found = 1;
            }
        }
        if (!m130C) break;
    }
    }
    return found;
}
