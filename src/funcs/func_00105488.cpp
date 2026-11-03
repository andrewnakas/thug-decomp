// CRC-32 (reflected, table D_0034D280) of len bytes, initial value ~0,
// case-folded ('A'-'Z' -> 'a'-'z') and with '/' treated as '\\'.
extern unsigned int D_0034D280[256];

extern "C" unsigned int func_00105488(const char* data, int len)
{
    if (!data || len <= 0) {
        return 0;
    }
    unsigned int crc = 0xFFFFFFFF;
    for (int i = 0; i < len; i++) {
        char c = data[i];
        if (c >= 0x41 && c <= 0x5A) {
            c += 0x20;
        }
        if (c == 0x2F) {
            c = 0x5C;
        }
        crc = D_0034D280[(crc ^ c) & 0xFF] ^ ((crc >> 8) & 0x00FFFFFF);
    }
    return crc;
}
