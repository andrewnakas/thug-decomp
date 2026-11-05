struct Blk_001234B8 {
    int m[14];
};

struct Dst_001234B8 {
    int m0;
    int m4;
    Blk_001234B8 m8;
};

extern "C" void func_001234B8(Dst_001234B8* dst, const Blk_001234B8* src)
{
    dst->m8 = *src;
}
