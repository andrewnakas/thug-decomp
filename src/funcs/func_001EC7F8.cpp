extern "C" unsigned char* func_001EC7F8(unsigned char* p, unsigned int v)
{
    *p = v;
    p++;
    *p = v >> 8;
    p++;
    *p = v >> 16;
    p++;
    *p = v >> 24;
    p++;
    return p;
}
