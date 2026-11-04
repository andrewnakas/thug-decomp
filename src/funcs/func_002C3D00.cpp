struct Box_002C3D00 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002C3D00(int a = 0, int b = 0, int c = 0, int e = 0, int f = 0, int g = 0);
};

struct Hdr_002C3D00 {
    int m0;
    short m4;
    short m6;
    unsigned short m8;
    short mA;
    unsigned char mC;
    unsigned char mD;
    unsigned char mE;
    unsigned char mF;
    unsigned short m10;
    unsigned short m12;
    unsigned char m14;
    char pad15[3];
    int m18;
    char m1C[0x40];
    signed char m5C[58 * 58];
};

struct Gap_002C3D00 {
    Box_002C3D00 p[2];
    int mC[2];
    int m14[2];
    int m1C[2];
    char m24[0x20];
    int m44;
    int m48;
    char pad4C[8];
};

struct Out_002C3D00 {
    unsigned char x[2];
    signed char y[2];
    unsigned char z[2];
    unsigned char f[2];
    unsigned char m8;
    char pad9;
    char name[0x20];
    unsigned short m2A;
};

struct Rec_002C3D00 {
    unsigned int a;
    unsigned int b;
};

struct Cell_002C3D00 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Arr_002C3D00;
struct Park_002C3D00;
extern void* D_00392808;
extern char D_0037A618[];
extern char D_0037A628[];
extern "C" Arr_002C3D00* func_001E55F8(char* name, int v);
extern "C" int func_001F0D78(char* s);
extern "C" int func_001E9300(Arr_002C3D00* a, unsigned int i);
extern "C" char* func_002BAA48(Box_002C3D00* b, int idx);
extern "C" void func_002C70C8(void* g, int v);
extern "C" void func_002B74E8(void* p, int v);
extern "C" void* func_002BE5F0(Park_002C3D00* self, int key, int* out);
extern "C" void* func_002BE6E0(Park_002C3D00* self, void* p, int a);
extern "C" void func_002BACC0(void* p, int v);
extern "C" void func_002BF008(Park_002C3D00* self, Box_002C3D00 b, void* p);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_002C0730(Park_002C3D00* self, Gap_002C3D00* g);

struct Park_002C3D00 {
    void* m0;
    char pad4[0x3528 - 4];
    int m3528;
    Box_002C3D00 m352C;
    char pad3532[6];
    Cell_002C3D00** m3538;
    char pad353C[0x6A60 - 0x353C];
    char* m6A60;
    int m6A64;
    void Load();
};

void Park_002C3D00::Load()
{
    Arr_002C3D00* a = func_001E55F8(D_0037A618, 1);
    int none = func_001F0D78(D_0037A628);
    Hdr_002C3D00* h = (Hdr_002C3D00*)m6A60;
    *func_002BAA48(&m352C, 0) = h->mC;
    *func_002BAA48(&m352C, 2) = h->mD;
    *func_002BAA48(&m352C, 3) = h->mE;
    *func_002BAA48(&m352C, 5) = h->mF;
    m3528 = h->m8;
    func_002C70C8(D_00392808, h->m18);
    func_002B74E8(m0, h->m14);
    signed char* in = h->m5C;
    for (int y = 0; y < 58; y++) {
        for (int x = 0; x < 58; x++) {
            m3538[y][x].m0 = *in++;
            m3538[y][x].m4 = 0;
        }
    }
    Rec_002C3D00* r = (Rec_002C3D00*)in;
    for (int i = 0; i < h->m10; i++, r++) {
        unsigned int ra = r->a;
        unsigned int rb = r->b;
        int key = func_001E9300(a, ra & 0x3FF);
        if (key == none) continue;
        void* p = func_002BE6E0(this, func_002BE5F0(this, key, 0), 0);
        Box_002C3D00 b;
        *func_002BAA48(&b, 0) = ra >> 10;
        *func_002BAA48(&b, 2) = ra >> 18;
        *func_002BAA48(&b, 1) = ((rb >> 2) & 0x1F) - 16;
        func_002BACC0(p, rb & 3);
        func_002BF008(this, b, p);
    }
    Out_002C3D00* o = (Out_002C3D00*)r;
    int j;
    for (j = 0; j < h->m12; j++) {
        Gap_002C3D00 g;
        for (int m = 0; m < 2; m++) {
            *func_002BAA48(&g.p[m], 0) = o->x[m];
            *func_002BAA48(&g.p[m], 1) = o->y[m] - 8;
            *func_002BAA48(&g.p[m], 2) = o->z[m];
            g.mC[m] = (o->m8 >> (m * 4)) & 0xF;
            g.m14[m] = o->f[m] >> 4;
            g.m1C[m] = o->f[m] & 0xF;
        }
        func_00331A9C(g.m24, o->name);
        g.m44 = o->m2A;
        g.m48 = 2;
        func_002C0730(this, &g);
        o = (Out_002C3D00*)((char*)o + 0x2C);
    }
    m6A64 |= 1;
    m6A64 &= ~4;
}
