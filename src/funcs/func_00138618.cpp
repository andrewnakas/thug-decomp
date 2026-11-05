extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00138528(const char* path);
extern char D_00389FE8[];
extern char D_0035DB48[];

class C_00138618 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual int V1(char* path, int a, int b);
    void Load(const char* name, int a, int b);
};

void C_00138618::Load(const char* name, int a, int b)
{
    char buf[0x200];
    func_003331D0(buf, D_00389FE8, name);
    if (a) {
        if (name[0] == '.' && name[1] == '.' && name[2] == '/')
            func_003331D0(buf, D_00389FE8, name + 3);
        else
            func_003331D0(buf, D_0035DB48, name);
    }
    m0 = func_00138528(buf);
    V1(buf, a, b);
}
