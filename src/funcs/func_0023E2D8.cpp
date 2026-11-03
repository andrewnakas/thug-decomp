struct Goal_0023E2D8 {
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
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual bool IsMinigame();
};

struct Mgr_0023E2D8 {
    int m0;
    char m_table[0x18];
    void* m_params;
    char m_pad20[0xC];
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
};

extern void* D_00392068;

extern "C" int func_0023C040(Mgr_0023E2D8* self);
extern "C" Goal_0023E2D8* func_00243C18(void* table, int* key, int* out);
extern "C" bool func_002A19A8(void* self);
extern "C" void func_001E6B30(void* params);
extern "C" bool func_0023C048(Mgr_0023E2D8* self, int a);
extern "C" bool func_00215F50(int a, int b);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);

void func_0023E2D8(Mgr_0023E2D8* self)
{
    void* mgr = D_00392068;
    for (int i = 0; i < func_0023C040(self); i++) {
        int out;
        Goal_0023E2D8* goal = func_00243C18(self->m_table, &i, &out);
        if (goal->IsMinigame() && !func_002A19A8(mgr)) {
            self->m3C--;
            self->m2C--;
            self->m30--;
        }
    }
    if (!func_002A19A8(mgr)) {
        func_001E6B30(self->m_params);
    }
    if (!func_0023C048(self, 0) && !func_00215F50(0, 0)) {
        func_001F0210(0x888EF05E, 0, 0, 0, 0);
    }
}
