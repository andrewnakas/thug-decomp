extern char D_0038FF20[];

struct Screen_0023CCA0 {
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
    virtual bool Hide();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual bool IsSilent();
};

struct Mgr_0023CCA0 {
    char m_pad[0x20];
    int m20;
};

extern "C" Screen_0023CCA0* func_0023BAD8(Mgr_0023CCA0* self, int id, int flag);
extern "C" void func_00246BE8(Screen_0023CCA0* self);
extern "C" void func_00246C10(Screen_0023CCA0* self);
extern "C" void func_0023C298(Mgr_0023CCA0* self, int value);
extern "C" void func_001F0A18(unsigned int name);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" int func_00246258(Screen_0023CCA0* self);
extern "C" void func_001E73C8(void* self, const char* name, int value);
extern "C" void func_001E6AE8(void* self, int flags);

void func_0023CCA0(Mgr_0023CCA0* self)
{
    if (self->m20) {
        Screen_0023CCA0* screen = func_0023BAD8(self, self->m20, 1);
        func_00246BE8(screen);
        func_0023C298(self, 0);
        func_001F0A18(0xDEA3057B);
        func_001F0A18(0x0B38ED6B);
        func_001F0210(0xBDA66E7D, 0, 0, 0, 0);
        if (!screen->IsSilent()) {
            void* params = func_001E6978(func_001190D0(8));
            func_001E73C8(params, D_0038FF20, func_00246258(screen));
            func_001F0210(0x17C2E09F, params, 0, 0, 0);
            if (params) {
                func_001E6AE8(params, 3);
            }
        }
        screen->Hide();
        func_00246C10(screen);
    }
}
