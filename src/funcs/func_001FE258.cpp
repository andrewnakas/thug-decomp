extern "C" void* func_00331404(void* dst, const void* src, int n);
extern "C" unsigned int func_001053C8(const void* data, int n);

struct Hdr_001FE258 {
    char key;
    char sum;
};

struct Obj_001FE258 {
    char m_pad[0x227C];
    int m_flags;
    bool Decode(unsigned char* src, unsigned char* dst, int len);
};

bool Obj_001FE258::Decode(unsigned char* src, unsigned char* dst, int len)
{
    if (len < 3)
        return false;
    int n = len - 2;
    if (!(m_flags & 0x20)) {
        func_00331404(dst, src, len);
        return true;
    }
    union {
        Hdr_001FE258 h;
        unsigned short s;
    } hdr;
    unsigned char buf[0x520];
    hdr.h = *(Hdr_001FE258*)src;
    func_00331404(buf, src + 2, n);
    unsigned char key = hdr.h.key;
    unsigned char* p = buf;
    for (int i = 0; i < n; i++)
        *p++ ^= key;
    unsigned int crc = func_001053C8(buf, n);
    if ((unsigned short)((crc >> 16) + crc) != hdr.s)
        return false;
    func_00331404(dst, buf, n);
    return true;
}
