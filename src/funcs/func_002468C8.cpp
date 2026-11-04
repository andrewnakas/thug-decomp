struct GoalBase_002468C8 {
    char m_pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
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

struct Goal_002468C8 : GoalBase_002468C8 {
    int m18;
    int m1C;
    void* m_params;
};

struct Comp_002468C8 {
    char m_pad[0x184];
    float m_distance;
};

extern void* D_0038FC78;

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" void* func_0022DD38(void* self);
extern "C" Comp_002468C8* func_00185578(void* self, unsigned int id);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

bool func_002468C8(Goal_002468C8* self)
{
    if (self->IsLocked()) {
        return false;
    }
    int best = 0;
    func_001E7DE8(self->m_params, 0x78FFB85C, &best, 0);
    void* skater = func_0022DD38(D_0038FC78);
    int offset = 10000;
    func_001E7DE8(self->m_params, 0xC07D8D60, &offset, 0);
    int dist = (int)func_00185578(skater, 0x43686585)->m_distance - offset;
    if (dist < 0) {
        dist = 0;
    }
    int feet = dist / 12;
    int inches = dist % 12;
    func_001E7200(self->m_params, 0x50815D42, feet);
    func_001E7200(self->m_params, 0xB0C26927, inches);
    if (dist <= best) {
        return false;
    }
    func_001E7200(self->m_params, 0x78FFB85C, dist);
    func_001E7200(self->m_params, 0x24BF3AE4, feet);
    func_001E7200(self->m_params, 0x9B49F28D, inches);
    return true;
}
