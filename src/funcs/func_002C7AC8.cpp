struct Box_002C7AC8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

extern "C" void func_002BAA28(Box_002C7AC8* b, int x, int y, int z, int w, int h, int d);
extern "C" void func_002CE120(void* p, void* self, Box_002C7AC8* b);
extern "C" int func_002BEC58(void* p, Box_002C7AC8* b, int a, int c);

struct Obj_002C7AC8 {
    char pad0[0x8];
    void* m8;
    char padC[0x4];
    Box_002C7AC8 m10;
    char pad16[0x6C - 0x16];
    void* m6C;
    char pad70[0xC];
    int m7C;
    int Test();
};

int Obj_002C7AC8::Test()
{
    Box_002C7AC8 b;
    func_002BAA28(&b, 0, 0, 0, 0, 0, 0);
    if (m7C == 5) {
        if (m6C) func_002CE120(m6C, this, &b);
        else return 0;
    } else {
        b = m10;
    }
    Box_002C7AC8 b2 = b;
    return func_002BEC58(m8, &b2, 0, 0);
}
