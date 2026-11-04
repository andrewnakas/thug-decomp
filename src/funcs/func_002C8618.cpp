struct Box_002C8618 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

extern "C" void func_002BAA28(Box_002C8618* b, int x, int y, int z, int w, int h, int d);
extern "C" void func_002C88F0(void* self, Box_002C8618* out);

struct Obj_002C8618 {
    char pad0[0x10];
    Box_002C8618 m10;
    char pad16[0x54 - 0x16];
    unsigned char m54;
    Box_002C8618 m55;
    Box_002C8618 m5B;
    char pad61[3];
    int m64;
    unsigned char Step();
};

unsigned char Obj_002C8618::Step()
{
    if (m54 == 0) {
        m55 = m10;
        m5B = m10;
        m54 = 1;
        m64 = 0;
    } else if (m54 == 1) {
        Box_002C8618 b;
        func_002BAA28(&b, 0, 0, 0, 0, 0, 0);
        func_002C88F0(this, &b);
        if (b.w < 11 && b.d < 11) m54 = 2;
    }
    return m54;
}
