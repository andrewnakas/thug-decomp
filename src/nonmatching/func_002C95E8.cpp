/* fuzzy: 95.3 */
/* blocked: residue is the second (z) clamp's schedule after func_002CE120: the game loads m4.m4 before t.z.
   Declaring tz/ez before lim cuts 17 -> 15 differing words but lowers fuzzy (95.3 -> 93.6); tz before b and an
   inline Fit helper for both axes (62 words) do not help; oracle_directed stops at 10 words, no forced match. */
struct Box_002C95E8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct SBox_002C95E8 {
    signed char x;
    signed char y;
    signed char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Board_002C95E8 {
    char pad0[0x352C];
    Box_002C95E8 bounds;
};

struct Sub_002C95E8 {
    int m0;
    Board_002C95E8* m4;
    Board_002C95E8* Get() { return m4; }
};

extern "C" unsigned char* func_002BAA48(Box_002C95E8* b, int idx);
extern "C" void func_002BAA28(SBox_002C95E8* b, int x, int y, int z, int w, int h, int d);
extern "C" void func_002CE120(void* p, void* self, SBox_002C95E8* b);

struct Obj_002C95E8 {
    char pad0[0x4];
    Sub_002C95E8 m4;
    char padC[0x10 - 0xC];
    Box_002C95E8 m10;
    char pad16[0x6C - 0x16];
    void* m6C;
    char pad70[0x7C - 0x70];
    int m7C;
    int Bx() { Box_002C95E8* bb = &m4.Get()->bounds; return bb->x + bb->w; }
    int Bz() { Box_002C95E8* bb = &m4.Get()->bounds; return bb->z + bb->d; }
    void Clamp();
};

void Obj_002C95E8::Clamp()
{
    if (*func_002BAA48(&m10, 0) < m4.Get()->bounds.x)
        *func_002BAA48(&m10, 0) = m4.Get()->bounds.x;
    if (*func_002BAA48(&m10, 0) + *func_002BAA48(&m10, 3) > Bx())
    {
        unsigned char* p = func_002BAA48(&m10, 0);
        Box_002C95E8* bb = &m4.Get()->bounds;
        int x = bb->x;
        int w = bb->w;
        *p = x + w - *func_002BAA48(&m10, 3);
    }
    if (*func_002BAA48(&m10, 2) < m4.Get()->bounds.z)
        *func_002BAA48(&m10, 2) = m4.Get()->bounds.z;
    if (*func_002BAA48(&m10, 2) + *func_002BAA48(&m10, 5) > Bz())
    {
        unsigned char* p = func_002BAA48(&m10, 2);
        Box_002C95E8* bb = &m4.Get()->bounds;
        int z = bb->z;
        int d = bb->d;
        *p = z + d - *func_002BAA48(&m10, 5);
    }
    if (m7C == 5 && m6C) {
        SBox_002C95E8 t;
        func_002BAA28(&t, 0, 0, 0, 0, 0, 0);
        func_002CE120(m6C, this, &t);
        {
            Box_002C95E8* b = &m4.Get()->bounds;
            int lim = b->x + b->w - 1;
            signed char tx = t.x;
            signed char ex = tx;
            ex += t.w - 1;
            int off = (tx < b->x) ? b->x - tx : 0;
            if (lim < ex) off = lim - ex;
            *func_002BAA48(&m10, 0) += off;
        }
        {
            Box_002C95E8* b = &m4.Get()->bounds;
            int lim = b->z + b->d - 1;
            signed char tz = t.z;
            signed char ez = tz;
            ez += t.d - 1;
            int off = (tz < b->z) ? b->z - tz : 0;
            if (lim < ez) off = lim - ez;
            *func_002BAA48(&m10, 2) += off;
        }
    }
}
