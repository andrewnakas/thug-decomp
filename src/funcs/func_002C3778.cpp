struct Box_002C3778 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};


struct Hdr_002C3778 {
    int m0;
    short m4;
    short m6;
    unsigned short m8;
    short mA;
    unsigned char mC;
    unsigned char mD;
    unsigned char mE;
    unsigned char mF;
    short m10;
    short m12;
    unsigned char m14;
    char pad15[3];
    int m18;
    int m1C[(0x5C - 0x1C) / 4];
    unsigned char m5C[58 * 58];
    void SetBox(const Box_002C3778& b) { mC = b.x; mD = b.z; mE = b.w; mF = b.d; }
};

struct Glob_002C3778 {
    char pad[0xB8];
    int mB8;
};

extern Glob_002C3778* D_00392808;
extern int D_0037A560[4];
extern "C" void* memcpy(void* d, const void* s, unsigned int n);
extern "C" void func_002C4108(void* p);
extern "C" int func_001053C8(void* p, int size);

struct Park_002C3778 {
    char pad0[0x3528];
    unsigned short m3528;
    char pad352A[2];
    Box_002C3778 m352C;
    char pad3532[0x6A60 - 0x3532];
    char* m6A60;
    int m6A64;
    void Reset();
};

void Park_002C3778::Reset()
{
    func_002C4108(this);
    Hdr_002C3778* h = (Hdr_002C3778*)m6A60;
    h->m6 = 0x4E24;
    h->m8 = m3528;
    h->mA = 0;
    h->SetBox(m352C);
    if (D_00392808) h->m18 = D_00392808->mB8;
    else h->m18 = 0;
    h->m14 = 2;
    memcpy(h->m1C, D_0037A560, 13);
    unsigned char* out = h->m5C;
    for (int y = 0; y < 58; y++) {
        for (int x = 0; x < 58; x++) {
            *out++ = 0;
        }
    }
    h->m10 = 0;
    int size = (char*)out - (char*)h;
    h->m0 = func_001053C8(m6A60 + 4, size - 4);
    h->m4 = size;
    h->m12 = 0;
    if (!(m6A64 & 5)) m6A64 |= 8;
    m6A64 = (m6A64 | 3) & ~4;
}
