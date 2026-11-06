struct Item_0016C890 {
    int m0;
    int m4;
    char pad8[0x60 - 0x8];
};

extern unsigned int D_0038BC14;
extern unsigned int D_0038BC18;
extern Item_0016C890 D_003DDAA0[];
extern "C" void func_0016C590(Item_0016C890* item);

void func_0016C890()
{
    if (D_0038BC14 != 0) {
        unsigned int added = 0;
        unsigned int i = 0;
        do {
            if (added >= 4)
                break;
            Item_0016C890* it = &D_003DDAA0[D_0038BC18++];
            if (it->m0 == 0 && it->m4 != 0) {
                func_0016C590(it);
                added++;
            }
            i++;
            if (D_0038BC18 >= D_0038BC14)
                D_0038BC18 = 0;
        } while (i < D_0038BC14);
    }
}
