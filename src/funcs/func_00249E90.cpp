struct GoalBase_00249E90 {
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
    virtual void V16();
    virtual bool HasBeaten();
};

struct Goal_00249E90 {
    unsigned int m_id;
};

extern void* D_0038C608;

extern "C" void* func_00249FE0(Goal_00249E90* self);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" void* func_00187B48(void* self, unsigned int id);
extern "C" void func_00185128(void* obj, int active);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void* func_00240850();
extern "C" GoalBase_00249E90* func_0023BAD8(void* self, unsigned int id, int flag);
extern "C" void func_001E6AE8(void* self, int flags);

void func_00249E90(Goal_00249E90* self, int active)
{
    void* params = func_00249FE0(self);
    if (func_001E8708(params, 0x3D1CAB0B)) {
        return;
    }
    unsigned int obj_id = 0;
    func_001E8398(params, 0x02D7E03D, &obj_id, 0);
    if (!obj_id) {
        return;
    }
    void* obj = func_00187B48(D_0038C608, obj_id);
    if (obj) {
        func_00185128(obj, active);
    }
    void* p = func_001E6978(func_001190D0(8));
    func_001E7360(p, 0x9982E501, self->m_id);
    if (active) {
        func_001F0210(0x6D39F2F3, p, 0, 0, 0);
    } else {
        int show = 1;
        GoalBase_00249E90* goal = func_0023BAD8(func_00240850(), self->m_id, 0);
        if (goal && goal->HasBeaten()) {
            show = 0;
        }
        if (show) {
            func_001F0210(0x6EA4D309, p, 0, 0, 0);
        }
    }
    if (p) {
        func_001E6AE8(p, 3);
    }
}
