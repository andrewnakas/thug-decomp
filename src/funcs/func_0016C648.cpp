struct Item_0016C648 {
    int m0;
};

struct Slot_0016C648 {
    Item_0016C648* m0;
    char pad4[0x60 - 0x4];
    int m60;
    char pad64[0x70 - 0x64];
};

extern unsigned int D_0038BC1C;
extern Slot_0016C648 D_003E0AA0[12];
extern "C" void func_0016C618();

void func_0016C648()
{
    if (!D_0038BC1C)
        return;
    func_0016C618();
    for (int i = D_0038BC1C - 1; i >= 0; i--) {
        Slot_0016C648* s = &D_003E0AA0[i];
        if (s->m60 == 0 || i >= 9) {
            s->m0->m0 = 0;
            D_0038BC1C--;
        } else {
            s->m60 = 0;
        }
    }
}
