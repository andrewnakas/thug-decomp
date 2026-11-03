extern "C" int func_00331BB8(const char* s);
extern "C" void* func_00331404(void* dst, const void* src, int n);

struct Tab_00123110 {
    int w[0x4420 / 4];
};

struct Hdr_00123110 {
    int w[0x38 / 4];
};

struct C_00123110 {
    int m0;
    int m4;
    Hdr_00123110 m8;
    Tab_00123110 m40;
    char m4460[0x20];
    char* Load(char* buf);
};

char* C_00123110::Load(char* buf)
{
    m40 = *(Tab_00123110*)buf;
    buf += sizeof(Tab_00123110);
    m8 = *(Hdr_00123110*)buf;
    buf += sizeof(Hdr_00123110);
    int len = func_00331BB8(buf) + 1;
    func_00331404(m4460, buf, len);
    return buf + len;
}
