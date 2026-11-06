struct Hdr_001E14F0 {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x20];
};

struct Data_001E14F0 {
    char pad[0x20];
    unsigned short m20;
};

struct Out_001E14F0 {
    int m_addr;
    int m_flag;
};

extern char D_00364448[];
extern char D_00364460[];
extern char D_0038E1F0[];
extern unsigned char D_003F2B90[];
extern int D_0038E1E4;
extern int D_003940E0;
extern int D_0038E1E0;
extern int D_0038E27C;
extern void* D_00388A70;

extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void* func_00110E38(const char* name, const char* mode);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" int func_001110F8(void* f, int off, int whence);
extern "C" int func_00110F68(void* buf, int size, int n, void* f);
extern "C" int func_00110EF8(void* f);
extern "C" int func_001E17D8(int v);
extern "C" float func_001E17A0(Hdr_001E14F0* h);
extern "C" char* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_0031BF20(int a);
extern "C" int func_0031AE78(void* src, int dst, int size, int mode);
extern "C" void func_001E23E0(int a, int b, int c, int d, int e);

bool Call_001E14F0(Out_001E14F0* out, char* name, int flag, float* rate)
{
    Hdr_001E14F0 hdr;
    char buf[0x100];
    func_003331D0(buf, D_00364448, name);
    void* f = func_00110E38(buf, D_0038E1F0);
    if (!f) {
        func_00103F28(D_00364460, name);
        return false;
    }
    func_001110F8(f, 0, 0);
    func_00110F68(&hdr, 1, 0x30, f);
    int size = func_001E17D8(hdr.mC);
    char* mem = func_0010A638(D_00388A70, size + 0x80, 1, 0);
    func_001110F8(f, 0x30, 0);
    Data_001E14F0* data = (Data_001E14F0*)(((int)mem + 0x3F) & -0x40);
    func_00110F68(data, 1, size, f);
    func_00110EF8(f);
    if (rate)
        *rate = func_001E17A0(&hdr);
    int addr;
    int i;
    if (flag) {
        int pad = 0;
        if (!D_0038E1E4)
            D_003940E0 = 0;
        int top = D_0038E1E4 + size;
        D_0038E1E4 = top;
        int d = (0x1F51DF - top) & 0xF;
        if (d)
            D_0038E1E4 = top + d;
        addr = 0x1F51DF - D_0038E1E4;
        int prev = D_003940E0;
        if (prev) {
            int r = size & 0x3F;
            if (r) {
                pad = 0x40 - r;
                int over = prev - (addr + size);
                int n = pad - over;
                for (i = 0; i < n; i++)
                    ((char*)data)[size + over + i] = D_003F2B90[i];
            }
            size += pad;
        }
        for (i = 0; i < 0x40; i++)
            D_003F2B90[i] = ((char*)data)[i];
        D_003940E0 = addr;
    } else {
        int base = 0x2D190;
        int cur0 = D_0038E1E0;
        int r = cur0 & 0xF;
        if (r)
            D_0038E1E0 = cur0 + (0x10 - r);
        int cur = D_0038E1E0;
        D_0038E1E0 = cur + size;
        addr = cur + base;
    }
    func_0031BF20(0);
    int dst = D_0038E27C;
    if (!dst)
        return false;
    if (func_0031AE78(data, dst, size, 1) == -1)
        return false;
    func_001E23E0(0, 0, dst, addr, size);
    out->m_addr = addr;
    out->m_flag = (data->m20 >> 9) & 1;
    func_0010A8D8(D_00388A70, mem);
    return true;
}
