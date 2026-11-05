extern "C" unsigned char* func_001EC880(unsigned char* p)
{
    for (;;) {
        if (*p == 1) {
            p++;
            continue;
        }
        if (*p == 2) {
            p += 5;
            continue;
        }
        return p;
    }
}
