struct Card_00113380;
extern "C" int func_003236D0(int port, int slot, const char* name, int mode);
extern "C" int func_00113000(Card_00113380* self);
extern "C" void* func_001046B0(int size);
extern "C" void* func_00113900(void* p, int fd, Card_00113380* card);

struct Card_00113380 {
    int m0;
    int m_port;
    int m_slot;
    int m_error;
    void* Open(const char* name, int flags);
};

void* Card_00113380::Open(const char* name, int flags)
{
    int mode = flags & 1;
    if (flags & 2) {
        mode |= 2;
    }
    if (flags & 4) {
        mode |= 0x200;
    }
    void* file = 0;
    if (func_003236D0(m_port, m_slot, name, mode)) {
        m_error = 8;
        return 0;
    }
    int fd = func_00113000(this);
    if (fd >= 0) {
        file = func_00113900(func_001046B0(0x58), fd, this);
    }
    return file;
}
