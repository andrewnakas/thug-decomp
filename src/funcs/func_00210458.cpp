struct Comp_00210458 {
    char m0;
    unsigned char m_type;
    short m2;
    int m4;
    union {
        int i;
        float f;
        char* s;
        char* ls;
        float* v;
        unsigned int cs;
    } m8;
};

extern Comp_00210458 D_003F5380;
extern char D_003F4F70[];
extern char D_0038F340[];
extern char D_00370320[];
extern char D_00370360[];
extern char D_0038F2C8[];
extern char D_0038F430[];
extern char D_00370388[];
extern char D_00370398[];
extern char D_0038F438[];

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, char** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_00103F28(char* fmt, ...);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" Comp_00210458* func_001E6DD0(void* params, unsigned int name);
extern "C" void func_001EAFA8(Comp_00210458* c);
extern "C" char* func_001044A8(int v, char sep);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_003331D0(char* d, const char* fmt, ...);
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_001E61F0(unsigned int cs);
extern "C" void func_001E70C0(void* s, unsigned int name, const char* v);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);

extern "C" int func_00210458(void* out_struct, void* params)
{
    char key[64];
    char buf[100];
    char f[16];
    int ret = 1;
    unsigned int name = 0;
    func_001E8398(params, 0xFF0DB407, &name, 0);
    unsigned int csname = 0;
    func_001E8398(params, 0x76FA7A8F, &csname, 0);
    char* fmt = D_0038F340;
    if (!func_001E7C80(params, 0, &fmt, 0)) {
        func_00103F28(D_00370320);
        return 0;
    }
    char* p = fmt;
    char* out = D_003F4F70;
    while (*p) {
        if (*p == '\\' && p[1] == '%') {
            p++;
            *out = *p;
            p++;
            out++;
        } else if (*p == '%') {
            p++;
            char* d = key;
            if (*p == '%') {
                p++;
                while ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || *p == '_') {
                    *d = *p;
                    p++;
                    d++;
                }
            } else {
                *d = *p;
                p++;
                d++;
            }
            *d = 0;
            Comp_00210458* c = func_001E6DD0(params, func_001F0D78(key));
            if (!c) {
                func_00103F28(D_00370360, key);
                return 0;
            }
            D_003F5380.m_type = c->m_type;
            D_003F5380.m8.i = c->m8.i;
            func_001EAFA8(&D_003F5380);
            switch (D_003F5380.m_type) {
            case 1: {
                if (func_001E8708(params, 0xF138085F)) {
                    func_00331A9C(buf, func_001044A8(D_003F5380.m8.i, ','));
                } else {
                    func_003331D0(buf, D_0038F2C8, D_003F5380.m8.i);
                }
                int len = func_00331BB8(buf);
                func_00331A9C(out, buf);
                out += len;
                break;
            }
            case 2: {
                int prec = 3;
                func_001E7DE8(params, 0xD8E2E09F, &prec, 0);
                func_003331D0(f, D_0038F430, prec);
                func_003331D0(buf, f, D_003F5380.m8.f);
                int len = func_00331BB8(buf);
                func_00331A9C(out, buf);
                out += len;
                break;
            }
            case 5: {
                float* v = D_003F5380.m8.v;
                func_003331D0(buf, D_00370388, v[1], v[2]);
                int len = func_00331BB8(buf);
                func_00331A9C(out, buf);
                out += len;
                break;
            }
            case 6: {
                float* v = D_003F5380.m8.v;
                func_003331D0(buf, D_00370398, v[1], v[2], v[3]);
                int len = func_00331BB8(buf);
                func_00331A9C(out, buf);
                out += len;
                break;
            }
            case 13: {
                ret = 2;
                func_003331D0(buf, D_0038F438, func_001E61F0(D_003F5380.m8.cs));
                int len = func_00331BB8(buf);
                func_00331A9C(out, buf);
                out += len;
                break;
            }
            case 3:
            case 4: {
                char* s;
                if (D_003F5380.m_type == 3) s = D_003F5380.m8.s;
                else s = D_003F5380.m8.ls;
                while (*s) {
                    *out = *s;
                    s++;
                    out++;
                }
                break;
            }
            }
        } else {
            *out = *p;
            p++;
            out++;
        }
    }
    *out = 0;
    if (name) func_001E70C0(out_struct, name, D_003F4F70);
    if (csname) func_001E7360(out_struct, csname, func_001F0D78(D_003F4F70));
    return ret;
}
