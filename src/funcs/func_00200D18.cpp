struct SockAddr_00200D18 {
    unsigned short family;
    unsigned short port;
    unsigned int addr;
    char zero[8];
};

struct Net_00200D18 {
    char pad0[0x1820];
    int m_socket;
    char pad1824[0x1854 - 0x1824];
    char m_buffer[0x227C - 0x1854];
    unsigned int m_flags;
    bool SendTo(unsigned int addr, unsigned short port, char* data, int len, int flags);
};

extern "C" void* func_003315B8(void* p, int c, int n);
extern "C" unsigned short func_00326B40(unsigned short v);
extern "C" void func_001FE1B8(Net_00200D18* net, char* src, char* dst, int len, int* out_len);
extern "C" int func_003260D0(int s, char* data, int len, int flags, SockAddr_00200D18* to, int tolen);
extern "C" int func_003264C8(int s);

bool Net_00200D18::SendTo(unsigned int addr, unsigned short port, char* data, int len, int flags)
{
    SockAddr_00200D18 to;
    func_003315B8(&to, 0, sizeof(to));
    to.family = 2;
    to.port = func_00326B40(port);
    to.addr = addr;
    int ret;
    if (m_flags & 0x20) {
        int out_len;
        func_001FE1B8(this, data, m_buffer, len, &out_len);
        ret = func_003260D0(m_socket, m_buffer, out_len, flags, &to, sizeof(to));
    } else {
        ret = func_003260D0(m_socket, data, len, flags, &to, sizeof(to));
    }
    if (ret == -1) {
        int err = func_003264C8(m_socket);
        if (err != 6 && err != 0x16) {
            return false;
        }
    }
    return true;
}
