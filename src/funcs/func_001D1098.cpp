extern char D_0038DC18[];
extern void* D_00388A70;

extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00115CE0(void* mem);
extern "C" int func_00132580();
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00115EC8(void* self, const char* name, int arg, bool async, bool preloaded);
extern "C" int func_001E53A0(unsigned int key, int a);
extern "C" void func_00115D58(void* p, int flags);

class Loader_001D1098 {
public:
    char m_pad[0x20];
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
    virtual void SetFile(void* file);
    int Load(const char* name, bool async, bool preloaded);
};

int Loader_001D1098::Load(const char* name, bool async, bool preloaded)
{
    int result = -1;
    func_0010BFC0(name);
    void* file = func_00115CE0(func_0010A638(D_00388A70, 0x44, 1, 0));
    char path[0x100];
    func_003331D0(path, D_0038DC18, name, func_00132580());
    if (!func_00115EC8(file, path, 1, async, preloaded)) {
        func_001E53A0(0x25DC7904, 0);
        if (file) {
            func_00115D58(file, 3);
        }
        file = 0;
    } else {
        result = 0;
    }
    SetFile(file);
    func_0010BFC8();
    return result;
}
