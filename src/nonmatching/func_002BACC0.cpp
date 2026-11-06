/* fuzzy: 94.8 */
struct Box_002BACC0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Entry_002BACC0 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    int m4;
    int m8;
};

struct Heap_002BACC0;
extern void* D_00388A70;
extern "C" void** func_002C0368();
extern "C" int func_002B74E0(void* p);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" unsigned int func_002BAA28(Box_002BACC0* c, int a, int b, int d, int e, int f, int g);
extern "C" Box_002BACC0* func_002BE5F0(void* self, int key, int* out);
extern "C" void func_002B6C58(int t, Box_002BACC0* b);

struct Piece_002BACC0 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
    char pad6[2];
    int m8;
    int mC;
    Entry_002BACC0 m10[2];
    Entry_002BACC0* m28;
    int m2C;
    unsigned int m30;
    void SetRot(int rot);
};

void Piece_002BACC0::SetRot(int rot)
{
    int old = mC - 4;
    mC = rot;
    int d = rot - old;
    int r = d & 3;
    if (d & 1) {
        unsigned char t5 = m5;
        unsigned char t3 = m3;
        unsigned char t4 = m4;
        m3 = t5;
        m4 = t4;
        m5 = t3;
    }
    Entry_002BACC0 tmp[2];
    Box_002BACC0 b;
    Entry_002BACC0* extra = 0;
    if (m28) {
        void* h = D_00388A70;
        func_0010A950(h, func_002B74E0(*func_002C0368()));
        extra = (Entry_002BACC0*)func_0010A638(D_00388A70, (m2C - 2) * 12, 1, 0);
        func_0010A9B0(D_00388A70);
    }
    for (unsigned int i = 0; i < m30; i++) {
        Entry_002BACC0* dst = (i < 2) ? &tmp[i] : &extra[i - 2];
        Entry_002BACC0* src = (i < 2) ? &m10[i] : &m28[i - 2];
        *dst = *src;
        func_002BAA28(&b, 0, 0, 0, 0, 0, 0);
        if (m8 & 2) {
            b = *func_002BE5F0(func_002C0368(), src->m8, 0);
            if (src->m3 & 1) {
                unsigned char t5 = b.d;
                unsigned char t3 = b.w;
                unsigned char t4 = b.h;
                b.w = t5;
                b.h = t4;
                b.d = t3;
            }
        } else {
            func_002B6C58(src->m8, &b);
        }
        switch (r) {
        case 0:
            dst->m0 = src->m0;
            dst->m2 = src->m2;
            break;
        case 1:
            dst->m0 = src->m2;
            dst->m2 = m5 - src->m0 - b.w;
            break;
        case 2:
            dst->m0 = m3 - src->m0 - b.w;
            dst->m2 = m5 - src->m2 - b.d;
            break;
        case 3:
            dst->m0 = m3 - src->m2 - b.d;
            dst->m2 = src->m0;
            break;
        }
        dst->m1 = src->m1;
        dst->m3 = (src->m3 + r) & 3;
        dst->m8 = src->m8;
    }
    if (m28) func_0010A8D8(D_00388A70, m28);
    m28 = extra;
    for (int k = 0; k < 2; k++) m10[k] = tmp[k];
}
