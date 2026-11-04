extern "C" unsigned char* func_001EB070(unsigned char* p);
extern "C" unsigned int func_00105438(unsigned char* p, int len, unsigned int h);

extern "C" unsigned int func_001ECDB8(unsigned char* s)
{
    unsigned int h = 0xFFFFFFFF;
    while (*s != '$') {
        unsigned char* b = s;
        s = func_001EB070(b);
        if ((unsigned int)(*b - 1) >= 2) h = func_00105438(b, s - b, h);
    }
    return h;
}
