struct Item_002C8990 {
    char pad0[0x14];
    Item_002C8990* m14;
};

extern "C" void func_002CD490(Item_002C8990* p, int f);

struct Obj_002C8990 {
    char pad0[0x68];
    Item_002C8990* m68;
    void PopLast();
};

void Obj_002C8990::PopLast()
{
    Item_002C8990* prev = 0;
    Item_002C8990* p = 0;
    for (Item_002C8990* q = m68; q; q = q->m14) {
        prev = p;
        p = q;
    }
    if (p) {
        func_002CD490(p, 3);
        if (prev)
            prev->m14 = 0;
        else
            m68 = 0;
    }
}
