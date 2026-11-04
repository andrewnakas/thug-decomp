extern char* D_0038E320;

extern "C" void func_001F7CE8(char*, int*, int*, int*, int*);
extern "C" int func_001F7090(int, int, int, int, char*, int, char*, int);
extern "C" void func_001F7D98(char*, int);

struct Pkt_001F6FB0 {
    int m0;
    int m4;
    char* m8;
    int mC;
};

struct Buf_001F6FB0 {
    char m_data[0x50008];
    int m_size;
};

struct Obj_001F6FB0 {
    int Send(Pkt_001F6FB0* p, Buf_001F6FB0* b);
};

int Obj_001F6FB0::Send(Pkt_001F6FB0* p, Buf_001F6FB0* b)
{
    int addr0;
    int size0;
    int addr1;
    int size1;
    char* src = p->m8 + 4;
    char* end = b->m_data + b->m_size;
    if (src >= end)
        src -= b->m_size;
    int len = p->mC - 4;
    int n = end - src;
    if (len < n)
        n = len;
    int rest = len - n;
    func_001F7CE8(D_0038E320 + 0x673680, &addr0, &size0, &addr1, &size1);
    int r = func_001F7090(addr0, size0, addr1, size1, src, n, b->m_data, rest);
    func_001F7D98(D_0038E320 + 0x673680, r);
    return r > 0;
}
