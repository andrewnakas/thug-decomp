extern void* D_00388A70;
extern "C" void* func_0010A638(void*, int, int, int);
extern "C" void func_00331404(void*, void*, int);

struct Msg_001FA838 {
    unsigned char m0;
    unsigned short m2;
    void* m4;
    int m8;
    int mC;
    Msg_001FA838(unsigned char type, unsigned short len, void* data);
};

Msg_001FA838::Msg_001FA838(unsigned char type, unsigned short len, void* data)
{
    mC = 0;
    m4 = 0;
    if (len) {
        m4 = func_0010A638(D_00388A70, len, 1, 0);
        func_00331404(m4, data, len);
    }
    m0 = type;
    m2 = len;
}
