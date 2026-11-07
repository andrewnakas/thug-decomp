/* const: 0x195000 */
struct Blk_001F5138 {
    char m[0x195000];
};
struct Obj_001F5138 {
    Blk_001F5138* m0;
    int m4;
    int m8;
    char* Get();
};
extern "C" bool func_001F50A8(Obj_001F5138* self);

char* Obj_001F5138::Get()
{
    return !func_001F50A8(this) ? m0[m8].m : 0;
}
