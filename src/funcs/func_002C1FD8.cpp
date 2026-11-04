struct Box_002C1FD8 {
    unsigned char x;
    signed char y;
    int GetY() const { return y; }
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

extern "C" char* func_002BAA48(Box_002C1FD8* b, int idx);
extern "C" unsigned int func_002BEE08(void* self, Box_002C1FD8* b, int n);

struct Obj_002C1FD8 {
    char pad0[0x10];
    int m10;
    int m14;
    void Drop(Box_002C1FD8* in);
};

void Obj_002C1FD8::Drop(Box_002C1FD8* in)
{
    Box_002C1FD8 b = *in;
    *func_002BAA48(&b, 1) = in->GetY() - 1;
    *func_002BAA48(&b, 4) = 1;
    Box_002C1FD8 b2 = b;
    unsigned int r = func_002BEE08(this, &b2, 4);
    m10 += r >> 16;
    m14 += r & 0xFFFF;
}
