struct Piece_002CC920 {
    char pad0[8];
    int m8;
};

extern "C" void* func_002C0368();
extern "C" void func_002BE958(void* p, Piece_002CC920* pc, int f);

struct Obj_002CC920 {
    char pad0[0x14];
    Piece_002CC920* m14;
    void Drop();
};

void Obj_002CC920::Drop()
{
    if (m14) {
        m14->m8 &= ~0x200;
        func_002BE958(func_002C0368(), m14, 0);
        m14 = 0;
    }
}
