extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_00229EB0(void* list);
extern "C" void* func_00229F48(void* list, int i);
extern "C" void* func_00229DF0(void* e);
extern "C" void func_0022A090(void* e, void* out);
extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_00183C98(void* obj, void* ref);

struct Thing_001B6038 {
    int m_pad[47];
    void* mBC;
};

extern "C" Thing_001B6038* func_001F0750(unsigned int name, void* params, int a, int b, int c,
                                          int d, int e, int f, int g, int h);

static inline void SetRef_001B6038(void** ref, void* obj)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
    *ref = obj;
    if (obj) func_00183C98(obj, ref);
}

struct C_001B6038 {
    int m_pad[3];
    void* mC;
    int m10[4];
    unsigned int m20;
    int m24[9];
    void* m48;
    void* m4C;
    int m50[8];
    int m70[4];
    void Finish();
};

void C_001B6038::Finish()
{
    if (!(m20 & 4)) return;
    m20 = (m20 & ~4u) | 0x80;
    int n = func_00229EB0(m48);
    if (n >= 2) {
        for (int i = 0; i < n; i++) {
            void* e = func_00229F48(m48, i);
            unsigned int type;
            if (func_001E8398(func_00229DF0(e), 0x963DC198, &type, 0) && type == 0xE41199AF) {
                m4C = e;
                func_0022A090(e, m70);
                break;
            }
        }
    }
    Thing_001B6038* th = func_001F0750(0xE630BF07, 0, 0, 0, -1, 0, 0, 0, 0, 0);
    SetRef_001B6038(&th->mBC, mC);
}
