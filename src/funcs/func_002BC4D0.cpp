struct Item_002BC4D0 {
    int m0;
    int m4;
    int m8;
};

struct Piece_002BC4D0 {
    char pad0[0x8];
    unsigned int m8;
    char padC[0x24];
    unsigned int m30;
};

extern "C" Item_002BC4D0* func_002BB3B0(void* self, unsigned int i);
extern "C" void* func_002C0368();
extern "C" Piece_002BC4D0* func_002BE5F0(void* self, int key, int* out);

struct Obj_002BC4D0 {
    char pad0[0x30];
    unsigned int m30;
    unsigned int Count();
};

unsigned int Obj_002BC4D0::Count()
{
    unsigned int n = 0;
    for (unsigned int i = 0; i < m30; i++) {
        Item_002BC4D0* it = func_002BB3B0(this, i);
        Piece_002BC4D0* p = func_002BE5F0(func_002C0368(), it->m8, 0);
        if (p->m8 & 0x80) {
            n++;
        } else {
            for (unsigned int j = 0; j < p->m30; j++) n++;
        }
    }
    return n;
}
