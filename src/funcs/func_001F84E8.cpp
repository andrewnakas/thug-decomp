extern "C" int func_00331BB8(char*);
extern "C" void* func_003315B8(void*, int, int);
extern "C" void func_00331404(void*, char*, int);
extern "C" int func_00327BE0(int, int, void*, int);

struct Req_001F84E8 {
    int m0;
    int m4;
    int m8;
    int mC;
    char name[0x20];
};

int func_001F84E8(char* s)
{
    Req_001F84E8 r;
    int len = func_00331BB8(s) + 1;
    if (len > 0x20)
        return -1;
    func_003315B8(&r, 0, 0x30);
    r.m0 = 0;
    if (*s == 0)
        r.m4 = 1;
    else
        r.m4 = 0;
    r.m8 = 0;
    r.mC = 0;
    func_00331404(r.name, s, len);
    return func_00327BE0(0, 3, &r, 0x30) ? -1 : 0;
}
