/* fuzzy: 97.2 */
struct Tex_00175650 {
    int pad0;
    int pad4;
    unsigned int m8;
    int padC;
    long m10;
    long m18;
    long m20;
};

struct Mat_00175650 {
    int m0;
    int pad4;
    Tex_00175650* m8;
    int padC;
    long m10;
    long m18;
    long m20;
    unsigned char m28;
};

struct Mesh_00175650 {
    int pad0;
    int m4;
};

extern unsigned char* D_00394274;
extern int D_00394000;
extern int D_003942F0;
extern int D_0038BF7C;
extern int D_0039431C;
extern char D_1D0[];
extern char D_1E0[];
extern char D_1F0[];
extern char D_210[];

extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);
extern "C" void func_00175D40(int a, int b, int c, unsigned int n, unsigned int d);
extern "C" void func_00175DB8();
extern "C" void func_00175E18(Mesh_00175650* m, Mat_00175650* mat, unsigned int i);
extern "C" void func_00175FF8(void* p);
extern "C" void func_001761E8(void* p);
extern "C" void func_001763F8(void* p, int w, int h);
extern "C" void func_00176620(void* p);
extern "C" void func_00176888(void* p);
extern "C" void func_00176AF8(void* p, void* q);
extern "C" void func_00176D90(void* p);
extern "C" void func_00177020(void* p, int a, int b);
extern "C" void func_00177920();

static inline void PutReg(long v, int reg)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = (unsigned int)v;
    p[1] = (unsigned int)(v >> 32);
    p[2] = reg;
    D_00394274 = (unsigned char*)(p + 3);
}

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

extern "C" unsigned char* func_00175650(unsigned char* data, Mesh_00175650* mesh, Mat_00175650* mat, int unused, int arg)
{
    char buf[0x40];
    unsigned int count;
    int uvOff;
    int texW = 0;
    int texH = 0;
    unsigned char* p = Read(data, 4, &count);
    if (!count) return p;
    int fmt = 4;
    int nreg = 1;
    int mode = 0x64;
    unsigned int prog = (unsigned int)D_1D0 >> 3;
    if (mesh->m4 & 2) {
        fmt = 0x41;
        nreg = 2;
    }
    int mf = mat->m0;
    if (mesh->m4 & 4) {
        if (mf & 8) {
            fmt = (fmt << 4) | 2;
            prog = (unsigned int)D_1F0 >> 3;
            mode = 0x74;
        } else {
            fmt = (fmt << 4) | 0xF;
        }
        nreg++;
    }
    if ((mesh->m4 & 1) && !(mf & 8)) {
        fmt = (fmt << 4) | 2;
        prog = (unsigned int)D_1E0 >> 3;
        nreg++;
        mode |= 0x10;
    }
    if (mf & 0x20)
        mode |= 8;
    if (mesh->m4 & 0x10) {
        if (mat->m20 & 0xF) {
            fmt = 0x51FF2;
            prog = (unsigned int)D_210 >> 3;
            nreg = 5;
            mode |= 0x10;
        } else {
            fmt = 0x51FF3;
            prog = (unsigned int)D_210 >> 3;
            nreg = 5;
            mode |= 0x110;
        }
    }
    func_001645F8(1, 0, 0);
    PutReg(mat->m10, 0x42);
    PutReg(((unsigned long)mat->m28 << 4) | 0x5000B, 0x47);
    if (mat->m0 & 4) {
        Tex_00175650* t = mat->m8;
        PutReg(t->m10, 6);
        PutReg(mat->m18, 0x14);
        PutReg(mat->m20, 8);
        if (t->m8) {
            PutReg(t->m18, 0x34);
            if (t->m8 >= 4)
                PutReg(t->m20, 0x36);
        }
        texW = 1 << (int)(((unsigned long)t->m10 >> 26) & 0xF);
        texH = 1 << (int)(((unsigned long)t->m10 >> 30) & 0xF);
    }
    func_001646D0(0);
    uvOff = 0;
    D_003942F0 = 0xF0;
    func_00175D40(fmt, nreg, mode, count, prog);
    int colOff = 0;
    int f = mesh->m4;
    int normOff = 0;
    int posOff = 0;
    int stride = (f & 0x10) ? 8 : 0x10;
    if (f & 0x10) {
        stride += 8;
        posOff = 8;
    }
    if (f & 4) {
        stride += 4;
        posOff += 4;
        normOff = 4;
    }
    if (f & 2) {
        stride += 4;
        posOff += 4;
        normOff += 4;
        colOff = 4;
    }
    if (f & 1) {
        int n = (f & 0x10) ? 4 : 8;
        stride += n;
        posOff += n;
        normOff += n;
        colOff += n;
        uvOff = n;
    }
    unsigned int i;
    for (i = 0; i < count; i++) {
        D_00394000 = 1;
        p = Read(p, stride, buf);
        func_00175E18(mesh, mat, i);
        f = mesh->m4;
        if (f & 0x10) {
            D_00394000 = 1;
            if ((f & 1) && !(mat->m0 & 8)) {
                if (mat->m20 & 0xF)
                    func_001761E8(buf);
                else
                    func_001763F8(buf, texW << 4, texH << 4);
            }
            D_00394000 = 2;
            func_00176888(buf + normOff);
            D_00394000 = 3;
            func_00176AF8(buf + colOff, buf + normOff + 4);
            D_00394000 = 4;
            if (mesh->m4 & 2)
                func_00176D90(buf + uvOff);
            D_00394000 = 5;
            func_00177020(buf + posOff, 1, arg);
        } else {
            if ((f & 1) && !(mat->m0 & 8))
                func_00175FF8(buf);
            if (mesh->m4 & 4)
                func_00176620(buf + colOff);
            if (mesh->m4 & 2)
                func_00176D90(buf + uvOff);
            func_00177020(buf + posOff, 0, arg);
        }
        func_00177920();
        D_0038BF7C++;
    }
    D_0039431C += count;
    func_00175DB8();
    return p;
}
