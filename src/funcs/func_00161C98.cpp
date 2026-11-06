extern "C" unsigned char* func_00164D20(unsigned char* code);

int func_00161C98(unsigned short* pkt)
{
    int n = 0;
    unsigned char* end = (unsigned char*)pkt + (pkt[0] * 16 + 16);
    unsigned char* p = (unsigned char*)pkt + 8;
    do {
        if ((p[3] & 0x7F) == 5 && p[0] == 1) {
            n = 32 >> (func_00164D20(p)[3] & 3);
            break;
        }
        p = func_00164D20(p);
    } while (p < end);
    return n;
}
