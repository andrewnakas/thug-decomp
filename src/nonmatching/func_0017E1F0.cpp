/* fuzzy: 84.9 */
struct Tex_0017E1F0 {
    int m0;
    int m_flags;
    void* m8;
    int mC;
    unsigned char* m10;
    unsigned char* m14;
    unsigned int m18;
    unsigned int m1C;
    int m20;
    int m24;
    unsigned long m28;
    unsigned long m30;
    unsigned int* m38;
    unsigned int* m3C;
    int m40;
    unsigned short m44;
    unsigned short m46;
    unsigned short m48;
    unsigned short m4A;

    int Debug() { return (m_flags >> 1) & 1; }
    int Upload(unsigned char* data, int logw, int logh, unsigned int psm, int cpsm, int nmips, int swizzled);
};

extern unsigned int* D_00394274;
extern unsigned int* D_00394278;
extern unsigned int D_00393F58;
extern unsigned int D_00393F5C;
extern unsigned int D_0038BDBC;
extern char D_003E2798[];
extern char D_003610C0[];
extern char D_003610E0[];
extern char D_00361108[];

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_00334148(int code) __attribute__((noreturn));
extern "C" void func_001657F0(void* obj, int* w, int* h, int psm);
extern "C" unsigned short func_00165890(void* obj, int w, int h, int psm);
extern "C" void* func_0010BDE0(int size);
extern "C" int func_001E5648(const char* name, int v);
extern "C" void func_001644E8(unsigned int regs, unsigned int nreg, unsigned int flg, unsigned int prim,
                             unsigned int pre, unsigned int eop, unsigned int nloop);
extern "C" void func_001647B0(unsigned int reg, unsigned long data);
extern "C" unsigned int* func_00164808(unsigned int reg, unsigned long data);

static inline void Tag(unsigned int v, void* a)
{
    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = v;
    p[1] = (unsigned int)a;
    D_00394274 = p + 2;
}

static inline void Put(unsigned int v)
{
    unsigned int* p = D_00394274;
    *p = v;
    D_00394274 = p + 1;
}

static inline void Direct(unsigned short n)
{
    Put(0x50000000 | n);
}

static inline void EndTag()
{
    int kind = (*D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *D_00394274 = 0;
        D_00394274++;
    }
    if (kind != 3 && kind != 0 && kind != 4) {
        *(unsigned short*)D_00394278 = ((char*)D_00394274 - (char*)D_00394278 - 8) >> 4;
    }
}

int Tex_0017E1F0::Upload(unsigned char* data, int logw, int logh, unsigned int psm, int cpsm, int nmips, int swizzled)
{
    unsigned int size, qwc, cbsize;
    unsigned int bpp, cbpp, ncolors;
    unsigned int vram;
    unsigned int* saved = D_00394274;
    if (Debug()) {
        vram = D_00393F5C;
    } else {
        vram = D_00393F58;
    }
    switch (psm) {
    case 0:
        bpp = 32;
        ncolors = 0;
        break;
    case 1:
        bpp = 24;
        ncolors = 0;
        break;
    case 2:
        bpp = 16;
        ncolors = 0;
        break;
    case 0x13:
        bpp = 8;
        ncolors = 0x100;
        break;
    case 0x14:
        bpp = 4;
        ncolors = 0x10;
        break;
    default:
        func_00103F28(D_003610C0, psm);
        func_00334148(1);
        break;
    }
    int pal = bpp < 16;
    if (pal) {
        switch (cpsm) {
        case 0:
            cbpp = 32;
            break;
        case 2:
            cbpp = 16;
            break;
        default:
            func_00103F28(D_003610E0, psm);
            func_00334148(1);
            break;
        }
    } else {
        cbpp = 0;
    }
    if (!swizzled && psm == 0x13) {
        for (int i = 0; i < 0x100; i += 0x20) {
            for (int j = 0; j < 8; j++) {
                if (cpsm == 0) {
                    unsigned int* p = (unsigned int*)data;
                    unsigned int t = p[i + j + 8];
                    p[i + j + 8] = p[i + j + 16];
                    p[i + j + 16] = t;
                } else {
                    unsigned short* p = (unsigned short*)data;
                    unsigned short t = p[i + j + 8];
                    p[i + j + 8] = p[i + j + 16];
                    p[i + j + 16] = t;
                }
            }
        }
    }
    unsigned int w = 1 << logw;
    unsigned int h = 1 << logh;
    unsigned int tbw = (w + 0x3F) >> 6;
    if (pal) {
        if (tbw < 2) {
            tbw = 2;
        }
    }
    int bw = w;
    int bh = h;
    func_001657F0(D_003E2798, &bw, &bh, psm);
    m44 = func_00165890(D_003E2798, bw, bh, psm);
    unsigned int cbytes = ncolors * cbpp;
    m20 = 0x110;
    unsigned int cqwc = cbytes >> 7;
    cbsize = cbytes >> 3;
    unsigned int bits = w * h * bpp;
    qwc = bits >> 7;
    size = bits >> 3;
    m8 = func_0010BDE0(0x110);
    D_00394274 = (unsigned int*)m8;
    m48 = vram;
    vram = m48 + m44;
    m4A = vram;
    if (!pal) {
        m46 = 0;
    } else if (bpp == 4) {
        m46 = bpp;
    } else {
        m46 = 4;
    }
    vram += m46;
    if (Debug()) {
        func_001E5648(D_00361108, 0);
    }
    if (Debug() && D_00393F58 + D_0038BDBC < vram) {
        D_00394274 = saved;
        return 0;
    }
    if (pal) {
        Tag(0x10000000, 0);
        Put(0);
        Put(0x50000006);
        func_001644E8(0xE, 1, 0, 0, 0, 0, 4);
        m3C = func_00164808(0x50, ((unsigned long)(m4A & 0x3FFF) << 32) | (1L << 48) | ((unsigned long)(cpsm & 0x3F) << 56));
        func_001647B0(0x51, 0);
        if (psm == 0x14) {
            func_001647B0(0x52, 8 | (2L << 32));
        } else {
            func_001647B0(0x52, 16 | (16L << 32));
        }
        func_001647B0(0x53, 0);
        func_001644E8(0, 0, 2, 0, 0, 0, cqwc);
        EndTag();
        Tag(0x30000000 | cqwc, data);
        Put(0);
        Direct(cqwc);
        m14 = data;
        data = (unsigned char*)(((unsigned int)(data + cbsize) + 0xF) & ~0xF);
        m1C = cbsize;
    }
    Tag(0x10000000, 0);
    Put(0);
    Put(0x50000006);
    func_001644E8(0xE, 1, 0, 0, 0, 0, 4);
    m38 = func_00164808(0x50, ((unsigned long)(m48 & 0x3FFF) << 32) | ((unsigned long)(tbw & 0x3F) << 48) | ((unsigned long)(psm & 0x3F) << 56));
    func_001647B0(0x51, 0);
    func_001647B0(0x52, (w & 0xFFF) | ((unsigned long)(h & 0xFFF) << 32));
    func_001647B0(0x53, 0);
    func_001644E8(0, 0, 2, 0, 0, 0, qwc);
    EndTag();
    Tag(0x30000000 | qwc, data);
    Put(0);
    Direct(qwc);
    if (!(m_flags & 8) && nmips != 0) {
        for (int i = 1; i < nmips; i++) {
            size += ((1 << logw) >> i) * ((1 << logh) >> i) * bpp >> 3;
        }
    }
    m10 = data;
    m28 = (m48 & 0x3FFF) | ((unsigned long)(tbw & 0x3F) << 14) | ((unsigned long)(psm & 0x3F) << 20) |
          ((unsigned long)(logw & 0xF) << 26) | ((unsigned long)(logh & 0xF) << 30) | (1L << 34) |
          ((unsigned long)(m4A & 0x3FFF) << 37) | ((unsigned long)(cpsm & 0xF) << 51) | (1L << 61);
    m18 = size;
    m30 = 0x61;
    if (Debug()) {
        D_00393F5C = vram;
    }
    Tag(0x60000000, 0);
    Put(0);
    Put(0);
    D_00394274 = saved;
    return 1;
}
