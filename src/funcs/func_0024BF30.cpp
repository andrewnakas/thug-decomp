class Base_0024BF30 {
public:
    char pad0[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual bool Deactivate(int flag, int all);
};

class Goal_0024BF30 : public Base_0024BF30 {
public:
    char pad18[0x8];
    void* m_params;
};

extern "C" bool func_001E8708(void* self, unsigned int name);
extern "C" void func_001E7360(void* self, unsigned int name, unsigned int value);
extern "C" void func_001E6D18(void* self, unsigned int name);
extern "C" bool func_00244A88(Goal_0024BF30* self);

bool func_0024BF30(Goal_0024BF30* self)
{
    bool had = func_001E8708(self->m_params, 0x54D3CAC1);
    func_001E7360(self->m_params, 0, 0xC309CAD1);
    self->Deactivate(0, 1);
    func_001E6D18(self->m_params, 0xC309CAD1);
    if (had)
        func_001E7360(self->m_params, 0, 0x54D3CAC1);
    bool result = func_00244A88(self);
    func_001E6D18(self->m_params, 0x54D3CAC1);
    return result;
}
