struct Dma_00161B20 {
    unsigned short m0;
};

extern "C" unsigned int* func_00164D20(unsigned int* p);
extern "C" void func_00161A40(Dma_00161B20* d, unsigned char* buf, int size, int flag, unsigned int mask, unsigned int code);

extern "C" void func_00161B20(Dma_00161B20* d, unsigned char* buf, int flag)
{
    unsigned char* dst;
    unsigned char* src;
    unsigned int* p = (unsigned int*)((char*)d + 8);
    unsigned int* end = (unsigned int*)((char*)d + (d->m0 * 16 + 16));
    *(flag ? &src : &dst) = buf;
    do {
        unsigned int code = *p;
        if ((code & 0x7B000000) == 0x6A000000) {
            if ((code & 0x7F000000) == 0x6E000000) {
                func_00161A40(d, buf, 4, flag, 0x7F000000, 0x6E000000);
                return;
            }
            *(!flag ? &src : &dst) = (unsigned char*)(p + 1);
            int n = ((unsigned char*)p)[2];
            for (int i = 0; i < n; i++) {
                *dst++ = *src++;
                *dst++ = *src++;
                *dst++ = *src++;
                (*(flag ? &src : &dst))++;
            }
        }
        p = func_00164D20(p);
    } while (p < end);
}
