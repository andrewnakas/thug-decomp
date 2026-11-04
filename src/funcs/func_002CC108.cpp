struct Item_002CC108 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    char pad1C[0xE8 - 0x1C];
    int mE8;
};

struct Obj_002CC108 {
    int m0;
    Item_002CC108* m4[32];
    int m84[32];
    void Add(int a, int b, int idx);
};

void Obj_002CC108::Add(int a, int b, int idx)
{
    Item_002CC108* it = m4[idx];
    for (int i = 0; i < 32; i++) {
        if (!m4[i]) {
            m4[i] = it;
            it->m8 = m0++;
            m4[i]->m10 = a;
            m4[i]->m18 = b;
            m4[i]->mE8 = idx;
            m84[i] = 0;
            return;
        }
    }
}
