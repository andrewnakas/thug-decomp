struct Box_002C3330 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Cell_002C3330 {
    unsigned char m0;
    char pad[15];
};

struct Arr_002C3330 {
    int m0;
    int m4;
    int m8;
    unsigned int mC;
};

struct Hdr_002C3330 {
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
    char m1C[0x40];
    unsigned char m5C[58 * 58];
    void SetBox(const Box_002C3330& b) { mC = b.x; mD = b.z; mE = b.w; mF = b.d; }
};

struct Gap_002C3330 {
    Box_002C3330 p[2];
    int mC[2];
    int m14[2];
    int m1C[2];
    char m24[0x20];
    unsigned short m44;
    char pad46[2];
    int m48;
    char pad4C[4];
    int m50;
};

struct Out_002C3330 {
    unsigned char x[2];
    signed char y[2];
    unsigned char z[2];
    unsigned char f[2];
    unsigned char m8;
    char pad9;
    char name[0x20];
    unsigned short m2A;
    int m2C;
};

struct Rec_002C3330 {
    int a;
    int b;
};

struct Piece_002C3330 {
    Box_002C3330 m0;
    char pad6[2];
    int m8;
    int mC;
    char pad10[0x34 - 0x10];
    int m34;
    bool F8() { return (m8 & 8) != 0; }
    bool F100() { return (m8 & 0x100) != 0; }
    bool F4() { return (m8 & 4) != 0; }
};

struct Node_002C3330 {
    char pad[0xC];
    Node_002C3330* mC;
};

struct Glob_002C3330 {
    char pad[0xB8];
    int mB8;
};

struct Info_002C3330 {
    char pad[0x28];
    int m28;
};

extern Glob_002C3330* D_00392808;
extern char D_0037A618[];
extern "C" Arr_002C3330* func_001E55F8(char* name, int v);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" void* func_002BC5A0(Node_002C3330* n);
extern "C" Piece_002C3330* func_002BAB80(void* p);
extern "C" int func_001E9300(Arr_002C3330* a, unsigned int i);
extern "C" Gap_002C3330* func_002CC5A0(void* p, int v, int* out);
extern "C" int func_001053C8(void* p, int size);

struct Park_002C3330 {
    Info_002C3330* m0;
    char pad4[0x80 - 4];
    Node_002C3330* m80;
    char pad84[0x3528 - 0x84];
    unsigned short m3528;
    char pad352A[2];
    Box_002C3330 m352C;
    char pad3532[6];
    Cell_002C3330** m3538;
    char pad353C[0x6A60 - 0x353C];
    char* m6A60;
    int m6A64;
    char m6A68[0x6B00 - 0x6A68];
    void* m6B00;
    void Save();
};

void Park_002C3330::Save()
{
    if (m6A64 & 4) return;
    Box_002C3330 b;
    Gap_002C3330* gaps[32];
    int found;
    for (int i = 0; i < 15000; i++) m6A60[i] = 0;
    Arr_002C3330* a = func_001E55F8(D_0037A618, 1);
    unsigned int cnt = a->mC;
    Hdr_002C3330* h = (Hdr_002C3330*)m6A60;
    h->m6 = 0x4E24;
    h->m8 = m3528;
    h->mA = 0;
    h->SetBox(m352C);
    h->m18 = D_00392808->mB8;
    int lv = m0->m28;
    h->m14 = lv;
    func_00331A9C(h->m1C, m6A68);
    unsigned char* out = h->m5C;
    for (int y = 0; y < 58; y++) {
        for (int x = 0; x < 58; x++) {
            *out++ = m3538[y][x].m0;
        }
    }
    Rec_002C3330* r = (Rec_002C3330*)out;
    int np = 0;
    for (Node_002C3330* n = m80; n; n = n->mC) {
        Piece_002C3330* p = func_002BAB80(func_002BC5A0(n));
        if (p->F8()) continue;
        if (p->F100()) continue;
        if (!p->F4()) continue;
        int* pb = &r->b;
        b = p->m0;
        int key = p->m34;
        unsigned int i = 0;
        for (;;) {
            if (i >= cnt) goto next;
            if (func_001E9300(a, i) == key) break;
            i++;
        }
        np++;
        r->a = i & 0x3FF;
        r->a |= b.x << 10;
        r->a |= b.z << 18;
        r++;
        *pb = p->mC & 3;
        *pb |= ((b.y + 16) & 0x1F) << 2;
    next:;
    }
    h->m10 = np;
    int ng = 0;
    int j;
    for (j = 0; j < 32; j++) {
        found = 0;
        Gap_002C3330* g = func_002CC5A0(m6B00, j, &found);
        if (g && !found && g->m48 == 2) {
            gaps[ng] = g;
            ng++;
        }
    }
    h->m12 = ng;
    Out_002C3330* o = (Out_002C3330*)r;
    for (j = 0; j < ng; j++) {
        o->m8 = 0;
        for (int m = 0; m < 2; m++) {
            o->x[m] = (m + gaps[j]->p)->x;
            int yv = (m + gaps[j]->p)->y;
            o->y[m] = yv + 8;
            o->z[m] = (m + gaps[j]->p)->z;
            o->m8 |= gaps[j]->mC[m] << (m * 4);
            o->f[m] = (gaps[j]->m14[m] & 0xF) << 4;
            o->f[m] |= gaps[j]->m1C[m] & 0xF;
        }
        func_00331A9C(o->name, gaps[j]->m24);
        o->m2A = gaps[j]->m44;
        o->m2C = gaps[j]->m50;
        o++;
    }
    h->m4 = (char*)o - (char*)h;
    if (!(m6A64 & 5)) m6A64 |= 8;
    m6A64 = (m6A64 | 3) & ~4;
    h->m0 = func_001053C8(m6A60 + 4, 0x3A94);
}
