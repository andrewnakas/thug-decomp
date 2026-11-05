extern int D_0039412C;
extern int D_00394130;
extern "C" void func_0031BCE0(int sema);
extern "C" void func_0031BCB0(int sema);
extern "C" void func_0031BAF0(int thread);
extern "C" void func_0031BAB0(int thread);
extern "C" void func_0031BAC0(int thread, void* arg);
extern "C" void func_001F9018(void* arg);

struct Net_001FA0C8;
extern "C" void func_001FA6A0(Net_001FA0C8* self, int state);

struct Param_001FA0C8 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    void (*m18)(void*);
    char* m1C;
    int m20;
    int m24;
};

extern "C" int func_00106038(Param_001FA0C8* p);

struct Net_001FA0C8 {
    char pad[0x134];
    int m134;
    char pad2[0x2A8 - 0x138];
    int m2A8;
    char pad3[0x2B8 - 0x2AC];
    int m2B8;
    char pad4[0x2E0 - 0x2BC];
    char m_stack[0x3000];
    Param_001FA0C8 m_param;
    char pad5[0x330C - 0x3308];
    int m330C;
    bool Stop();
};

bool Net_001FA0C8::Stop()
{
    if (m134 == 2) {
        m2A8 = 0;
    } else if (m134 == 1 || m134 == 3) {
        D_0039412C = 1;
        func_0031BCE0(D_00394130);
        func_0031BCB0(D_00394130);
        func_0031BAF0(m330C);
        func_0031BAB0(m330C);
        func_001FA6A0(this, 3);
        m2B8 = 0;
        m_param.m24 = 10;
        m_param.m18 = func_001F9018;
        m_param.m1C = m_stack;
        m_param.m20 = 0x3000;
        m_param.m10 = 0x14F;
        func_00106038(&m_param);
        m330C = m_param.m14;
        func_0031BAC0(m330C, this);
    }
    return m2A8 == 0;
}
