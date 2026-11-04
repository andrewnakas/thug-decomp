extern void* D_00388A70;
extern "C" void* func_0010A638(void*, int, int, int);
extern "C" void func_00331404(void*, void*, int);

struct Msg_001FA918 {
    unsigned char m0;
    unsigned short m2;
    void* m4;
    unsigned char m8;
    int mC;
    int m10;
    Msg_001FA918(unsigned char type, unsigned short len, void* data, unsigned char flag);
};

Msg_001FA918::Msg_001FA918(unsigned char type, unsigned short len, void* data, unsigned char flag)
{
    m10 = 0;
    m4 = 0;
    if (len) {
        m4 = func_0010A638(D_00388A70, len, 1, 0);
        func_00331404(m4, data, len);
    }
    m0 = type;
    m2 = len;
    m8 = flag;
}
