extern "C" unsigned char* func_001E93D8(unsigned char*, int, unsigned int);
extern "C" unsigned char* func_001EC828(unsigned char*, float);

extern "C" unsigned int func_001E9688(unsigned int name, unsigned char* p, unsigned int size, float f)
{
    unsigned char* start = p;
    float a;
    if (f < 0.0f)
        a = -f;
    else
        a = f;
    if (a < 0.0001f) {
        if (size < 5)
            return 0;
        p = func_001E93D8(p, 0x13, name);
    } else {
        if (size < 9)
            return 0;
        p = func_001E93D8(p, 2, name);
        p = func_001EC828(p, f);
    }
    return p - start;
}
