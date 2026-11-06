struct Struct_001E99F8;

extern "C" unsigned char* func_001E93D8(unsigned char*, int, unsigned int);
extern "C" unsigned int func_001E9B08(Struct_001E99F8*, unsigned char*, unsigned int, int);

extern "C" unsigned int func_001E99F8(unsigned int name, Struct_001E99F8* s, unsigned char* p, unsigned int size, int flags)
{
    unsigned char* start = p;
    if (size < 5)
        return 0;
    p = func_001E93D8(p, 10, name);
    unsigned int hdr = p - start;
    unsigned int w = func_001E9B08(s, p, size - hdr, flags);
    if (!w)
        return 0;
    return hdr + w;
}
