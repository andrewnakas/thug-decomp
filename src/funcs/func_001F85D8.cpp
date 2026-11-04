extern char D_003666A0[];

struct Host_001F85D8 {
    char pad[0xC];
    char** m_addrs;
};

extern "C" int func_003250C0(int a, void* out);
extern "C" unsigned int func_0010FC30();
extern "C" int func_003276D8(int* state);
extern "C" void func_003247E8(int ms);
extern "C" int func_00326AC8();
extern "C" Host_001F85D8* func_00326B68(char* name);
extern "C" char* func_00327098(int addr);

static inline bool TimedOut_001F85D8(unsigned int ms, unsigned int now, unsigned int start)
{
    return now - start > ms;
}

struct Net_001F85D8 {
    char pad[0x13C];
    char m_addr[4];

    bool Connect();
};

extern "C" void func_001FA658(Net_001F85D8* n, int err);
extern "C" int func_001FA648(Net_001F85D8* n);
extern "C" int func_001FA588(Net_001F85D8* n);
extern "C" char* func_00331A9C(char* dst, const char* src);

bool Net_001F85D8::Connect()
{
    int info;
    if (func_003250C0(1, &info)) {
        func_001FA658(this, 1);
        return false;
    err_state:
        func_001FA658(this, 4);
        return false;
    err_time:
        func_001FA658(this, 4);
        return false;
    err_host:
        func_001FA658(this, 6);
        return false;
    }
    if (func_001FA648(this) == 1 || func_001FA648(this) == 3) {
        int last = -2;
        int state = -1;
        unsigned int start = func_0010FC30();
        while (state != 3) {
            if (func_003276D8(&state)) {
                goto err_state;
            }
            if (state == last) {
                func_003247E8(10);
            } else {
                last = state;
            }
            if (TimedOut_001F85D8(10000, func_0010FC30(), start)) {
                goto err_time;
            }
        }
    }
    unsigned int start = func_0010FC30();
    while (!func_00326AC8()) {
        func_003247E8(500);
        if (TimedOut_001F85D8(10000, func_0010FC30(), start)) {
            return false;
        }
    }
    if (!func_001FA588(this)) {
        return true;
    }
    bool found = false;
    start = func_0010FC30();
    int addr;
    do {
        Host_001F85D8* h = func_00326B68(D_003666A0);
        if (h && h->m_addrs[0]) {
            __builtin_memcpy(&addr, h->m_addrs[0], 4);
            if (addr) {
                found = true;
            }
        }
        if (!found) {
            func_003247E8(500);
        }
        if (TimedOut_001F85D8(10000, func_0010FC30(), start)) {
            goto err_host;
        }
    } while (!found);
    func_00331A9C(m_addr, func_00327098(addr));
    return true;
}
