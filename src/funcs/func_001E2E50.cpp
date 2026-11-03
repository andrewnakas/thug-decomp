extern unsigned int D_0038E280;
extern int D_0038881C;
extern char D_00364578[];
extern char D_003645B8[];
extern char D_0038E2A0[];
extern char D_0038E2A8[];

struct Wad_001E2E50 {
    char m_name[0x100];
    int m_handle;
    int pad;
};

extern Wad_001E2E50 D_003F2BD0[2];

struct Info_001E2E50 {
    union {
        const char* m_name;
        unsigned int m_offset;
    };
    int m_size;
};

struct Stream_001E2E50 {
    int m_channel;
    int m_4;
    int m_8;
    int m_file;
    int m_10;
    int m_14;
};

extern "C" void func_0010FE68();
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" int func_00111E68(int handle, int a, int size);
extern "C" int func_0010EC78(const char* name, int a, int size);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" void func_0010E500(int file, int a);
extern "C" void func_0010E748(int file, unsigned long offset, int whence);
extern "C" void func_001E2C10(Stream_001E2E50* s, int a);

bool func_001E2E50(Stream_001E2E50* s, Info_001E2E50* info, bool loop)
{
    char buf[0x100];
    func_0010FE68();
    if (D_0038E280 & ((1 << s->m_channel) | (0x10 << s->m_channel)))
        func_00103F28(D_00364578, s->m_channel, D_0038E280);
    Wad_001E2E50* wad;
    int handle;
    int size;
    if (s->m_channel == 0) {
        Wad_001E2E50* w = D_003F2BD0;
        size = 0x50;
        handle = w[1].m_handle;
        wad = w + 1;
    } else {
        Wad_001E2E50* w = D_003F2BD0;
        size = 0x5A;
        handle = w[0].m_handle;
        wad = w;
    }
    if (s->m_file)
        return false;
    if (D_0038881C) {
        s->m_file = func_00111E68(handle, 0, size);
    } else {
        if (info->m_size < 0) {
            func_00331A9C(buf, info->m_name);
            if (s->m_channel == 0)
                func_00331678(buf, D_0038E2A0);
            else
                func_00331678(buf, D_0038E2A8);
            s->m_file = func_0010EC78(buf + 1, 0, size);
        } else {
            s->m_file = func_0010EC78(wad->m_name, 0, size);
        }
    }
    if (!s->m_file) {
        func_00103F28(D_003645B8, wad->m_name);
        return false;
    }
    s->m_14 = 0;
    func_0010E500(s->m_file, 1);
    if (info->m_size < 0) {
        if (s->m_channel != 0)
            func_0010E748(s->m_file, 0x30, 0);
    } else {
        func_0010E748(s->m_file, info->m_offset, 0);
    }
    s->m_10 = info->m_size & 0x7FFFFFFF;
    s->m_4 = 1;
    s->m_8 = loop ? 3 : 1;
    func_001E2C10(s, 0);
    D_0038E280 |= 0x10000 << s->m_channel;
    return true;
}
