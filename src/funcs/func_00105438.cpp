// CRC-32 (reflected, table D_0034D280) continued over len bytes.
extern unsigned int D_0034D280[256];

extern "C" unsigned int func_00105438(const char* data, int len, unsigned int crc)
{
    for (int i = 0; i < len; i++) {
        crc = D_0034D280[(crc ^ data[i]) & 0xFF] ^ ((crc >> 8) & 0x00FFFFFF);
    }
    return crc;
}
