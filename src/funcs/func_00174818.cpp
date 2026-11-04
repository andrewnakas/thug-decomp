struct Tex_00174818 {
    int pad0;
    int pad4;
    int m8;
};

struct Mat_00174818 {
    int m0;
    int m4;
    Tex_00174818* m8;
    int padC;
    char m10[8];
    long m18;
    long m20;
    unsigned char m28;
    char pad29[0xB];
    short m34;
    short m36;
};

struct Group_00174818 {
    char pad0[0x28];
    int m28;
    Mat_00174818* m2C;
};

extern unsigned int D_00394314;

extern "C" void* func_0010BDE0(int size);
extern "C" Tex_00174818* func_00181A50(unsigned int checksum, unsigned int group);
extern "C" Tex_00174818* func_001819E8(unsigned int checksum);

static inline unsigned char* Read(unsigned char* src, int n, void* dst)
{
    unsigned char* d = (unsigned char*)dst;
    unsigned char* s = src;
    int c = n;
    while (c > 0) {
        *d++ = *s++;
        c--;
    }
    return s;
}

static inline long Tex1(int lcm, int mxl, int mmag, int mmin, int mtba, int l, int k)
{
    return (unsigned long)(lcm & 1) | ((unsigned long)(mxl & 7) << 2) | ((unsigned long)(mmag & 1) << 5)
        | ((unsigned long)(mmin & 7) << 6) | ((unsigned long)(mtba & 1) << 9) | ((unsigned long)(l & 3) << 19)
        | ((unsigned long)(k & 0xFFF) << 32);
}

extern "C" unsigned char* func_00174818(unsigned char* p, Group_00174818* grp, int groupBase)
{
    unsigned int texChecksum;
    unsigned int texGroup;
    int wms;
    int wmt;
    unsigned int numPasses;
    int passSize;
    int mmag;
    int mmin;
    union {
        float f;
        int i;
    } k;
    int l;
    float f;
    p = Read(p, 4, &grp->m28);
    grp->m2C = (Mat_00174818*)func_0010BDE0(grp->m28 * 0x38);
    Mat_00174818* m = grp->m2C;
    int i;
    for (i = 0; i < grp->m28; i++) {
        p = Read(p, 4, &m->m4);
        if (D_00394314 >= 5)
            p = Read(p, 4, &m->m0);
        if (D_00394314 >= 2) {
            if (D_00394314 >= 3)
                p = Read(p, 4, &m->m28);
            else
                p = Read(p, 1, &m->m28);
        } else {
            m->m28 = 1;
        }
        if (D_00394314 >= 5) {
            if (!(m->m0 & 0x800))
                p = Read(p, 4, &texChecksum);
        } else {
            p = Read(p, 4, &texChecksum);
        }
        if (D_00394314 >= 3) {
            p = Read(p, 4, &texGroup);
            texGroup += groupBase;
        }
        if (D_00394314 < 5)
            p = Read(p, 4, &m->m0);
        p = Read(p, 8, m->m10);
        if (D_00394314 >= 2) {
            p = Read(p, 4, &wms);
            p = Read(p, 4, &wmt);
            m->m20 = (unsigned long)(wms & 3) | ((unsigned long)(wmt & 3) << 2);
        } else {
            m->m20 = 0;
        }
        int flags = m->m0;
        p += 0x24;
        if (flags & 1)
            p += 0x28;
        if (flags & 2) {
            p = Read(p, 4, &numPasses);
            unsigned int j;
            for (j = 0; j < numPasses; j++) {
                p = Read(p, 4, &passSize);
                p += passSize * 0x14;
            }
        }
        if (texChecksum) {
            Tex_00174818* tex;
            if (D_00394314 >= 3)
                tex = func_00181A50(texChecksum, texGroup);
            else
                tex = func_001819E8(texChecksum);
            m->m8 = tex;
            int mxl = tex->m8;
            p = Read(p, 4, &mmag);
            p = Read(p, 4, &mmin);
            p = Read(p, 4, &k);
            k.i = (int)(k.f * 16.0f) & 0xFFF;
            if (D_00394314 >= 2) {
                m->m18 = Tex1(0, mxl, mmag, mmin, 0, 0, k.i);
            } else {
                p = Read(p, 4, &l);
                m->m18 = Tex1(0, mxl, mmag, mmin, 0, l, k.i);
            }
        } else {
            m->m8 = 0;
            if (D_00394314 == 1)
                p += 0x10;
            else
                p += 0xC;
        }
        if (D_00394314 >= 4) {
            p = Read(p, 4, &f);
            m->m34 = (int)(f * 256.0f);
            p = Read(p, 4, &f);
            m->m36 = (int)(f * 256.0f);
        }
        m++;
    }
    return p;
}
