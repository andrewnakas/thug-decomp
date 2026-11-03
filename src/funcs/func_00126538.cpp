extern "C" int func_00331BB8(const char* s);
extern "C" char* func_00331A9C(char* dst, const char* src);

struct C_00126538 {
    char pad[0x1A0];
    char* m1A0;
    bool Backspace();
};

extern "C" void func_001262A0(C_00126538* o, char* s);

bool C_00126538::Backspace()
{
    if (!m1A0)
        return false;
    int len = func_00331BB8(m1A0);
    if (!len)
        return false;
    char buf[0x60];
    func_00331A9C(buf, m1A0);
    if (len > 1 && buf[len - 1] == '\\' && buf[len - 2] == '\\')
        buf[len - 2] = 0;
    buf[len - 1] = 0;
    func_001262A0(this, buf);
    return true;
}
