struct Item_0023AC08 {
    char pad0[0x18];
    int m18;
};
extern "C" Item_0023AC08* func_0023AFE8(void* a, int i);

struct Obj_0023AC08 {
    char pad0[0x44];
    char m44[8];
    int Flag(int i);
};

int Obj_0023AC08::Flag(int i)
{
    return (func_0023AFE8(m44, i)->m18 >> 4) & 1;
}
