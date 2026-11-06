extern "C" void func_00183A18(unsigned char* buf, unsigned int mask)
{
    unsigned char* p = buf + 1;
    unsigned int bit = 1;
    for (int i = 0; i < 25; i++) {
        if (mask & bit) {
            if ((unsigned int)i < 4 || i == 18 || i == 19 || i == 20 || i == 21) {
                *p = 0x80;
            } else {
                *p = 0;
            }
        }
        bit <<= 1;
        p++;
    }
}
