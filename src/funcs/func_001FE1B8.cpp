extern "C" unsigned int func_001053C8(const unsigned char* s, int len);

struct Pair_001FE1B8 {
    char b[2];
};

union Key_001FE1B8 {
    unsigned short s;
    Pair_001FE1B8 p;
};

static inline void Xor_001FE1B8(char* d, unsigned char* s, int n, unsigned char k)
{
    for (int i = 0; i < n; i++) *d++ = k ^ *s++;
}

extern "C" void func_001FE1B8(void* self, unsigned char* src, char* dst, int len, int* out)
{
    unsigned int crc = func_001053C8(src, len);
    Key_001FE1B8 k;
    k.s = (crc >> 16) + crc;
    unsigned char key = k.p.b[0];
    *(Pair_001FE1B8*)dst = k.p;
    Xor_001FE1B8(dst + 2, src, len, key);
    *out = len + 2;
}
