extern char* D_0038E320;
extern char D_00366488[];
extern char D_00366468[];

extern "C" int func_00103F28(char*, ...);
extern "C" void func_003315B8(char*, int, int);
extern "C" void func_001F8270(int, char*, int);

struct Strm_001F7A78 {
    int m0;
    int m_pad[10];
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
};

extern "C" int func_001F7A00();

int func_001F7A78(Strm_001F7A78* s, int buf, int bufSize, int count, int start)
{
    func_001F7A00();
    s->m30 = buf;
    s->m3C = bufSize;
    s->m0 = 0;
    s->m2C = 0;
    s->m34 = 0;
    s->m38 = 0;
    s->m40 = 0;
    s->m54 = 0;
    s->m48 = count;
    s->m4C = 0;
    s->m50 = 0;
    s->m44 = start;
    if (start >= 0) {
        func_00103F28(D_00366488, start, count);
        s->m58 = start + count;
        if (s->m58 >= 0) {
            func_00103F28(D_00366488, s->m58, 0x800);
            func_003315B8(D_0038E320 + 0x80, 0, 0x800);
            func_001F8270(s->m58, D_0038E320 + 0x80, 0x800);
            return 1;
        }
    }
    func_00103F28(D_00366468);
    return 0;
}
