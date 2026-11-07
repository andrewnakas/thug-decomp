/* fuzzy: 66.6 */
/* Texture dictionary loader: reads a texture file image from the D_00394320 stream (format version in
   D_00394324), inserts the dictionary into the priority-sorted list D_003942F4/D_003942F8, then for every texture
   computes the GS memory layout of its mip levels (VRAM double-buffered through D_00394304), swizzles 8/4-bit
   images where possible and builds the DMA upload packet (BITBLTBUF/TRXPOS/TRXREG/TRXDIR + IMAGE REF tags) plus
   the TEX0/MIPTBP1/MIPTBP2 register values. */
extern char D_003612F0[]; /* "non-texture at number %d\n" */
extern char D_00361310[]; /* "Unknown PSM %d at index %d in texture file\n" */
extern char D_00361340[]; /* "Unknown CPSM %d in texture file\n" */
extern char D_00361368[];
extern char D_003E2798[];

struct Heap_001804E8 {
    char pad[0xD8];
    int mD8;
};

struct Tex_001804E8 {
    unsigned int m_name;       /* 0x00 */
    int m_group;               /* 0x04 */
    int m_levels;              /* 0x08 */
    int mC;
    unsigned long m_tex0;      /* 0x10 */
    unsigned long m_miptbp1;   /* 0x18 */
    unsigned long m_miptbp2;   /* 0x20 */
    unsigned char* m_data;     /* 0x28 */
    int m_dataSize;            /* 0x2C */
    unsigned char* m_clut;     /* 0x30 */
    int m_clutSize;            /* 0x34 */
    unsigned int m_flags;      /* 0x38 */
    unsigned char* m_packet;   /* 0x3C */
    int m40;
    int m_qwc;                 /* 0x44 */
};

struct Sector_001804E8 {
    char pad0[0x18];
    int m_count;               /* 0x18 */
    char pad1C[0x8];
    Tex_001804E8* m_textures;  /* 0x24 */
};

struct Dict_001804E8 {
    Dict_001804E8* m_next;     /* 0x00 */
    float m_priority;          /* 0x04 */
    int m_group;               /* 0x08 */
    int m_type;                /* 0x0C */
    unsigned char* m10;
    unsigned char* m14;
    char pad18[0x30 - 0x18];
    int m30;
    int m34;
    char pad38[0x40 - 0x38];
    int m_vram0;               /* 0x40 */
    int m_vram1;               /* 0x44 */
    Sector_001804E8* m_sector; /* 0x48 */
    Dict_001804E8* m_prev;     /* 0x4C */
    int pad50;
    int m54;
};

extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int* D_00394320;
extern unsigned int D_00394324;
extern int D_00394304;
extern int D_0038C178;
extern Dict_001804E8* D_003942F4;
extern Dict_001804E8* D_003942F8;
extern Heap_001804E8* D_00388A70;

extern "C" void func_00103F28(const char* fmt, ...);
extern "C" void func_00334148(int code);
extern "C" Tex_001804E8* func_001819E8(unsigned int name);
extern "C" void func_001644E8(int regs, int nreg, int flg, int prim, int pre, int eop, int nloop);
extern "C" void func_001647B0(int reg, unsigned long v);
extern "C" void func_0010A950(void* heap, int v);
extern "C" void func_0010A9B0(void* heap);
extern "C" unsigned char* func_0010BDE0(unsigned int size);
extern "C" void func_0010BEB8(void* p);
extern "C" void* func_00331404(void* dst, const void* src, unsigned int n);
extern "C" int func_00166958(void* ctx, int w, int h);
extern "C" int func_001669B8(void* ctx, int w, int h, unsigned char* src, unsigned char* dst);
extern "C" int func_001665E8(void* ctx, int w, int h);
extern "C" int func_00166648(void* ctx, int w, int h, unsigned char* src, unsigned char* dst);
extern "C" int func_00166CB8(void* ctx, int w, int h);
extern "C" int func_00166D18(void* ctx, int w, int h, unsigned char* src, unsigned char* dst);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void Tag(unsigned int v, unsigned int a)
{
    unsigned int* p = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)p;
    p[0] = v;
    p[1] = a;
    D_00394274 = (unsigned char*)(p + 2);
}

static inline void Close()
{
    int kind = (*(unsigned int*)D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (kind != 3 && kind != 0 && kind != 4) {
        *(unsigned short*)D_00394278 = ((D_00394274 - D_00394278) - 8) >> 4;
    }
}

static inline unsigned int Read()
{
    return *D_00394320++;
}

static inline unsigned int* Align16(unsigned int* p)
{
    return (unsigned int*)(((int)p + 15) & -16);
}

extern "C" void func_001804E8(void* self, Sector_001804E8* sector, Dict_001804E8* dict, int front, int overlay,
                              int keep, int groupBase)
{
    unsigned int addr[8];    /* GS block address of each level (256-byte units) */
    unsigned int bw[8];      /* buffer width of each level (64-pixel units) */
    unsigned int width[8];
    unsigned int height[8];
    unsigned int bytes[8];   /* image size of each level */
    unsigned int qwc[8];
    unsigned int vbytes[8];  /* size of each level in GS memory */
    unsigned int vwidth[8];
    unsigned int vheight[8];

    dict->m54 = 0xC000;
    Tex_001804E8* src = 0;
    int parity = 0;
    dict->m_sector = sector;
    if (overlay)
        dict->m54 = 0x808000;
    if (front) {
        dict->m54 = 0x80;
        if (overlay)
            dict->m54 = 0x800080;
    }

    unsigned char* p = D_00394274;
    unsigned char* end = (unsigned char*)(((int)p + 15) & -16);
    dict->m30 = 0;
    dict->m34 = 0;
    while (p < end) {
        *p++ = 0;
        D_00394274 = p;
    }
    dict->m14 = D_00394274;
    dict->m10 = D_00394274;

    dict->m_group = Read() + groupBase;
    if (D_00394324 >= 2)
        dict->m_type = Read();
    else if ((unsigned int)(dict->m_group - 1000) < 1000)
        dict->m_type = 2;
    else
        dict->m_type = 0;

    if (D_00394324 >= 4) {
        dict->m_priority = *(float*)D_00394320;
        D_00394320++;
    } else {
        if (keep) {
            switch (dict->m_type & 3) {
            case 0:
                dict->m_priority = 0.0f;
                break;
            case 2:
                dict->m_priority = -100.0f;
                break;
            case 1:
                dict->m_priority = 7500.0f;
                break;
            case 3:
                dict->m_priority = -99.0f;
                break;
            }
        }
        if (front)
            dict->m_priority = (float)(D_0038C178 + 5000);
        if (overlay)
            dict->m_priority = (float)(D_0038C178 + 2500);
    }

    /* insert into the list sorted by priority */
    Dict_001804E8* head = D_003942F4;
    if (!head || dict->m_priority < head->m_priority) {
        dict->m_next = head;
        dict->m_prev = 0;
        D_003942F4 = dict;
        if (head)
            head->m_prev = dict;
        else
            D_003942F8 = dict;
    } else if (D_003942F8->m_priority <= dict->m_priority) {
        dict->m_prev = D_003942F8;
        dict->m_next = 0;
        D_003942F8->m_next = dict;
        D_003942F8 = dict;
    } else {
        Dict_001804E8* n;
        for (n = head; n; n = n->m_next) {
            if (dict->m_priority < n->m_priority)
                break;
        }
        dict->m_next = n;
        dict->m_prev = n->m_prev;
        n->m_prev->m_next = dict;
        n->m_prev = dict;
    }

    int count = Read();
    unsigned int next = D_00394304;
    unsigned int limit = D_00394304 + 0xA20;
    dict->m_vram0 = D_00394304;
    dict->m_vram1 = D_00394304 + 0xA20;
    D_00394304 ^= 0x1E20;
    Tex_001804E8* t = &sector->m_textures[sector->m_count];

    for (int index = 0; index < count; index++, t++) {
        if (D_00394324 >= 5)
            t->m_flags = Read();
        t->m_name = Read();
        t->m_group = dict->m_group;
        int logW = Read();
        int logH = Read();
        int psm = Read();
        int cpsm = Read();
        int levels = Read();
        t->m_data = 0;
        t->m_clut = 0;
        t->m_dataSize = 0;
        t->m_clutSize = 0;
        if ((unsigned int)logW == 0xFFFFFFFF) {
            func_00103F28(D_003612F0, index);
            continue;
        }
        if (levels < 0) {
            src = func_001819E8(t->m_name);
            levels &= 0x7FFFFFFF;
            t->m_flags &= ~1;
        } else {
            t->m_flags |= 1;
        }
        if (t->m_flags & 1)
            D_00394320 = Align16(D_00394320);

        int bpp;
        unsigned int colors;
        if (psm == 0) {
            bpp = 32;
            colors = 0;
        } else if (psm == 1) {
            bpp = 24;
            colors = 0;
        } else if (psm == 2) {
            bpp = 16;
            colors = 0;
        } else if (psm == 0x13) {
            bpp = 8;
            colors = 256;
        } else if (psm == 0x14) {
            bpp = 4;
            colors = 16;
        } else {
            func_00103F28(D_00361310, psm, index);
            func_00334148(1);
        }
        int vbpp = bpp == 24 ? 32 : bpp;
        int clutBits;
        if (bpp < 16) {
            if (cpsm == 0) {
                clutBits = 32;
            } else if (cpsm == 2) {
                clutBits = 16;
            } else {
                func_00103F28(D_00361340, psm);
                func_00334148(1);
                clutBits = 0;
            }
        } else {
            clutBits = 0;
        }

        /* CSM1 palette order: swap the middle two blocks of every 32 entries */
        if (psm == 0x13 && (t->m_flags & 1)) {
            for (int base = 0; base < 256; base += 32) {
                for (int k = 0; k < 8; k++) {
                    if (cpsm == 0) {
                        unsigned int* c = D_00394320 + base + k;
                        unsigned int tmp = c[8];
                        c[8] = c[16];
                        c[16] = tmp;
                    } else {
                        unsigned short* c = (unsigned short*)D_00394320 + base + k;
                        unsigned short tmp = c[8];
                        c[8] = c[16];
                        c[16] = tmp;
                    }
                }
            }
        }

        int i;
        for (i = 0; i <= levels; i++) {
            unsigned int w = (1 << logW) >> i;
            unsigned int h = (1 << logH) >> i;
            height[i] = h;
            width[i] = w;
            bw[i] = (w + 63) >> 6;
            if (bpp < 16 && bw[i] < 2)
                bw[i] = 2;
        }

        unsigned int pageW;
        unsigned int pageH;
        if (psm == 0 || psm == 1) {
            pageW = 64;
            pageH = 32;
        } else if (psm == 2) {
            pageW = 64;
            pageH = 64;
        } else if (psm == 0x13) {
            pageW = 128;
            pageH = 64;
        } else if (psm == 0x14) {
            pageW = 128;
            pageH = 128;
        } else {
            func_00103F28(D_00361310, psm, index);
            func_00334148(1);
        }

        for (i = 0; i <= levels; i++) {
            vwidth[i] = width[i];
            vheight[i] = height[i];
            if (width[i] < pageW && pageH < height[i])
                vwidth[i] = pageW;
            if (pageW < vwidth[i] && vheight[i] < pageH)
                vheight[i] = pageH;
            if (vwidth[i] < bw[i] << 6)
                vwidth[i] = bw[i] << 6;
        }

        unsigned int clutBytes = colors * clutBits;
        unsigned int clutQwc = clutBytes >> 7;
        clutBytes >>= 3;
        for (i = 0; i <= levels; i++) {
            bytes[i] = (width[i] * height[i] * bpp) >> 3;
            vbytes[i] = (vwidth[i] * vheight[i] * vbpp) >> 3;
            qwc[i] = (bytes[i] + 15) >> 4;
        }

        addr[0] = next;
        for (i = 1; i <= levels; i++)
            addr[i] = (((addr[i - 1] << 8) + vbytes[i - 1] + 0x1FFF) & ~0x1FFF) >> 8;

        /* the palette sits at the top of the dictionary's VRAM area */
        unsigned int cbp;
        if (bpp < 16) {
            cbp = limit - 1;
            if (bpp != 4) {
                cbp = limit - 2;
                if (cpsm == 0)
                    cbp = limit - 4;
            }
        } else {
            cbp = limit;
        }

        next = (((addr[levels] << 8) + vbytes[levels] + 0x1FFF) & ~0x1FFF) >> 8;
        if (cbp < next) {
            func_00103F28(D_00361368, index);
            if (t->m_flags & 1) {
                D_00394320 = (unsigned int*)((unsigned char*)D_00394320 + clutBytes);
                for (i = 0; i <= levels; i++)
                    D_00394320 = Align16((unsigned int*)((unsigned char*)D_00394320 + bytes[i]));
            }
            continue;
        }

        unsigned int cbp14 = cbp & 0x3FFF;
        unsigned int lowBpp = bpp < 9;
        unsigned int psm6 = psm & 0x3F;
        unsigned int tw = logW & 0xF;
        unsigned int th = logH & 0xF;
        unsigned int cpsm4 = cpsm & 0xF;
        unsigned char* data;

        if (bpp < 16) {
            if (t->m_flags & 1)
                data = (unsigned char*)D_00394320;
            else
                data = src->m_clut;
            t->m_clut = data;
            t->m_clutSize = clutBytes;
            Tag(0x10000000, 0);
            Put(0);
            Put(0);
            func_001644E8(0xE, 1, 0, 0, 0, 0, 4);
            func_001647B0(0x50, (unsigned long)(cbp & 0x3FFF) << 32 | (unsigned long)1 << 48 |
                                    (unsigned long)(cpsm & 0x3F) << 56);
            func_001647B0(0x51, 0);
            if (psm == 0x14)
                func_001647B0(0x52, (unsigned long)2 << 32 | 8);
            else
                func_001647B0(0x52, (unsigned long)16 << 32 | 16);
            func_001647B0(0x53, 0);
            func_001644E8(0, 0, 2, 0, 0, 0, clutQwc);
            Close();
            Tag(clutQwc | 0x30000000, (unsigned int)data);
            Put(0);
            Put(0);
        }

        if (t->m_flags & 1) {
            D_00394320 = Align16((unsigned int*)((unsigned char*)D_00394320 + clutBytes));
            t->m_data = (unsigned char*)D_00394320;
        } else {
            t->m_data = src->m_data;
        }
        data = t->m_data;

        /* alternate small levels between the two halves of a page */
        for (i = 0; i <= levels; i++) {
            if (parity & 1) {
                if ((bpp == 32 || bpp == 8) && !(pageW >> 1 < width[i]) && !(pageH < height[i]))
                    addr[i] += 0x10;
                else if ((bpp == 16 || bpp == 4) && !(pageW < width[i]) && !(pageH >> 1 < height[i]))
                    addr[i] += 0x10;
            }
            parity++;
        }

        for (i = 0; i <= levels; i++) {
            int lbw = bw[i];
            int w = width[i];
            int lpsm = psm;
            int h = height[i];
            if (lowBpp) {
                if (lpsm == 0x13) {
                    if (func_00166958(D_003E2798, w, h)) {
                        if (t->m_flags & 1) {
                            func_0010A950(D_00388A70, D_00388A70->mD8);
                            unsigned char* tmp = func_0010BDE0(width[i] * height[i]);
                            func_0010A9B0(D_00388A70);
                            func_001669B8(D_003E2798, width[i], height[i], data, tmp);
                            func_00331404(data, tmp, width[i] * height[i]);
                            func_0010BEB8(tmp);
                        }
                        w = w / 2;
                        lbw = w / 64;
                        h = h / 2;
                        t->m_flags |= 0x2000000 << i;
                        if (!lbw)
                            lbw = 1;
                        lpsm = 0;
                    }
                } else if (lpsm == 0x14) {
                    if (func_001665E8(D_003E2798, w, h)) {
                        if (t->m_flags & 1) {
                            func_0010A950(D_00388A70, D_00388A70->mD8);
                            unsigned char* tmp = func_0010BDE0((width[i] * height[i]) >> 1);
                            func_0010A9B0(D_00388A70);
                            func_00166648(D_003E2798, width[i], height[i], data, tmp);
                            func_00331404(data, tmp, (width[i] * height[i]) >> 1);
                            func_0010BEB8(tmp);
                        }
                        w = w / 2;
                        lbw = w / 64;
                        h = h / 4;
                        t->m_flags |= 0x2000000 << i;
                        if (!lbw)
                            lbw = 1;
                        lpsm = 0;
                    } else if (func_00166CB8(D_003E2798, width[i], height[i])) {
                        if (t->m_flags & 1) {
                            func_0010A950(D_00388A70, D_00388A70->mD8);
                            unsigned char* tmp = func_0010BDE0((width[i] * height[i]) >> 1);
                            func_0010A9B0(D_00388A70);
                            func_00166D18(D_003E2798, width[i], height[i], data, tmp);
                            func_00331404(data, tmp, (width[i] * height[i]) >> 1);
                            func_0010BEB8(tmp);
                        }
                        w = w / 2;
                        t->m_flags |= 0x40000 << i;
                        h = h / 2;
                        lbw = w / 64;
                        if (!lbw)
                            lbw = 1;
                        lpsm = 2;
                    }
                }
            }
            Tag(0x10000000, 0);
            Put(0);
            Put(0);
            func_001644E8(0xE, 1, 0, 0, 0, 0, 4);
            func_001647B0(0x50, (unsigned long)(addr[i] & 0x3FFF) << 32 | (unsigned long)(lbw & 0x3F) << 48 |
                                    (unsigned long)(lpsm & 0x3F) << 56);
            func_001647B0(0x51, 0);
            func_001647B0(0x52, (w & 0xFFF) | (unsigned long)(h & 0xFFF) << 32);
            func_001647B0(0x53, 0);
            if (i == 0) {
                t->m_packet = D_00394274;
                t->m40 = 0;
                t->m_qwc = qwc[0];
            }
            func_001644E8(0, 0, 2, 0, 0, 0, qwc[i]);
            Close();
            Tag(qwc[i] | 0x30000000, (unsigned int)data);
            Put(0);
            Put(0);
            data += bytes[i];
        }

        t->m_dataSize = data - t->m_data;
        if (t->m_flags & 1)
            D_00394320 = (unsigned int*)data;
        t->m_levels = levels;

        unsigned long tex0 = (addr[0] & 0x3FFF) | (unsigned long)(bw[0] & 0x3F) << 14 | (unsigned long)psm6 << 20 |
                             (unsigned long)tw << 26 | (unsigned long)th << 30;
        if (psm != 1)
            tex0 |= (unsigned long)1 << 34;
        t->m_tex0 = tex0 | (unsigned long)cbp14 << 37 | (unsigned long)cpsm4 << 51 | (unsigned long)1 << 61;
        t->m_miptbp1 = (addr[1] & 0x3FFF) | (unsigned long)(bw[1] & 0x3F) << 14 | (unsigned long)(addr[2] & 0x3FFF) << 20 |
                       (unsigned long)(bw[2] & 0x3F) << 34 | (unsigned long)(addr[3] & 0x3FFF) << 40 |
                       (unsigned long)(bw[3] & 0x3F) << 54;
        limit = cbp;
        t->m_miptbp2 = (addr[4] & 0x3FFF) | (unsigned long)(bw[4] & 0x3F) << 14 | (unsigned long)(addr[5] & 0x3FFF) << 20 |
                       (unsigned long)(bw[5] & 0x3F) << 34 | (unsigned long)(addr[6] & 0x3FFF) << 40 |
                       (unsigned long)(bw[6] & 0x3F) << 54;
    }

    sector->m_count += count;
    Tag(0x70000000, 0);
    Put(0);
    Put(0);
    func_001644E8(0xE, 1, 0, 0, 0, 1, 1);
    func_001647B0(0x3F, 0);
    Close();
    if (!keep)
        D_0038C178++;
}
