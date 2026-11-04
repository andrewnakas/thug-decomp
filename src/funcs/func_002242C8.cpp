extern "C" unsigned int func_001F0D78(const char* s);

char* func_002242C8(char* buf, const char* name, unsigned int type)
{
    unsigned int crc = func_001F0D78(name);
    for (int i = 0; i < 8; i++) {
        unsigned int r = crc % 26;
        buf[i] = r + 'a';
        crc = (crc - r) / 26;
    }
    switch (type) {
    case 0xB010F357:
        buf[7] = 'a';
        break;
    case 0x61A1BC57:
        buf[7] = 'f';
        break;
    case 0x3BF882CC:
        buf[7] = 'c';
        break;
    case 0x26C80B0D:
        buf[7] = 'd';
        break;
    case 0xCA41692D:
        buf[7] = 'e';
        break;
    case 0x62896EDF:
        buf[7] = 'g';
        break;
    case 0xFFFFFFFF:
        break;
    }
    buf[8] = 0;
    return buf;
}
