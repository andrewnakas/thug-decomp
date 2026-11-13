// m8/mC are ring-buffer indices also updated from the vsync handler (cf. func_001F51F8: volatile int mC).
struct Blk_001F5190 {
    char m[0x4CE40];
};
struct Obj_001F5190 {
    int m0;
    Blk_001F5190* m4;
    volatile int m8;
    volatile int mC;
    int m10;
    Blk_001F5190* Get();
};
extern "C" int func_001F5180(Obj_001F5190* self);

Blk_001F5190* Obj_001F5190::Get()
{
    if (func_001F5180(this))
        return 0;
    return &m4[((m8 - mC) + m10) % m10];
}
