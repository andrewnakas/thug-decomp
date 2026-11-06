extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned char* D_00394288;
extern long* D_003942AC;
extern int D_0038882C;
extern unsigned char* D_00393F24;
extern unsigned char* D_00393F28;
extern unsigned char* D_00393F2C;
extern unsigned char* D_003940A8;

extern "C" void func_00160E38(int type);
extern "C" long func_00160E90();
extern "C" void func_00164530(int regs, int nreg, int flg, int prim, int pre);
extern "C" void func_00164570(int eop);
extern "C" void func_001647B0(int reg, unsigned long v);

static inline bool IsMode1_001628A8()
{
    return D_0038882C == 1;
}

#define W_001628A8 (IsMode1_001628A8() ? 640 : 512)
#define H_001628A8 (IsMode1_001628A8() ? 448 : 512)

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

static inline void BeginDirect()
{
    unsigned char* end = (unsigned char*)((((int)D_00394274 + 3) & ~15) + 12);
    while (D_00394274 < end)
        *D_00394274++ = 0;
    D_00394288 = D_00394274;
    Put(0x50000000);
}

static inline void EndDirect()
{
    unsigned char* end = (unsigned char*)(((int)D_00394274 + 15) & ~15);
    while (D_00394274 < end)
        *D_00394274++ = 0;
    *(unsigned short*)D_00394288 = (D_00394274 - D_00394288 - 4) / 16;
}

static inline void Vec(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    ((unsigned int*)D_00394274)[0] = a;
    ((unsigned int*)D_00394274)[1] = b;
    ((unsigned int*)D_00394274)[2] = c;
    ((unsigned int*)D_00394274)[3] = d;
    D_00394274 += 16;
}

#define FB1_001628A8 (W_001628A8 * H_001628A8 * 4 / 8192)
#define FB2_001628A8 (W_001628A8 * H_001628A8 * 2 / 8192)
#define FB3_001628A8 (W_001628A8 * H_001628A8 * 4 / 8192 / 2)
#define SCISSOR_001628A8 ((unsigned long)(W_001628A8 - 1) << 16 | (unsigned long)(H_001628A8 - 1) << 48)
#define TEX0_001628A8 ((unsigned long)(W_001628A8 / 64) << 14 | (unsigned long)10 << 26 | (unsigned long)10 << 30 | (unsigned long)1 << 34 | (unsigned long)1 << 35)

extern "C" void func_001628A8()
{
    func_00160E38(2);
    Tag(0x70000000, 0);
    BeginDirect();
    func_00164530(0xE, 1, 0, 6, 1);
    func_001647B0(0x4C, 0x100000);
    func_001647B0(0x4E, (unsigned long)1 << 32);
    func_001647B0(0x47, 0x30000);
    func_001647B0(0x18, 0);
    func_001647B0(0x40, (unsigned long)0x7FF << 16 | (unsigned long)0x7FF << 48);
    func_001647B0(0x1A, 1);
    func_001647B0(0x22, 0);
    func_001647B0(0x4A, 0);
    func_001647B0(0x45, 0);
    func_001647B0(0x3B, (unsigned long)0x80 << 32);
    func_001647B0(0x01, 0);
    func_001647B0(0x05, 0);
    func_001647B0(0x05, 0x3FFF3FFF);
    func_001647B0(0x3F, 0);
    func_00164570(1);
    EndDirect();
    Put(0x11000000);
    Close();
    D_003942AC[0] = func_00160E90();

    unsigned int w = W_001628A8 * 16;
    unsigned int h = H_001628A8 * 16;


    func_00160E38(3);
    Put(0x13000000);
    BeginDirect();
    func_00164530(0xE, 1, 0, 0, 0);
    D_00393F28 = D_00394274 + 4;
    func_001647B0(0x42, (unsigned long)0x80 << 32 | 0x64);
    func_001647B0(0x44, 0x6273041573621504);
    func_001647B0(0x45, 1);
    func_001647B0(0x4A, 0);
    func_001647B0(0x4C, (unsigned long)FB1_001628A8 | (unsigned long)(W_001628A8 / 64) << 16 | (unsigned long)10 << 24);
    func_001647B0(0x1A, 1);
    func_001647B0(0x22, 0);
    func_001647B0(0x40, SCISSOR_001628A8);
    func_001647B0(0x47, 0x30000);
    func_001647B0(0x06, TEX0_001628A8);
    func_001647B0(0x14, 1);
    func_001647B0(0x3F, 0);
    func_001647B0(0x18, 0);
    func_001647B0(0x4E, (unsigned long)((FB1_001628A8 + FB2_001628A8) & 0x1FF) | (unsigned long)1 << 24);
    func_00164570(0);
    func_00164530(0x53, 2, 0, 0x156, 1);
    for (unsigned int u = 0; u < w; u += 0x200) {
        Vec(u + 8, 8, 0, 0);
        Vec(u, 0, 0, 0);
        Vec(u + 0x208, h + 8, 0, 0);
        Vec(u + 0x200, h, 0, 0);
    }
    func_00164570(0);
    func_00164530(0xE, 1, 0, 0, 0);
    func_001647B0(0x45, 0);
    func_001647B0(0x4C, (unsigned long)(W_001628A8 / 64) << 16);
    func_001647B0(0x4E, (unsigned long)FB3_001628A8);
    func_001647B0(0x01, 0x706050);
    func_00164570(1);
    func_00164530(5, 1, 0, 6, 1);
    for (unsigned int u = 0; u < w; u += 0x200) {
        Vec(u, 0, 0, 0);
        Vec(u + 0x200, h >> 1, 0x706050, 0);
    }
    func_00164570(1);
    EndDirect();
    D_003942AC[1] = func_00160E90();

    func_00160E38(3);
    Put(0x11000000);
    BeginDirect();
    float y0 = h * 0.125f;
    float y1 = h - y0;
    func_00164530(0xE, 1, 0, 0, 0);
    D_00393F2C = D_00394274 + 4;
    func_001647B0(0x42, (unsigned long)0x80 << 32 | 0x64);
    func_001647B0(0x44, 0x6273041573621504);
    func_001647B0(0x45, 1);
    func_001647B0(0x4A, 0);
    func_001647B0(0x4C, (unsigned long)FB1_001628A8 | (unsigned long)(W_001628A8 / 64) << 16 | (unsigned long)10 << 24);
    func_001647B0(0x1A, 1);
    func_001647B0(0x01, 0);
    func_001647B0(0x22, 0);
    func_001647B0(0x40, SCISSOR_001628A8);
    func_001647B0(0x47, 0x30000);
    func_001647B0(0x06, TEX0_001628A8);
    func_001647B0(0x14, 1);
    func_001647B0(0x3F, 0);
    func_001647B0(0x18, 0);
    func_001647B0(0x4E, (unsigned long)((FB1_001628A8 + FB2_001628A8) & 0x1FF) | (unsigned long)1 << 24);
    func_00164570(0);
    func_00164530(5, 1, 0, 6, 1);
    for (unsigned int u = 0; u < w; u += 0x200) {
        Vec(u, 0, 0, 0);
        Vec(u + 0x200, (int)y0, 0, 0);
    }
    for (unsigned int u = 0; u < w; u += 0x200) {
        Vec(u, (int)y1, 0, 0);
        Vec(u + 0x200, h, 0, 0);
    }
    func_00164570(1);
    func_00164530(0x53, 2, 0, 0x156, 1);
    for (unsigned int u = 0; u < w; u += 0x200) {
        Vec(u + 8, 8, 0, 0);
        Vec(u, (int)y0, 0, 0);
        Vec(u + 0x208, h + 8, 0, 0);
        Vec(u + 0x200, (int)y1, 0, 0);
    }
    func_00164570(0);
    func_00164530(0xE, 1, 0, 0, 0);
    func_001647B0(0x45, 0);
    func_001647B0(0x4C, (unsigned long)((FB1_001628A8 + FB2_001628A8) & 0x1FF) | (unsigned long)(W_001628A8 / 64) << 16 | (unsigned long)0xFF000000 << 32);
    func_001647B0(0x1A, 1);
    func_001647B0(0x01, 0);
    func_001647B0(0x22, 0);
    func_001647B0(0x40, SCISSOR_001628A8);
    func_001647B0(0x47, 0x30000);
    func_001647B0(0x18, 0);
    func_001647B0(0x4E, (unsigned long)((FB1_001628A8 + FB2_001628A8 + FB3_001628A8) & 0x1FF) | (unsigned long)1 << 24);
    func_00164570(1);
    func_00164530(5, 1, 0, 6, 1);
    for (unsigned int u = 0; u < w; u += 0x200) {
        Vec(u, 0, 0, 0);
        Vec(u + 0x200, h >> 1, 0, 0);
    }
    func_00164570(1);
    func_00164530(0xE, 1, 0, 0, 0);
    func_001647B0(0x45, 0);
    func_001647B0(0x4C, (unsigned long)(W_001628A8 / 64) << 16);
    func_001647B0(0x4E, (unsigned long)FB3_001628A8);
    func_001647B0(0x01, 0x706050);
    func_00164570(1);
    func_00164530(5, 1, 0, 6, 1);
    for (unsigned int u = 0; u < w; u += 0x200) {
        Vec(u, 0, 0, 0);
        Vec(u + 0x200, h >> 1, 0x706050, 0);
    }
    func_00164570(1);
    EndDirect();
    D_003942AC[7] = func_00160E90();

    func_00160E38(3);
    BeginDirect();
    func_00164530(0xE, 1, 0, 0, 0);
    func_001647B0(0x45, 0);
    func_001647B0(0x4A, 0);
    func_001647B0(0x4C, (unsigned long)(W_001628A8 / 64) << 16);
    func_001647B0(0x1A, 1);
    func_001647B0(0x01, 0x706050);
    func_001647B0(0x22, 0);
    func_001647B0(0x40, SCISSOR_001628A8);
    func_001647B0(0x47, 0x30000);
    func_001647B0(0x18, 0);
    func_001647B0(0x4E, (unsigned long)FB3_001628A8);
    func_00164570(1);
    func_00164530(5, 1, 0, 6, 1);
    for (unsigned int u = 0; u < w; u += 0x200) {
        Vec(u, 0, 0, 0);
        Vec(u + 0x200, h >> 1, 0x706050, 0);
    }
    func_00164570(1);
    EndDirect();
    D_003942AC[2] = func_00160E90();

    func_00160E38(3);
    BeginDirect();
    func_00164530(0xE, 1, 0, 0, 0);
    func_001647B0(0x45, 0);
    func_001647B0(0x4C, (unsigned long)((FB1_001628A8 + FB2_001628A8) & 0x1FF) | (unsigned long)(W_001628A8 / 64) << 16 | (unsigned long)0xFF000000 << 32);
    func_001647B0(0x1A, 1);
    func_001647B0(0x01, 0);
    func_001647B0(0x22, 0);
    func_001647B0(0x40, SCISSOR_001628A8);
    func_001647B0(0x47, 0x30000);
    func_001647B0(0x18, 0);
    func_001647B0(0x4E, (unsigned long)((FB1_001628A8 + FB2_001628A8 + FB3_001628A8) & 0x1FF) | (unsigned long)1 << 24);
    func_00164570(1);
    func_00164530(5, 1, 0, 6, 1);
    for (unsigned int u = 0; u < w; u += 0x200) {
        Vec(u, 0, 0, 0);
        Vec(u + 0x200, h >> 1, 0, 0);
    }
    func_00164570(1);
    EndDirect();
    D_003942AC[4] = func_00160E90();

    func_00160E38(3);
    BeginDirect();
    func_00164530(0xE, 1, 0, 0, 0);
    func_001647B0(0x42, (unsigned long)0x80 << 32 | 0x44);
    func_001647B0(0x08, 0);
    func_001647B0(0x46, 1);
    func_001647B0(0x45, 0);
    func_001647B0(0x4A, 0);
    func_001647B0(0x4C, (unsigned long)(W_001628A8 / 64) << 16);
    D_00393F24 = D_00394274;
    func_001647B0(0x1A, 1);
    func_001647B0(0x1B, 0x48);
    func_001647B0(0x22, 0);
    func_001647B0(0x40, SCISSOR_001628A8);
    func_001647B0(0x47, 0x5000D);
    func_001647B0(0x3F, 0);
    func_001647B0(0x18, (unsigned long)(0x8000 - W_001628A8 * 8) | (unsigned long)(0x8000 - H_001628A8 * 8) << 32);
    func_001647B0(0x4E, (unsigned long)((FB1_001628A8 + FB2_001628A8) & 0x1FF) | (unsigned long)1 << 24);
    func_00164570(1);
    EndDirect();
    Put(0x13000000);
    D_003942AC[3] = func_00160E90();

    func_00160E38(3);
    BeginDirect();
    func_00164530(0xE, 1, 0, 0, 0);
    D_003940A8 = D_00394274;
    func_001647B0(0x3D, 0xFF);
    func_00164570(1);
    EndDirect();
    D_003942AC[6] = func_00160E90();
}
