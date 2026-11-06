struct Slot_00254978 {
    int m_index;
    unsigned int m_id;
};

extern char D_00390868[];
extern char D_003751D0[];
extern char D_003751E8[];
extern char D_003751F8[];
extern char D_00375208[];
extern "C" bool func_001E5628(unsigned int name, int a);
extern "C" int func_00113E98(char* buf);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" int func_0018A370(void* params, int a);
extern "C" void func_001E6B30(void* params);
extern "C" void func_00113EE8();
extern "C" void func_001E6AE8(void* params, int a);

struct Obj_00254978 {
    char pad[0x68];
    Slot_00254978 m_slots[32];
    unsigned int Fn(unsigned int mask, int n, int noPad, unsigned int flags);
};

unsigned int Obj_00254978::Fn(unsigned int mask, int n, int noPad, unsigned int flags)
{
    for (int i = 0; i < 32; i++) {
        if ((mask & (1 << m_slots[i].m_index)) && m_slots[i].m_id) {
            if (--n < 0) {
                return m_slots[i].m_id;
            }
        }
    }
    if (!((flags & 0x100) && func_001E5628(0xF3E055E1, 1))) {
        if ((mask & 0x800) && n == 0) {
            return 0x2E6EF8E7;
        }
    }
    if (!noPad) {
        unsigned int key = 0;
        char buf[0x100];
        int cnt = func_00113E98(buf);
        if (cnt > 0) {
            for (int i = 0; i < cnt; i++) {
                if (buf[i] == 0x1A) {
                    key = 0x7EE0FD2A;
                    void* params = func_001E6978(func_001190D0(8));
                    func_001E7360(params, func_001F0D78(D_00390868), func_001F0D78(D_003751D0));
                    if (!func_0018A370(params, 0)) {
                        key = 0x2E6EF8E7;
                    }
                    func_00113EE8();
                    if (params) {
                        func_001E6AE8(params, 3);
                    }
                    break;
                } else if (buf[i] == 0x19 || buf[i] == 0x20) {
                    const char* name = D_00390868;
                    void* params = func_001E6978(func_001190D0(8));
                    func_001E7360(params, func_001F0D78(name), func_001F0D78(D_003751E8));
                    if (!func_0018A370(params, 0)) {
                        func_001E6B30(params);
                        func_001E7360(params, func_001F0D78(name), func_001F0D78(D_003751F8));
                        if (func_0018A370(params, 0) == 1 && buf[i] == 0x20) {
                            return 0;
                        }
                        func_001E6B30(params);
                        func_001E7360(params, func_001F0D78(name), func_001F0D78(D_003751D0));
                        bool ok;
                        if (func_0018A370(params, 0)) {
                            ok = true;
                        } else {
                            func_001E6B30(params);
                            func_001E7360(params, func_001F0D78(name), func_001F0D78(D_00375208));
                            if (func_0018A370(params, 0)) {
                                ok = true;
                            } else {
                                ok = false;
                            }
                        }
                        if (ok) {
                            key = 0x1E3E253B;
                            func_00113EE8();
                        }
                    }
                    if (params) {
                        func_001E6AE8(params, 3);
                    }
                }
            }
        }
        return key;
    }
    return 0;
}
