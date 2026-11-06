struct Struct_001E9A80;

extern "C" unsigned char* func_001E93D8(unsigned char*, int, unsigned int);
extern "C" unsigned int func_001EA0B8(Struct_001E9A80*, unsigned char*, unsigned int, int);

extern "C" unsigned int func_001E9A80(unsigned int name, Struct_001E9A80* s, unsigned char* p, unsigned int size, int flags)
{
    unsigned char* start = p;
    if (size < 5)
        return 0;
    p = func_001E93D8(p, 12, name);
    unsigned int len = p - start;
    unsigned int w = func_001EA0B8(s, p, size - len, flags);
    if (!w)
        return 0;
    return len + w;
}
