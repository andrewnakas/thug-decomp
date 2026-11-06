typedef int qword __attribute__((mode(TI)));

struct Vec_0014B608 {
    union {
        qword q;
        struct { float x, y, z, w; } f;
    };
};

struct Blk_0014B608 {
    unsigned int m_mask;
    int pad[3];
    Vec_0014B608 m_vecs[1];
};

extern Vec_0014B608 D_003DD9F0[];

class Obj_0014B608 {
public:
    char pad[0x1C];
    Blk_0014B608* m_blk;
    Vec_0014B608* GetVec(int i);
};

Vec_0014B608* Obj_0014B608::GetVec(int i)
{
    Blk_0014B608* b = m_blk;
    if (!(b->m_mask & (2 << i)))
        return &D_003DD9F0[i];
    return &b->m_vecs[i];
}
