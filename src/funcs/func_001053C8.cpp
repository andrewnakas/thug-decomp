// CRC-32 (reflected, table D_0034D280) of len bytes, initial value ~0.
extern unsigned int D_0034D280[256];

extern "C" unsigned int func_001053C8(const char* data, int len)
{
    if (!data || len <= 0) {
        return 0;
    }
    unsigned int crc = 0xFFFFFFFF;
    for (int i = 0; i < len; i++) {
        crc = D_0034D280[(crc ^ data[i]) & 0xFF] ^ ((crc >> 8) & 0x00FFFFFF);
    }
    return crc;
}
