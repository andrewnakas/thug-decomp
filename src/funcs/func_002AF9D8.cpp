struct Bits_002AF9D8 {
    int m[8];
};

extern "C" void func_001FAA08(Bits_002AF9D8* b);
extern "C" void func_001FAA28(Bits_002AF9D8* b, void* data, int size);
extern "C" int func_001FAB88(Bits_002AF9D8* b, int n);
extern "C" void func_001FAC80(Bits_002AF9D8* b, int n);
extern "C" long func_001FAA60(Bits_002AF9D8* b);

struct Obj_002AF9D8 {
    void* m0;
    int m4;
    long m8;
};

bool Cmd_002AF9D8(Obj_002AF9D8* o)
{
    Bits_002AF9D8 bs;
    func_001FAA08(&bs);
    func_001FAA28(&bs, o->m0, 0x400);
    unsigned char mask = func_001FAB88(&bs, 8);
    for (unsigned char i = 0; i < 8; i++) {
        if ((mask >> i) & 1) {
            func_001FAB88(&bs, 16);
            int f = func_001FAB88(&bs, 9);
            if (f & 1)
                func_001FAC80(&bs, 16);
            if (f & 2)
                func_001FAC80(&bs, 16);
            if (f & 4)
                func_001FAC80(&bs, 16);
            if (f & 8)
                func_001FAC80(&bs, 16);
            if (f & 0x10)
                func_001FAC80(&bs, 16);
            if (f & 0x20)
                func_001FAC80(&bs, 16);
            if (f & 0x40) {
                func_001FAB88(&bs, 4);
                func_001FAB88(&bs, 6);
                func_001FAB88(&bs, 1);
                func_001FAB88(&bs, 1);
            }
            if (f & 0x80)
                func_001FAB88(&bs, 8);
            if (f & 0x100)
                func_001FAC80(&bs, 16);
        }
    }
    o->m8 = func_001FAA60(&bs);
    return true;
}
