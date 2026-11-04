struct Box_002C8788 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

extern "C" void func_002BAA28(Box_002C8788* b, int x, int y, int z, int w, int h, int d);
extern "C" int func_002BEC58(void* p, Box_002C8788* b, int a, int c);
extern "C" void func_002C8778(void* self);

extern "C" void func_002C88F0(void* self, Box_002C8788* out);

struct Obj_002C8788 {
    char pad0[0x8];
    void* m8;
    char padC[0x48];
    unsigned char m54;
    void Commit();
};

void Obj_002C8788::Commit()
{
    if (!m54) return;
    Box_002C8788 b;
    func_002BAA28(&b, 0, 0, 0, 0, 0, 0);
    func_002C88F0(this, &b);
    Box_002C8788 b2 = b;
    func_002BEC58(m8, &b2, 1, 1);
    func_002C8778(this);
}
