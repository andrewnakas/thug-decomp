struct Box_002C8818 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

extern "C" void func_002BAA28(Box_002C8818* b, int x, int y, int z, int w, int h, int d);
extern "C" void func_002BFD50(void* p, Box_002C8818* b);
extern "C" void func_002C8778(void* self);

extern "C" void func_002C88F0(void* self, Box_002C8818* out);

struct Obj_002C8818 {
    char pad0[0x8];
    void* m8;
    char padC[0x48];
    unsigned char m54;
    void Erase();
};

void Obj_002C8818::Erase()
{
    if (!m54) return;
    Box_002C8818 b;
    func_002BAA28(&b, 0, 0, 0, 0, 0, 0);
    func_002C88F0(this, &b);
    Box_002C8818 b2 = b;
    func_002BFD50(m8, &b2);
    func_002C8778(this);
}
