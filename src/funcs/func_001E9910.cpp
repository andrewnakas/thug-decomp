struct Pair_001E9910 {
    int m0;
    float x;
    float y;
};

extern "C" unsigned char* func_001E93D8(unsigned char*, int, unsigned int);
extern "C" unsigned char* func_001EC828(unsigned char* p, float v);

extern "C" unsigned int func_001E9910(unsigned int name, Pair_001E9910* v, unsigned char* p, unsigned int size)
{
    unsigned char* start = p;
    if (size < 13)
        return 0;
    p = func_001E93D8(p, 5, name);
    p = func_001EC828(p, v->x);
    p = func_001EC828(p, v->y);
    return p - start;
}
