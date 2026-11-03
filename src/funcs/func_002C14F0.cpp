struct Box_002C14F0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Item_002C14F0 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
};

struct Keys_002C14F0 {
    int a;
    int b;
    int c;
};

extern "C" Box_002C14F0* func_002BAA28(Box_002C14F0* b, unsigned char x, signed char y, unsigned char z,
                                        unsigned char w, unsigned char h, unsigned char d);
extern "C" void* func_002BE5F0(void* self, int key, int* out);
extern "C" void* func_002BE6E0(void* self, void* p, int a);
extern "C" void func_002BF008(void* self, Box_002C14F0* b, void* r);

struct Obj_002C14F0 {
    char pad0[0x18];
    Keys_002C14F0 m18[1];
    void Remove(Item_002C14F0* it);
};

void Obj_002C14F0::Remove(Item_002C14F0* it)
{
    int key;
    if (it->mC & 1) {
        if (it->mC & 2) {
            key = m18[it->m10].a;
        } else {
            key = m18[it->m10].b;
        }
    } else {
        if (!(it->mC & 2)) return;
        key = m18[it->m10].c;
    }
    void* r = func_002BE6E0(this, func_002BE5F0(this, key, 0), 0);
    Box_002C14F0 b;
    func_002BAA28(&b, it->m0, it->m4, it->m8, 0, 0, 0);
    Box_002C14F0 b2 = b;
    func_002BF008(this, &b2, r);
    it->m24++;
}
