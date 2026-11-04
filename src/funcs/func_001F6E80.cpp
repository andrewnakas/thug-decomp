extern char* D_0038E320;
extern char D_00366430[];

extern "C" void func_001F5340(char*, unsigned int*, int*, unsigned int*, int*);
extern "C" int func_001F7090(unsigned int, int, unsigned int, int, char*, int, char*, int);
extern "C" int func_001F53E8(char*, long, long, unsigned int, int);
extern "C" void func_001E4BE8(char*);
extern "C" void func_001F5360(char*, int);

struct Pkt_001F6E80 {
    int m0;
    int m4;
    char* m8;
    int mC;
    long m10;
    long m18;
};

struct Buf_001F6E80 {
    char m_data[0x50008];
    int m_size;
};

struct Obj_001F6E80 {
    int Send(Pkt_001F6E80* p, Buf_001F6E80* b);
};

int Obj_001F6E80::Send(Pkt_001F6E80* p, Buf_001F6E80* b)
{
    unsigned int addr0;
    int size0;
    unsigned int addr1;
    int size1;
    char* src = p->m8;
    int len = p->mC;
    int n = b->m_data + b->m_size - src;
    if (len < n)
        n = len;
    int rest = len - n;
    func_001F5340(D_0038E320 + 0x6735C0, &addr0, &size0, &addr1, &size1);
    int r = func_001F7090((addr0 & 0x0FFFFFFF) | 0x20000000, size0, (addr1 & 0x0FFFFFFF) | 0x20000000, size1, src, n, b->m_data, rest);
    if (r > 0) {
        if (!func_001F53E8(D_0038E320 + 0x6735C0, p->m10, p->m18, addr0, r))
            func_001E4BE8(D_00366430);
    }
    func_001F5360(D_0038E320 + 0x6735C0, r);
    return r > 0;
}
