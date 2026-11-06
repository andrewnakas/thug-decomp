extern char D_00372238[];
extern char D_00372250[];
extern char D_0038FA30[];
extern char D_00372260[];
extern char D_0038F9D0[];
extern char D_00372270[];
extern char D_00372218[];
extern char D_003720D0[];
extern char D_00372280[];
extern char D_00372290[];
extern char D_003722A0[];
extern char D_003722B0[];
extern char D_003722C0[];
extern char D_003722D0[];
extern int D_00388814;
extern void* D_00388EFC;

extern "C" void func_001DFF88(int v);
extern "C" void func_001E0038(int v);
extern "C" void* func_00112FB8(void* a, int b, int c);
extern "C" bool func_001E7D18(void* params, char* name, char** out, int required);
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" char* func_00225FE8(unsigned int type, char* name);
extern "C" bool func_00113110(void* card, char* name);
extern "C" bool func_00113320(void* card, char* name);
extern "C" char* func_00106810();
extern "C" char* func_002242C8(char* buf, char* name, unsigned int type);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00331BB8(const char* s);
extern "C" unsigned int func_00224400(int c);

bool func_00227250(void* params, void* script)
{
    if (D_00388814 != 4) {
        func_001DFF88(1);
        func_001E0038(1);
    }
    void* card = func_00112FB8(D_00388EFC, 0, 0);
    if (!card) {
        if (D_00388814 != 4) {
            func_001DFF88(-1);
            func_001E0038(-1);
        }
        return false;
    }
    char* fname = 0;
    func_001E7D18(params, D_00372238, &fname, 0);
    bool ok = true;
    char* dir = 0;
    func_001E7D18(params, D_00372250, &dir, 0);
    unsigned int type = 0;
    func_001E84E8(params, D_0038FA30, &type, 0);
    char* name = D_0038F9D0;
    func_001E7D18(params, D_00372260, &name, 0);
    char path[0x70];
    char buf1[0x20];
    char buf2[0x20];
    char base[0x70];
    char sub[0x70];
    switch (D_00388814) {
    case 5:
        if (dir) {
            if (!func_00113320(card, dir))
                ok = false;
        } else {
            char* prefix = func_00106810();
            func_002242C8(buf1, name, type);
            func_003331D0(path, D_00372270, prefix, buf1, prefix, buf1);
            if (!func_00113320(card, path))
                ok = false;
        }
        break;
    case 4:
        if (!fname)
            fname = func_00225FE8(type, name);
        if (!func_00113110(card, fname))
            ok = false;
        break;
    case 1:
    case 2:
    case 3: {
        if (!dir) {
            char* prefix = func_00106810();
            func_002242C8(buf2, name, type);
            func_003331D0(path, D_00372218, prefix, buf2, prefix, buf2);
            dir = path;
        }
        unsigned int t = func_00224400(dir[func_00331BB8(dir) - 1]);
        char* s = dir;
        char* d = base;
        *d++ = *s++;
        while (*s && *s != '/')
            *d++ = *s++;
        *d = 0;
        if (!func_00113320(card, dir))
            ok = false;
        func_003331D0(sub, D_003720D0, base);
        if (!func_00113320(card, sub))
            ok = false;
        switch (t) {
        case 0x61A1BC57:
            func_003331D0(sub, D_00372280, base);
            break;
        case 0x3BF882CC:
            func_003331D0(sub, D_00372290, base);
            break;
        case 0x26C80B0D:
            func_003331D0(sub, D_003722A0, base);
            break;
        case 0xB010F357:
            func_003331D0(sub, D_003722B0, base);
            break;
        case 0x62896EDF:
            func_003331D0(sub, D_003722C0, base);
            break;
        case 0xCA41692D:
            func_003331D0(sub, D_003722D0, base);
            break;
        case 0xFFFFFFFF:
            break;
        }
        if (!func_00113320(card, sub))
            ok = false;
        if (!func_00113110(card, base))
            ok = false;
        break;
    }
    default:
        ok = false;
        break;
    }
    if (D_00388814 != 4) {
        func_001DFF88(-1);
        func_001E0038(-1);
    }
    return ok;
}
