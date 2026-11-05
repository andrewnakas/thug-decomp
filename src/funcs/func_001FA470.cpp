struct Obj_001FA470 {
    char pad0[0x2AC];
    int m2AC;
    char pad2B0[0x2CC - 0x2B0];
    int m2CC;
    void Set(int v);
};

void Obj_001FA470::Set(int v)
{
    if (m2AC != v) {
        m2AC = v;
        m2CC = 1;
    }
}
