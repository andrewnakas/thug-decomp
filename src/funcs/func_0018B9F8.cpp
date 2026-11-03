extern "C" int func_001E8708(void* params, unsigned int id);
extern "C" void* func_0013D8A8(void* p);
extern "C" void func_0013D7A0(void* p);
extern "C" void func_0013D820(void* p);
extern "C" void func_00137DA8(void* p, void* q);
extern "C" void* func_00185578(void* p, unsigned int id);
extern "C" void* func_0019EBD0(void* p);
extern "C" void func_0013CC80(void* p, void* q);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int required);
extern "C" void func_0013F1E8(void* p, int flag);

struct C_0018B9F8 {
    char pad0[0xC];
    char* mC;
    char pad10[0x260 - 0x10];
    void* m260;
    void Apply(void* params);
    void ApplyRest(void* params);
};

void C_0018B9F8::Apply(void* params)
{
    if (func_001E8708(params, 0x10079F2D)) {
        if (!func_0013D8A8(m260)) {
            func_0013D7A0(m260);
            func_00137DA8(func_0013D8A8(m260), mC + 0x50);
        }
    } else {
        if (func_0013D8A8(m260)) func_0013D820(m260);
    }
    void* o = func_00185578(mC, 0x222756D5);
    if (o) {
        void* s = m260;
        func_0013CC80(s, func_0019EBD0(o));
    }
    int v = 0;
    func_001E7DE8(params, 0x2A1F92C0, &v, 0);
    func_0013F1E8(m260, v != 0);
    ApplyRest(params);
}
