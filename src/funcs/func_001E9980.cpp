struct Vec_001E9980 {
    float x, y, z, w;
};

extern "C" unsigned char* func_001E93D8(unsigned char*, int, unsigned int);
extern "C" unsigned char* func_001EC828(unsigned char*, float);

extern "C" unsigned int func_001E9980(unsigned int name, Vec_001E9980* v, unsigned char* p, unsigned int size)
{
    unsigned char* start = p;
    if (size < 17)
        return 0;
    p = func_001E93D8(p, 6, name);
    p = func_001EC828(p, v->y);
    p = func_001EC828(p, v->z);
    p = func_001EC828(p, v->w);
    return p - start;
}
