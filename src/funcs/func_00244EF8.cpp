extern int D_0038FC78;
extern void* D_00392068;
extern "C" void* func_0022DD38(int mgr);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_002A39F8(void* p);
extern "C" int func_00290810(void* c);
extern "C" int func_00290820(void* c);
extern "C" void func_00290720(void* c, int arg);
extern "C" void func_002907D0(void* c, int arg);

struct Goal_00244EF8 {
    char pad0[0x28];
    int m_type;
    char pad2C[0x54 - 0x2C];
    int m_count;
    char pad58[0x8C - 0x58];
    int m_8C;
    char pad90[0xA0 - 0x90];
    int m_A0;

    bool Check(int arg);
};

bool Goal_00244EF8::Check(int arg)
{
    void* p = D_00392068;
    void* sk = func_0022DD38(D_0038FC78);
    if (!sk) {
        return true;
    }
    void* c = func_00185578(sk, 0xB1D5A3E1);
    if (!func_002A39F8(p)) {
        return true;
    }
    if (m_A0) {
        return false;
    }
    int r = 0;
    switch (m_type) {
    case 1:
        r = func_00290810(c);
        break;
    case 0:
        r = func_00290820(c);
        break;
    case 2:
        return m_count < 1;
    }
    if (r) {
        if (m_count <= 0) {
            return true;
        }
    } else if (m_count <= 0) {
        if (m_type != 0) {
            if (m_type == 1) {
                m_8C = 1;
                func_00290720(c, arg);
            }
        } else {
            m_8C = 1;
            func_002907D0(c, arg);
        }
    }
    return false;
}
