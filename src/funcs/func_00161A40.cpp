extern "C" unsigned char* func_00164D20(unsigned char* code);

void func_00161A40(unsigned short* pkt, unsigned int* user, int scale, int toPacket, unsigned int mask, unsigned int want)
{
    unsigned int* ptr[2];
    unsigned char* end = (unsigned char*)pkt + (pkt[0] * 16 + 16);
    unsigned int** u = toPacket ? &ptr[1] : &ptr[0];
    unsigned int** d = !toPacket ? &ptr[1] : &ptr[0];
    *u = user;
    unsigned char* p = (unsigned char*)pkt + 8;
    do {
        if ((*(unsigned int*)p & mask) == want) {
            *d = (unsigned int*)(p + 4);
            int n = (p[2] * scale) >> 2;
            for (int i = 0; i < n; i++)
                *ptr[0]++ = *ptr[1]++;
        }
        p = func_00164D20(p);
    } while (p < end);
}
