extern "C" int func_00331BB8(const char* s);
extern "C" void* func_00331404(void* dst, const void* src, int n);

struct Tab_00122F88 {
    int w[0x4420 / 4];
};

struct Hdr_00122F88 {
    int w[0x38 / 4];
};

struct C_00122F88 {
    int m0;
    int m4;
    Hdr_00122F88 m8;
    Tab_00122F88 m40;
    char m4460[0x20];
    int Save(char* buf);
};

int C_00122F88::Save(char* buf)
{
    *(Tab_00122F88*)buf = m40;
    buf += sizeof(Tab_00122F88);
    *(Hdr_00122F88*)buf = m8;
    int size = sizeof(Tab_00122F88) + sizeof(Hdr_00122F88) + func_00331BB8(m4460) + 1;
    buf += sizeof(Hdr_00122F88);
    func_00331404(buf, m4460, func_00331BB8(m4460) + 1);
    buf += func_00331BB8(m4460) + 1;
    return size;
}
