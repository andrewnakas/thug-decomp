extern "C" unsigned int func_00331BB8(const unsigned char*);
extern "C" unsigned char* func_001E93D8(unsigned char*, int, unsigned int);

extern "C" unsigned int func_001E9850(unsigned int name, const unsigned char* str, unsigned char* p, unsigned int size)
{
    unsigned char* start = p;
    unsigned int len = func_00331BB8(str);
    if (size < len + 6)
        return 0;
    p = func_001E93D8(p, 4, name);
    for (unsigned int i = 0; i < len; i++)
        *p++ = *str++;
    *p++ = 0;
    return p - start;
}
