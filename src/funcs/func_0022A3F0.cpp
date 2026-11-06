extern char D_00372568[];
extern void* D_0038E8A4;

struct Sym_0022A3F0 {
    char pad0[2];
    unsigned char m_type;
};

typedef void (*Callback_0022A3F0)(void* params, unsigned char* start);

extern "C" unsigned char* func_001F2F88(void* mgr, unsigned int name);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" unsigned char* func_001EDAD8(unsigned char* p);
extern "C" unsigned int func_001EC7A0(unsigned char* p);
extern "C" Sym_0022A3F0* func_001E5040(unsigned int id);
extern "C" void func_001E6B30(void* s);
extern "C" unsigned char* func_001ED6B8(void* s, unsigned char* p, void* params);
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" unsigned char* func_001EB070(unsigned char* p);
extern "C" void func_001F3108(void* mgr, unsigned int name);
extern "C" void func_001E6AE8(void* p, int v);

extern "C" void func_0022A3F0(unsigned int name, unsigned int key, Callback_0022A3F0 cb, void* extra, int depth)
{
    if (depth >= 6)
        return;
    void* mgr = D_0038E8A4;
    int done = 0;
    unsigned char* script = func_001F2F88(mgr, name);
    void* params = func_001E6978(func_001190D0(8));
    unsigned char* p = func_001EDAD8(script);
    do {
        switch (*p) {
        case 0x43:
            p = func_001EDAD8(p + 5);
            break;
        case 0x16:
        case 0x44: {
            unsigned char* start = p;
            p++;
            unsigned int id = func_001EC7A0(p);
            p += 4;
            if (*p == 7)
                break;
            Sym_0022A3F0* sym = func_001E5040(id);
            if (!sym)
                break;
            switch (sym->m_type) {
            case 8:
                if (id == key) {
                    func_001E6B30(params);
                    p = func_001ED6B8(params, p, extra);
                    cb(params, start);
                } else {
                    p = func_001EDAD8(p);
                }
                break;
            case 9:
                if (id == key) {
                    func_001E6B30(params);
                    p = func_001ED6B8(params, p, extra);
                    cb(params, start);
                    if (key == 0xE5399FB2) {
                        unsigned int sub = 0;
                        if (func_001E84E8(params, D_00372568, &sub, 0))
                            func_0022A3F0(sub, 0xE5399FB2, cb, 0, depth + 1);
                    }
                } else {
                    p = func_001EDAD8(p);
                }
                break;
            case 7:
                func_001E6B30(params);
                p = func_001ED6B8(params, p, extra);
                if (id == key)
                    cb(params, start);
                else
                    p = func_001EDAD8(p);
                func_0022A3F0(id, key, cb, params, depth + 1);
                break;
            }
            break;
        }
        case 0x21:
            p = func_001EDAD8(func_001EB070(p));
            break;
        case 0x25:
            p = func_001EB070(p);
            if (*p == 0x39)
                p = func_001EB070(p);
            if (*p == 0xE)
                p = func_001EDAD8(p);
            break;
        case 0x24:
            done = 1;
            break;
        default:
            p = func_001EB070(p);
            break;
        }
    } while (!done);
    func_001F3108(mgr, name);
    if (params)
        func_001E6AE8(params, 3);
}
