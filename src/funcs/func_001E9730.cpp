extern "C" unsigned char* func_001E93D8(unsigned char*, int, unsigned int);
extern "C" unsigned char* func_001EC7F8(unsigned char*, void*);

extern "C" unsigned int func_001E9730(unsigned int name, void* value, unsigned char* p, unsigned int size)
{
    unsigned char* start = p;
    if (size < 9)
        return 0;
    p = func_001E93D8(p, 13, name);
    p = func_001EC7F8(p, value);
    return p - start;
}
