/* sym: __12Box_002BDDA8UcScUcUcUcUc = 0x002BAA28 */
struct Box_002BDDA8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002BDDA8(unsigned char x = 0, signed char y = 0, unsigned char z = 0,
                 unsigned char w = 0, unsigned char h = 0, unsigned char d = 0);
    unsigned char X() const { return x; }
    unsigned char Z() const { return z; }
    void SetPos(unsigned char nx, signed char ny, unsigned char nz) { x = nx; y = ny; z = nz; }
    void SetSize(unsigned char nw, unsigned char nh, unsigned char nd) { w = nw; h = nh; d = nd; }
};

struct Piece_002BDDA8 {
    Box_002BDDA8 m0;
    char pad6[2];
    int m8;
    bool F100() { return (m8 & 0x100) != 0; }
    bool F8() { return (m8 & 8) != 0; }
    bool F4() { return (m8 & 4) != 0; }
};

struct Node_002BDDA8 {
    char pad[0xC];
    Node_002BDDA8* mC;
};

struct Park_002BDDA8;

extern "C" Box_002BDDA8* func_002BAA28(Box_002BDDA8* b, unsigned char x, signed char y, unsigned char z,
                                        unsigned char w, unsigned char h, unsigned char d);
extern "C" unsigned char* func_002BAA48(Box_002BDDA8* b, int idx);
extern "C" void* func_002BC5A0(Node_002BDDA8* n);
extern "C" Piece_002BDDA8* func_002BAB80(void* p);
extern "C" void func_002BE958(Park_002BDDA8* self, Piece_002BDDA8* p, int f);
extern "C" int func_001F0D78(const char* s);
extern "C" void* func_002BE5F0(Park_002BDDA8* self, int key, int* out);
extern "C" bool func_002C03B8(Park_002BDDA8* self, Box_002BDDA8 b);
extern "C" Piece_002BDDA8* func_002BE6E0(Park_002BDDA8* self, void* inf, int a);
extern "C" void func_002BACC0(Piece_002BDDA8* p, int v);
extern "C" void func_002BF008(Park_002BDDA8* self, Box_002BDDA8 b, Piece_002BDDA8* p);
extern "C" int func_002BD248(Park_002BDDA8* self);
extern "C" void func_002B7E20(void* p, int v);
extern "C" void func_002B7DB0(void* p, int v);
extern char D_0037A590[];

struct Cell_002BDDA8 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Park_002BDDA8 {
    void* m0;
    char pad4[0x80 - 4];
    Node_002BDDA8* m80;
    char pad84[0x352C - 0x84];
    Box_002BDDA8 m352C;
    char pad3532[6];
    Cell_002BDDA8** m3538;
    char pad353C[0x6AA8 - 0x353C];
    Box_002BDDA8 m6AA8[4];
    const Box_002BDDA8& GetBox() { return m352C; }
    void Resize(Box_002BDDA8* nb);
};

void Park_002BDDA8::Resize(Box_002BDDA8* nb)
{
    m352C = *nb;
    *func_002BAA48(&m6AA8[0], 0) = GetBox().x - 1;
    *func_002BAA48(&m6AA8[0], 2) = GetBox().z - 1;
    *func_002BAA48(&m6AA8[0], 3) = 1;
    *func_002BAA48(&m6AA8[0], 5) = GetBox().d + 2;
    *func_002BAA48(&m6AA8[1], 0) = GetBox().x + GetBox().w;
    *func_002BAA48(&m6AA8[1], 2) = GetBox().z - 1;
    *func_002BAA48(&m6AA8[1], 3) = 1;
    *func_002BAA48(&m6AA8[1], 5) = GetBox().d + 2;
    *func_002BAA48(&m6AA8[2], 0) = GetBox().x - 1;
    *func_002BAA48(&m6AA8[2], 2) = GetBox().z - 1;
    *func_002BAA48(&m6AA8[2], 3) = GetBox().w + 2;
    *func_002BAA48(&m6AA8[2], 5) = 1;
    *func_002BAA48(&m6AA8[3], 0) = GetBox().x - 1;
    *func_002BAA48(&m6AA8[3], 2) = GetBox().z + GetBox().d;
    *func_002BAA48(&m6AA8[3], 3) = GetBox().w + 2;
    *func_002BAA48(&m6AA8[3], 5) = 1;
    for (Node_002BDDA8* n = m80; n;) {
        Node_002BDDA8* next = n->mC;
        Box_002BDDA8 a = func_002BAB80(func_002BC5A0(n))->m0;
        if (func_002BAB80(func_002BC5A0(n))->F100()) {
            func_002BE958(this, func_002BAB80(func_002BC5A0(n)), 0);
        } else if (!func_002BAB80(func_002BC5A0(n))->F8()) {
            if (func_002BAB80(func_002BC5A0(n))->F4()) {
                if (a.X() < GetBox().X() || a.Z() < GetBox().Z() || a.X() + a.w > GetBox().X() + GetBox().w || a.Z() + a.d > GetBox().Z() + GetBox().d) {
                    func_002BE958(this, func_002BAB80(func_002BC5A0(n)), 0);
                }
            }
        }
        n = next;
    }
    void* inf = func_002BE5F0(this, func_001F0D78(D_0037A590), 0);
    for (int i = m352C.X(); i < m352C.x + GetBox().w; i += 2) {
        unsigned char ix = i;
        Box_002BDDA8 a;
        a.SetSize(2, 1, 1);
        Box_002BDDA8 b1(ix, 0, GetBox().z - 1);
        a.SetPos(b1.x, 0, b1.z + 1);
        if (!func_002C03B8(this, a)) {
            Piece_002BDDA8* p = func_002BE6E0(this, inf, 0);
            func_002BACC0(p, 0);
            p->m8 |= 0x100;
            func_002BF008(this, b1, p);
        }
        b1.SetPos(ix, 0, GetBox().z + GetBox().d);
        a.SetPos(b1.x, 0, b1.z - 1);
        if (!func_002C03B8(this, a)) {
            Piece_002BDDA8* p = func_002BE6E0(this, inf, 0);
            func_002BACC0(p, 2);
            p->m8 |= 0x100;
            func_002BF008(this, b1, p);
        }
    }
    for (int j = GetBox().Z(); j < GetBox().z + GetBox().d; j += 2) {
        unsigned char jz = j;
        Box_002BDDA8 a;
        a.SetSize(1, 1, 2);
        Box_002BDDA8 b2(m352C.x - 1, 0, jz);
        a.SetPos(b2.x + 1, 0, b2.z);
        if (!func_002C03B8(this, a)) {
            Piece_002BDDA8* p = func_002BE6E0(this, inf, 0);
            func_002BACC0(p, 1);
            p->m8 |= 0x100;
            func_002BF008(this, b2, p);
        }
        b2.SetPos(m352C.x + GetBox().w, 0, jz);
        a.SetPos(b2.x - 1, 0, b2.z);
        if (!func_002C03B8(this, a)) {
            Piece_002BDDA8* p = func_002BE6E0(this, inf, 0);
            func_002BACC0(p, 3);
            p->m8 |= 0x100;
            func_002BF008(this, b2, p);
        }
    }
    for (int y = 0; y < 56; y++) {
        for (int x = 0; x < 56; x++) {
            if (y < GetBox().x || x < GetBox().z || y >= m352C.x + GetBox().w || x >= GetBox().z + GetBox().d) {
                m3538[y][x].m0 = 0;
            }
        }
    }
    func_002B7E20(m0, func_002BD248(this));
    func_002B7DB0(m0, 1);
}
