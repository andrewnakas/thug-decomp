extern "C" void* func_00331404(void* dst, const void* src, unsigned int n);
extern "C" void func_0031BCE0(int sema);
extern "C" void func_0031BCC0(int sema);

struct Obj_00200C68 {
    char m_pad0[0x429C];
    int m_sema;
    int Send(char type, unsigned short len, const void* data, int a, unsigned short b, int c);
};

extern "C" int func_00200D18(Obj_00200C68* self, int a, unsigned short b, char* buf, int len, int c);

int Obj_00200C68::Send(char type, unsigned short len, const void* data, int a, unsigned short b, int c)
{
    char buf[0x520];
    buf[0] = type;
    __builtin_memcpy(&buf[1], &len, 2);
    if (len)
        func_00331404(&buf[3], data, len);
    func_0031BCE0(m_sema);
    int r = func_00200D18(this, a, b, buf, len + 3, c);
    func_0031BCC0(m_sema);
    return r;
}
