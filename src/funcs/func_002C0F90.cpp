struct Box_002C0F90 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    bool Lo0(int v) const { return x < v; }
    bool Hi0(int v) const { return v < x + w - 1; }
    bool Lo2(int v) const { return z < v; }
    bool Hi2(int v) const { return v < z + d - 1; }
};

struct Cell_002C0F90 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Item_002C0F90 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
};

extern "C" Box_002C0F90* func_002BAA28(Box_002C0F90* b, unsigned char x, signed char y, unsigned char z,
                                        unsigned char w, unsigned char h, unsigned char d);
extern "C" bool func_002C03B8(void* self, Box_002C0F90* b);
extern "C" void func_002C14F0(void* self, Item_002C0F90* it);
extern "C" void func_002C1298(void* self, Item_002C0F90* it);

struct Obj_002C0F90 {
    char pad0[0x3532];
    Box_002C0F90 box;
    Cell_002C0F90** cells;
    void Run(Item_002C0F90* it);
};


void Obj_002C0F90::Run(Item_002C0F90* it)
{
    int best = 10000;
    if (box.Lo0(it->m0)) best = best <= cells[it->m0 - 1][it->m8].m0 ? best : cells[it->m0 - 1][it->m8].m0;
    else best = best <= 0 ? best : 0;
    if (box.Hi0(it->m0)) best = best <= cells[it->m0 + 1][it->m8].m0 ? best : cells[it->m0 + 1][it->m8].m0;
    else best = best <= 0 ? best : 0;
    if (box.Lo2(it->m8)) best = best <= cells[it->m0][it->m8 - 1].m0 ? best : cells[it->m0][it->m8 - 1].m0;
    else best = best <= 0 ? best : 0;
    if (box.Hi2(it->m8)) best = best <= cells[it->m0][it->m8 + 1].m0 ? best : cells[it->m0][it->m8 + 1].m0;
    else best = best <= 0 ? best : 0;

    Box_002C0F90 b;
    func_002BAA28(&b, it->m0, 0, it->m8, 1, 1, 1);
    int flags = 1;
    Box_002C0F90 c = b;
    if (func_002C03B8(this, &c)) {
        it->m18 = 0;
        flags = 5;
    }
    if (best < it->m18) {
        it->m14 = best;
    } else {
        it->m14 = it->m18 - 1;
        flags &= ~1;
    }
    it->mC = flags;
    for (int i = it->m14; i < it->m18; i++) {
        if (i == it->m18 - 1 && !(flags & 4)) it->mC |= 2;
        if (i == -1) {
            if (best >= -1) it->m10 = 3;
            else it->m10 = 2;
        } else if (i < -1) {
            if (best >= i) it->m10 = 0;
            else it->m10 = 1;
        } else if (i == it->m18 - 1) {
            if (i == 0) it->m10 = 4;
            else it->m10 = 7;
        } else {
            if (i == 0) it->m10 = 5;
            else it->m10 = 6;
        }
        it->m4 = i;
        if (it->m1C) func_002C14F0(this, it);
        else func_002C1298(this, it);
    }
}
