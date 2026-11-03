extern char D_003901A0[];
extern char D_00373ED8[];
extern char D_00373EE8[];
extern char D_00373F08[];

struct GoalBase_0024AC20 {
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
    virtual bool Win();
    virtual bool Lose();
};

struct Goal_0024AC20 : GoalBase_0024AC20 {
    char m_pad18[0xA4 - 0x18];
    int mA4;
    int mA8;
    unsigned int mAC;
    int mB0;
    int mB4;
    int mB8;
    int mBC;
    int mC0;
    int mC4;
};

extern "C" void* func_0024AD70(Goal_0024AC20* self);
extern "C" int func_001E7E58(void* params, const char* name, int* out, int assert_);
extern "C" void* func_00240850();
extern "C" void* func_0023BAD8(void* self, unsigned int id, int flag);
extern "C" void* func_00244528(void* goal);
extern "C" int func_00103F28(const char* fmt, ...);

bool func_0024AC20(Goal_0024AC20* self, unsigned int id)
{
    if (!self->IsActive() || self->mAC != id || !self->mBC || self->mA4) {
        return false;
    }
    self->mBC = 0;
    int max;
    func_001E7E58(func_0024AD70(self), D_003901A0, &max, 1);
    void* params = func_00244528(func_0023BAD8(func_00240850(), self->mAC, 1));
    int last;
    if (self->mC4 && func_001E7E58(params, D_00373ED8, &last, 0)) {
        func_00103F28(D_00373EE8, last);
        func_00103F28(D_00373F08, self->mC4);
        if (last >= self->mC4) {
            self->Win();
            return true;
        }
    }
    self->mC0++;
    if (self->mC0 < max) {
        return false;
    }
    self->Lose();
    return true;
}
