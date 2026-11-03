// CRC-32 (reflected, table D_0034D280) of a NUL-terminated string, initial
// value ~0, case-folded ('A'-'Z' -> 'a'-'z') and with '/' treated as '\\'.
extern unsigned int D_0034D280[256];

extern "C" unsigned int func_00105520(const char* str)
{
    if (!str) {
        return 0;
    }
    unsigned int crc = 0xFFFFFFFF;
    const char* p = str;
    char c;
    while ((c = *p++) != 0) {
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
