struct Stream_00111B18 {
    char pad0[0x14];
    unsigned char m_14;
    char pad15[0x1C - 0x15];
    int m_1C;
    int m_20;
    int m_24;
    volatile int m_28;
    volatile int m_2C;
    char pad30[0x34 - 0x30];
    volatile int m_34;
    char pad38[0x3C - 0x38];
    volatile int m_3C;
    int NextId() { return ++m_34; }
};

struct Request_00111B18 {
    char pad0[0x10];
    int m_10;
    int m_14;
    union {
        struct {
            int m_sector;
            int m_size;
        } f;
        char m_name[0x50];
    } u;
    short m_68;
    char m_6A;
    char m_6B;
    int m_6C;
};

struct Entry_00111B18 {
    unsigned int m_0;
    unsigned int m_4;
};

extern int D_0038881C;
extern int D_00388E24;
extern int D_00388E14;
extern volatile int D_00388C90;
extern int D_00388E68[];

extern "C" Entry_00111B18* func_00112618(const char* name, int dir);
extern "C" char* func_003317AC(const char* s, int c);
extern "C" char* func_00332088(char* dst, const char* src, int n);
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_00112238(Request_00111B18* req, Stream_00111B18* s, int wait, int id);
extern "C" int func_0010E4B0(Stream_00111B18* s);

extern "C" int func_00111B18(Stream_00111B18* s, const char* name)
{
    Request_00111B18 req;
    req.m_6C = 1;
    s->m_2C = 0;
    const char* rest = 0;
    if (D_0038881C) {
        if (!D_00388E24) {
            return 0;
        }
        Entry_00111B18* e = func_00112618(name, D_00388E24);
        if (!e) {
            return 0;
        }
        s->m_28 = e->m_4 & 0x7FFFFFFF;
        req.u.f.m_sector = D_00388E14 + (e->m_0 >> 11);
        req.u.f.m_size = s->m_28;
        req.m_6A = 0;
    } else {
        unsigned int len = 0x4F;
        if (func_003317AC(name, ':')) {
            func_00332088(req.u.m_name, name, 0x4F);
        } else {
            len = 0x4A;
            *(int*)req.u.m_name = D_00388E68[0];
            *(unsigned short*)(req.u.m_name + 4) = *(unsigned short*)&D_00388E68[1];
            func_00332088(req.u.m_name + 5, name, 0x4A);
        }
        if (len < (unsigned int)func_00331BB8(name)) {
            rest = name + len;
            req.m_6A = 2;
        } else {
            req.m_6A = 1;
        }
    }
    req.m_6B = s->m_14;
    req.m_10 = s->m_20;
    req.m_14 = s->m_24;
    D_00388C90++;
    s->NextId();
    req.m_68 = 0;
    int r = func_00112238(&req, s, 1, -1);
    if (rest) {
        func_00331A9C(req.u.m_name, rest);
        req.m_6C = 7;
        func_00112238(&req, s, 1, r);
    }
    if (s->m_1C) {
        return func_0010E4B0(s) >= 0;
    }
    s->m_3C = r | 0x80000000;
    return 1;
}
