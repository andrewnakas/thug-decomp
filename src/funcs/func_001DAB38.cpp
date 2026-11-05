struct Item_001DAB38 {
    int m0;
    int m4;
    char* m8;
};
struct Ent_001DAB38 {
    Item_001DAB38* m0;
    char* m4;
};
struct Obj_001DAB38 {
    char pad[0x20];
    Ent_001DAB38 m20[(0xFC0 - 0x20) / 8];
    int mFC0;
    int mFC4;
    void Add(Item_001DAB38* it);
};

void Obj_001DAB38::Add(Item_001DAB38* it)
{
    m20[mFC0].m4 = it->m8 + 0x10;
    m20[mFC0++].m0 = it;
    mFC4++;
}
