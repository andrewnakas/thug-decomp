extern char D_00390080[];
extern char D_00390088[];
extern char D_00390090[];
extern char D_00390098[];
extern char D_003900A0[];
extern char D_003900A8[];
extern char D_003900B0[];
extern char D_00373C00[];
extern char D_00373C10[];
extern char D_00373C20[];
extern void* D_0038FC78;

class Obj_00248AA0;

extern "C" void* func_00249FE0(Obj_00248AA0* self);
extern "C" const char* func_00248950(Obj_00248AA0* self);
extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void* func_00240850();
extern "C" int func_00240120(void* p, int a);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" char* func_0022E368(void* self, int index);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" int func_00331BB8(const char* s);
extern "C" bool func_001E11A8(unsigned int key);

static inline void Up_00248AA0(char* s, int flag)
{
    if (flag)
        func_003331D0(s, D_00373C00, s);
}

class Obj_00248AA0 {
public:
    int Find(unsigned int* out, int index, int flag, const char* name, int noindex);
};

int Obj_00248AA0::Find(unsigned int* out, int index, int flag, const char* name, int noindex)
{
    void* params = func_00249FE0(this);
    const char* base = func_00248950(this);
    if (!base)
        return 0;
    char b0[0x100];
    char b1[0x100];
    char b2[0x100];
    char b3[0x100];
    char b4[0x100];
    char b5[0x100];
    char b6[0x100];
    char b7[0x100];
    const char* names[8];
    char tmp[0x100];
    const char* str;
    func_001E8870(params, 0xBFECC45B, &str, 1);
    func_003331D0(b0, D_00390080, base, str);
    const char* suffix;
    switch (func_00240120(func_00240850(), 0)) {
    case 0:
        suffix = D_00390088;
        break;
    case 1:
        suffix = D_00390090;
        break;
    case 2:
        suffix = D_00390098;
        break;
    default:
        return 0;
    }
    int alt = 0;
    if (name && func_001F0D78(name) == 0x5B8AB877) {
        int v;
        func_001E7DE8(func_0022E368(D_0038FC78, 0) + 0x5C, 0x3F813177, &v, 1);
        alt = v == 0;
    }
    func_003331D0(b1, D_00390080, b0, suffix);
    b2[0] = D_003900A0[0];
    b3[0] = D_003900A0[0];
    b4[0] = D_003900A0[0];
    b5[0] = D_003900A0[0];
    if (index >= 0 && !noindex) {
        func_003331D0(b2, D_00373C10, b1, index);
        Up_00248AA0(b2, flag);
        func_003331D0(b3, D_00373C10, b0, index);
        Up_00248AA0(b3, flag);
        if (name) {
            func_003331D0(b4, D_00373C20, b0, index, name);
            if (alt)
                func_003331D0(b4, D_003900A8, b4);
            Up_00248AA0(b4, flag);
            func_003331D0(b5, D_00373C20, b1, index, name);
            if (alt)
                func_003331D0(b5, D_003900A8, b5);
            Up_00248AA0(b5, flag);
        }
    }
    b6[0] = D_003900A0[0];
    b7[0] = D_003900A0[0];
    if (name) {
        func_003331D0(b6, D_00390080, b1, name);
        if (alt)
            func_003331D0(b6, D_003900A8, b6);
        Up_00248AA0(b6, flag);
        func_003331D0(b7, D_00390080, b0, name);
        if (alt)
            func_003331D0(b7, D_003900A8, b7);
        Up_00248AA0(b7, flag);
    }
    Up_00248AA0(b1, flag);
    Up_00248AA0(b0, flag);
    names[0] = b0;
    names[1] = b1;
    names[2] = b7;
    names[3] = b6;
    names[4] = b2;
    names[5] = b3;
    names[6] = b4;
    names[7] = b5;
    int i = 0;
    unsigned int found = 0;
    int pref = 0;
    if (index >= 0)
        i += 4;
    for (; i < 8; i++) {
        if (func_00331BB8(names[i])) {
            func_003331D0(tmp, D_003900B0, names[i]);
            unsigned int k = func_001F0D78(tmp);
            if (func_001E11A8(k)) {
                found = k;
                pref = 1;
                break;
            }
            k = func_001F0D78(names[i]);
            if (func_001E11A8(k)) {
                found = k;
                break;
            }
        }
    }
    *out = found;
    return pref;
}
