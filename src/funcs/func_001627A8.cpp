extern "C" unsigned char* func_00164D20(unsigned char* code);

void func_001627A8(unsigned short* pkt)
{
    unsigned char* p = (unsigned char*)pkt + 8;
    unsigned char* end = (unsigned char*)pkt + (pkt[0] * 16 + 16);
    unsigned int* dst = (unsigned int*)p;
    unsigned int* src = dst;
    while (p < end) {
        if (p[3] == 0) {
            src++;
            p = func_00164D20(p);
        } else {
            p = func_00164D20(p);
            while (src < (unsigned int*)p)
                *dst++ = *src++;
        }
    }
    while ((unsigned int)dst & 0xF) {
        *dst = 0;
        dst++;
    }
    pkt[0] = ((unsigned char*)dst - (unsigned char*)pkt - 16) >> 4;
}
