struct Comp_00249698 {
    char m_pad[0x18];
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
    virtual void Dispatch(unsigned int name, void* params, int script);
};

struct Cam_00249698 {
    int m0;
    int m4;
    int m_screen;
    unsigned int m_target;
};

extern void* D_0038FC78;
extern void* D_0038C608;
extern void* D_0038DB38;

extern "C" void* func_0022DD38(void* self);
extern "C" void* func_00187B48(void* self, unsigned int id);
extern "C" void func_001F0E98(void* obj, unsigned int name);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" Comp_00249698* func_00185578(void* self, unsigned int id);
extern "C" void func_001E6AE8(void* self, int flags);
extern "C" void* func_001D05B0(void* self, int id, int a);
extern "C" void func_001D0460(void* self, void* elem);
extern "C" void func_001D04E0(void* self, void* elem);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);

void func_00249698(Cam_00249698* self)
{
    if (!self->m_screen) {
        return;
    }
    if (self->m_target) {
        void* obj;
        if (self->m_target == 0x5B8AB877) {
            obj = func_0022DD38(D_0038FC78);
        } else {
            obj = func_00187B48(D_0038C608, self->m_target);
        }
        func_001F0E98(obj, 0x5376A011);
        void* p = func_001E6978(func_001190D0(8));
        func_001E7360(p, 0x7321A8D6, 0x659BF355);
        func_001E7360(p, 0x40C698AF, 0xC0BA0665);
        if (obj) {
            func_00185578(obj, 0x72AD7B23)->Dispatch(0x986D274E, p, 0);
        }
        if (p) {
            func_001E6AE8(p, 3);
        }
        self->m_target = 0;
    }
    void* mgr = D_0038DB38;
    void* elem = func_001D05B0(mgr, self->m_screen, 0);
    if (elem) {
        func_001D0460(mgr, elem);
        func_001D04E0(mgr, elem);
        func_001F0210(0xB3DCE47F, 0, 0, 0, 0);
    }
    self->m_screen = 0;
}
