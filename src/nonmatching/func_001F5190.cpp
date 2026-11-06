/* fuzzy: 92.0 */
struct Blk_001F5190 {
    char m[0x4CE40];
};
struct Obj_001F5190 {
    int m0;
    Blk_001F5190* m4;
    int m8;
    int mC;
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
