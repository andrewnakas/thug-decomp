struct Strm_001F8080 {
    int m0;
    int m_pad[16];
    int m44;
    int m48;
    int m4C;
};

void func_001F8080(int* addr0, int* size0, int* addr1, int* size1, Strm_001F8080* s, int pos)
{
    int len = (pos + s->m48 - s->m4C - 0x400) % s->m48;
    len = (len / 1024) * 1024;
    if (s->m48 - s->m4C >= len) {
        *addr0 = s->m44 + s->m4C;
        *size0 = len;
        *addr1 = 0;
        *size1 = 0;
    } else {
        *addr0 = s->m44 + s->m4C;
        *size0 = s->m48 - s->m4C;
        *addr1 = s->m44;
        *size1 = len - (s->m48 - s->m4C);
    }
}
