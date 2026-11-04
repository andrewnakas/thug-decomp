struct GoalBase_0024E820 {
    char m_pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual bool IsActive();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual bool IsLocked();
};

struct Goal_0024E820 : GoalBase_0024E820 {
    int m18;
    int m1C;
    void* m_params;
    char m_pad24[0x54 - 0x24];
    unsigned int m_warnTime;
    char m_pad58[0xA4 - 0x58];
    int m_timed;
    unsigned int m_elapsed;
    unsigned int m_timeLimit;
    int mB0;
    int m_goalCount;
    int m_count;
};

extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" bool func_0024EA20(Goal_0024E820* self);
extern "C" float func_0010FAB8();
extern "C" int func_0033EBE0(float f);
extern "C" void* func_00240850();
extern "C" unsigned int func_00246258(Goal_0024E820* self);
extern "C" void func_0023BE68(void* self, unsigned int id);
extern "C" bool func_0023BD18(void* self, unsigned int id);
extern "C" void func_002451B0(Goal_0024E820* self);

void func_0024E820(Goal_0024E820* self)
{
    func_001E7200(self->m_params, 0xFC7FC309, self->m_elapsed);
    if (self->IsActive() && !self->IsLocked()) {
        bool win = false;
        if (self->m_timed) {
            if (func_0024EA20(self)) {
                self->m_elapsed += func_0033EBE0(func_0010FAB8() * 1000.0f);
                func_001E7200(self->m_params, 0x9278CA8D, self->m_elapsed);
            }
            if (self->m_elapsed >= self->m_timeLimit) {
                win = true;
            } else if (self->m_warnTime < self->m_timeLimit - self->m_elapsed) {
                func_0023BE68(func_00240850(), func_00246258(self));
                return;
            }
        } else if (self->m_goalCount) {
            win = self->m_count >= self->m_goalCount;
        }
        if (win) {
            func_0023BD18(func_00240850(), func_00246258(self));
            return;
        }
    }
    func_002451B0(self);
}
