struct Hdr_0010D4A0 {
    int m0;
    int m4;
    unsigned short m8;
};

extern "C" char* func_0010D4A0(Hdr_0010D4A0* h, int align)
{
    int n = h->m0;
    if (h->m4) n = h->m4;
    n = (n + 3) & ~3;
    char* p = (char*)h + 0x10;
    p += h->m8;
    if (align) p = (char*)(((unsigned int)p + 15) & 0xFFFFFFF0);
    return p + n;
}
