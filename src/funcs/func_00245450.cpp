struct GoalBase_00245450 {
    char m_pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual bool IsActive();
};

struct Goal_00245450 : GoalBase_00245450 {
    int m18;
    int m1C;
    void* m_params;
    void* m_flags;
    char m_pad28[0x60 - 0x28];
    int m_numFlagsSet;
};

extern "C" bool func_001E8618(void* params, unsigned int name);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);

bool func_00245450(Goal_00245450* self, unsigned int flag, int value)
{
    if (!self->IsActive()) {
        return false;
    }
    if (func_001E8618(self->m_flags, flag)) {
        int old;
        func_001E7DE8(self->m_flags, flag, &old, 1);
        func_001E7200(self->m_flags, flag, value);
        if (old != value) {
        if (!value) {
            self->m_numFlagsSet--;
        } else {
            self->m_numFlagsSet++;
            if (!func_001E8708(self->m_params, 0x524566E3)) {
                func_001F0210(0x5ED34DEB, 0, 0, 0, 0);
            }
        }
        if (func_001E8708(self->m_params, 0xFD7AE1F4)) {
            func_001F0210(0xF2E85A34, self->m_params, 0, 0, 0);
        }
        func_001E7200(self->m_params, 0xCF6CD3C1, self->m_numFlagsSet);
        }
        return true;
    }
    return false;
}
