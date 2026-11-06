void func_00164860(int type, unsigned int* p, short a, short b)
{
    switch (type) {
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
        break;
    case 0x50:
        p++;
        *p = (*p & 0xFFFFC000) | (a & 0x3FFF);
        break;
    case 6:
    case 7:
        *p = (*p & 0xFFFFC000) | (a & 0x3FFF);
        if (b < 0)
            break;
        p++;
        *p = (*p & 0xFFF8001F) | ((b & 0x3FFF) << 5);
        break;
    case 0x16:
    case 0x17:
        p++;
        *p = (*p & 0xFFF8001F) | ((a & 0x3FFF) << 5);
        break;
    }
}
