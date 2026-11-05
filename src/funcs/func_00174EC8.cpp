struct Geom_00174EC8 {
    char pad0[0xC];
    float mC;
    int pad10;
    int m14;
};

extern "C" unsigned char* func_00174FB8(unsigned char* p, Geom_00174EC8* geom, int a, int b, int c, int* count);
extern "C" void func_00174EA8();

static inline unsigned char* Read(unsigned char* src, void* dst, int n)
{
    unsigned char* d = (unsigned char*)dst;
    unsigned char* s = src;
    int i = n;
    while (i > 0) {
        *d++ = *s++;
        i--;
    }
    return s;
}

extern "C" unsigned char* func_00174EC8(unsigned char* p, Geom_00174EC8* geom, int a, int b, int c)
{
    int count;
    int i;
    int end;
    geom->mC = -1.0f;
    count = 0;
    for (i = 0; i < geom->m14; i++) {
        p = func_00174FB8(p, geom, a, b, c, &count);
    }
    end = -1;
    p = Read(p, &end, 4);
    func_00174EA8();
    return p;
}
