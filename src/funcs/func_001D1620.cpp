struct File_001D1620;

extern char D_0038DCE8[];

extern "C" int func_003331D0(char* buf, const char* fmt, const char* name, const char* ext);
extern "C" void* func_001046B0(unsigned int size);
extern "C" File_001D1620* func_0011ECB8(void* mem);
extern "C" const char* func_00132580();
extern "C" bool func_0011F380(File_001D1620* f, const char* name, int a);

class Base_001D1620 {
public:
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
    virtual void Add(File_001D1620* f);

    int Load(const char* name);
};

int Base_001D1620::Load(const char* name)
{
    char buf[0x100];
    File_001D1620* f = func_0011ECB8(func_001046B0(0x498));
    func_003331D0(buf, D_0038DCE8, name, func_00132580());
    if (!func_0011F380(f, buf, 1))
        return -1;
    Add(f);
    return 0;
}
