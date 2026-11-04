struct Box_002CC970 {
    unsigned char m0;
    signed char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
};

struct Grid_002CC970 {
    char pad0[0x10];
    Box_002CC970 m10;
    char pad16[0x44 - 0x16];
    int m44;
};

extern "C" Box_002CC970* func_002BAA28(Box_002CC970* b, int x, int y, int z, int w, int h, int d);
extern "C" void func_002CC840(int* x, int* z, int rot);

struct Obj_002CC970 {
    int m0;
    Box_002CC970* m4;
    unsigned char m8;
    signed char m9;
    unsigned char mA;
    int mC;
    unsigned char m10;
    unsigned char m11;
    void Get(Box_002CC970* out, unsigned char a, unsigned char b, Grid_002CC970* g);
};

void Obj_002CC970::Get(Box_002CC970* out, unsigned char a, unsigned char b, Grid_002CC970* g)
{
    Box_002CC970 t;
    func_002BAA28(&t, 0, 0, 0, 0, 0, 0);
    if (m4) {
        t = *m4;
    } else {
        t.m3 = 1;
        t.m4 = 1;
        t.m5 = 1;
    }
    switch ((g->m44 + mC) & 3) {
    case 0:
    case 2:
        out->m3 = t.m3; out->m4 = 1; out->m5 = t.m5;
        break;
    case 1:
    case 3:
        out->m3 = t.m5; out->m4 = 1; out->m5 = t.m3;
        break;
    }
    int dx = m8 - a;
    int dz = mA - b;
    func_002CC840(&dx, &dz, g->m44);
    switch (g->m44) {
    case 0:
        break;
    case 1:
        dz++; dz -= m10;
        break;
    case 2:
        dx++; dx -= m10;
        dz++; dz -= m11;
        break;
    case 3:
        dx++; dx -= m11;
        break;
    }
    Box_002CC970 p = g->m10;
    unsigned char x = p.m0 + dx;
    signed char y = m9;
    unsigned char z = p.m2 + dz;
    out->m0 = x;
    out->m1 = y;
    out->m2 = z;
}
