extern "C" unsigned char* func_00164D20(unsigned char* code);

extern "C" void func_00161E70(unsigned char* pkt, unsigned int* src, int skipW)
{
    unsigned char* end = pkt + (*(unsigned short*)pkt * 16 + 16);
    unsigned char* p = pkt + 8;
    do {
        if ((*(unsigned int*)p & 0x7F000001) == 0x05000001) {
            p = func_00164D20(p);
            int n = ((unsigned char)(p[2] - 1) + 1) * 4;
            int i;
            if ((p[3] & 0x7F) == 0x6C) {
                unsigned int* dst = (unsigned int*)(p + 4);
                if (skipW) {
                    for (i = 0; i < n; i++, dst++, src++) {
                        if ((i & 3) != 3) *dst = *src;
                    }
                } else {
                    if (n != 0) {
                        i = n;
                        do {
                            *dst++ = *src++;
                        } while (--i);
                    }
                }
            } else {
                unsigned short* dst = (unsigned short*)(p + 4);
                if (skipW) {
                    for (i = 0; i < n; i++, dst++, src++) {
                        if ((i & 3) != 3) *dst = *src;
                    }
                } else {
                    if (n != 0) {
                        i = n;
                        do {
                            *dst++ = *src++;
                        } while (--i);
                    }
                }
            }
        }
        p = func_00164D20(p);
    } while (p < end);
}
