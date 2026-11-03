extern "C" int func_0031AF08(int, int, int);

struct Strm_001F7ED0;
extern "C" void func_001F8080(int*, int*, int*, int*, Strm_001F7ED0*, int);
extern "C" int func_001F8128(int, int, int, int, int, int, int, int);

struct Strm_001F7ED0 {
    int m0;
    int m_pad[11];
    int m30;
    int m34;
    int m38;
    int m3C;
    int m_pad2;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
};

int func_001F7ED0(Strm_001F7ED0* s)
{
    int ret = 0;
    union {
        int qw __attribute__((mode(TI)));
        struct {
            int addr0;
            int size0;
            int addr1;
            int size1;
        } v;
    } u;
    switch (s->m0) {
    case 0:
        return 0;
    case 1:
        u.v.addr0 = s->m44 + s->m54 % s->m48;
        u.v.size0 = s->m48 - s->m54;
        u.v.addr1 = 0;
        u.v.size1 = 0;
        break;
    case 2:
        {
            int pos = func_0031AF08(1, 0x8100, 0) & 0xFFFFFF;
            func_001F8080(&u.v.addr0, &u.v.size0, &u.v.addr1, &u.v.size1, s, pos - s->m44);
        }
        break;
    case 3:
        return 0;
    }
    int avail = (s->m38 / 1024) * 1024;
    int mod = (s->m34 - s->m38 + s->m3C) % s->m3C;
    int n0 = s->m3C - mod;
    if (avail < n0)
        n0 = avail;
    int n1 = avail - n0;
    int dst = s->m30 + mod;
    if (u.v.size0 + u.v.size1 >= 0x400 && n0 + n1 >= 0x400)
        { int a1 = u.v.addr1; ret = func_001F8128(u.v.addr0, u.v.size0, a1, u.v.size1, dst, n0, s->m30, n1); }
    s->m38 -= ret;
    s->m54 += ret;
    s->m4C = (s->m4C + ret) % s->m48;
    return ret;
}
