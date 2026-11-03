extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6AC8(void* s, void* src);
extern "C" unsigned int func_001E9B08(void* s, char* buf, int size, int f);
extern "C" void func_0011FB60(void* s);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" int func_00123420(void* o);

struct C_0011FC60 {
    char pad[0x48];
    char m48[0xC];
    int m54;
    int Write(char* buf, int size, int flag);
};

extern "C" void* func_001200E0(C_0011FC60* self);

int C_0011FC60::Write(char* buf, int size, int flag)
{
    void* s = func_001E6978(func_001190D0(8));
    func_001E6AC8(s, m48);
    unsigned int n = func_001E9B08(s, buf, size, 1);
    if (n > 0x2BC) {
        func_0011FB60(s);
        n = func_001E9B08(s, buf, size, 1);
    }
    if (s)
        func_001E6AE8(s, 3);
    buf += n;
    if (flag)
        *buf = 0;
    else {
        char v;
        if ((func_001200E0(this) && func_00123420(func_001200E0(this))) || m54)
            v = 1;
        else
            v = 0;
        *buf = v;
    }
    return n + 1;
}
