extern "C" int func_00331BB8(const char* s);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" char* func_00331678(char* dst, const char* src);

extern char D_003897B0[];

struct C_00126490 {
    char pad[0x1A0];
    char* m1A0;
    bool Append(char* s);
};

extern "C" void func_001262A0(C_00126490* o, char* s);

bool C_00126490::Append(char* s)
{
    int len = 0;
    if (m1A0)
        len = func_00331BB8(m1A0);
    int total = len + func_00331BB8(s);
    if (total + 1 < 0x60) {
        if (total <= 0)
            return false;
        char buf[0x60];
        buf[0] = D_003897B0[0];
        if (m1A0)
            func_00331A9C(buf, m1A0);
        func_00331678(buf, s);
        func_001262A0(this, buf);
        return true;
    }
    return false;
}
