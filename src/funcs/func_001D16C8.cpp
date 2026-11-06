struct File_001D16C8 { int m0; };
extern char D_00363C18[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" void* func_001046B0(unsigned int size);
extern "C" File_001D16C8* func_0011ECB8(void* mem);
extern "C" bool func_0011ED50(File_001D16C8* f, const char* name, int a, int b);

struct Base_001D16C8 {
    char pad0[0x20];
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
    virtual void Load(File_001D16C8* f);
};

extern "C" int func_001D16C8(Base_001D16C8* self, const char* name, int a)
{
    char buf[0x100];
    File_001D16C8* f;
    func_003331D0(buf, D_00363C18);
    func_0010BFC0(buf);
    f = func_0011ECB8(func_001046B0(0x498));
    if (!func_0011ED50(f, name, a, 1))
        return -1;
    self->Load(f);
    func_0010BFC8();
    return 0;
}
