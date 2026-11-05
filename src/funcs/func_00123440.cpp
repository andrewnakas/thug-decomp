struct Blk_00123440 {
    int m[14];
};

struct Src_00123440 {
    int m0;
    int m4;
    Blk_00123440 m8;
};

extern "C" Blk_00123440* func_00123440(Blk_00123440* out, const Src_00123440* src)
{
    *out = src->m8;
    return out;
}
