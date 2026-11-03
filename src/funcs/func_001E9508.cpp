extern "C" unsigned char* func_001E93D8(unsigned char*, unsigned char, unsigned int);
extern "C" unsigned char* func_001EC7F8(unsigned char*, int);
extern "C" unsigned char* func_001EC860(unsigned char*, unsigned short);

extern "C" unsigned int func_001E9508(unsigned int name, int v, unsigned char* p, unsigned int size)
{
    unsigned char buf[32];
    unsigned char* start = p;
    int t = 1;
    if (v == 0)
        t = 0x12;
    else if (v >= 0 && v <= 0xFF)
        t = 0x10;
    else if (v >= 0 && v <= 0xFFFF)
        t = 0x11;
    else if (v >= -0x80 && v <= 0x7F)
        t = 0xE;
    else if (v >= -0x8000 && v <= 0x7FFF)
        t = 0xF;
    unsigned char* q = buf;
    switch (t) {
    case 1:
        q = func_001E93D8(buf, t, name);
        q = func_001EC7F8(q, v);
        break;
    case 0xE:
    case 0x10:
        q = func_001E93D8(buf, t, name);
        *q++ = v;
        break;
    case 0xF:
    case 0x11:
        q = func_001E93D8(buf, t, name);
        q = func_001EC860(q, v);
        break;
    case 0x12:
        q = func_001E93D8(buf, t, name);
        break;
    }
    unsigned int len = q - buf;
    if (size < len)
        return 0;
    unsigned char* s = buf;
    for (unsigned int i = 0; i < len; i++)
        *p++ = *s++;
    return p - start;
}
