extern int D_0038FC78;
extern "C" float func_0010FAB8();
extern "C" int func_0033EBE0(float f);
extern "C" void* func_0022E358(int mgr, int a);
extern "C" int func_0024F5C0(void* p);
extern "C" void func_001F0210(unsigned int script, void* params, void* a, void* b, int c);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void* func_0022DD38(int mgr);

struct Stats_002451B0 {
    char pad[0xC];
    int m_C;
    char pad10[0x5C - 0x10];
    int m_5C;
};
extern "C" Stats_002451B0* func_00203360(void* sk);

struct GoalBase_002451B0 {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
    int m_10;

    virtual void V0();
    virtual bool V1();
    virtual void V2();
    virtual bool IsActive();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual bool IsTimed();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual bool IsDone();
};

struct Goal_002451B0 : GoalBase_002451B0 {
    int m_18;
    int m_1C;
    void* m_params;
    char pad24[0x54 - 0x24];
    int m_timeLeft;
    char pad58[0x64 - 0x58];
    int m_elapsed;

    bool Update();
};

extern "C" void func_00248800(Goal_002451B0* g, unsigned int name);
extern "C" int func_00248760(Goal_002451B0* g);

bool Goal_002451B0::Update()
{
    if (IsActive() && !IsDone()) {
        func_00248800(this, 0xB4E103FD);
    }
    if (IsActive() && !IsDone()) {
        if (IsTimed()) {
            int old = m_timeLeft;
            if (old > 0) {
                m_timeLeft -= func_0033EBE0(func_0010FAB8() * 1000.0f);
                m_elapsed += func_0033EBE0(func_0010FAB8() * 1000.0f);
                int left = m_timeLeft;
                if (left < 10000 && old / 1000 > left / 1000) {
                    if (func_0024F5C0(func_0022E358(D_0038FC78, 1000))) {
                        func_001F0210(0xCFC7C3AD, 0, 0, 0, 0);
                    }
                }
            }
        }
        if (func_00248760(this) && !func_001E8708(m_params, 0x7100155D)) {
            void* sk = func_0022DD38(D_0038FC78);
            if (sk) {
                Stats_002451B0* st = func_00203360(sk);
                if (st && st->m_C * st->m_5C > 0) {
                    func_001E7360(m_params, 0, 0x7100155D);
                }
            }
        }
        if (V1()) {
            V5();
        }
    }
    return true;
}
