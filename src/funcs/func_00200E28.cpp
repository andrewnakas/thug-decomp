extern "C" void func_001FE1B8(void* self, void* src, void* dst, int n, int* out);
extern "C" int func_00325F00(int fd, void* buf, int n, int flags);

struct Obj_00200E28 {
    char m_pad0[0x1820];
    int m1820;
    char m_pad1824[0x1834 - 0x1824];
    int m1834;
    char m_pad1838[0x1854 - 0x1838];
    char m1854[0x227C - 0x1854];
    int m227C;
    bool Send(void* buf, int n, int flags);
};

bool Obj_00200E28::Send(void* buf, int n, int flags)
{
    if (!m1834)
        return false;
    int r;
    if (m227C & 0x20) {
        int len;
        func_001FE1B8(this, buf, m1854, n, &len);
        r = func_00325F00(m1820, m1854, len, flags);
    } else {
        r = func_00325F00(m1820, buf, n, flags);
    }
    return r != -1;
}
