struct Obj_002680E8 {
    char pad[0x160];
    int m160;
    int m164;
    int m168;
    void Set(int v);
};

void Obj_002680E8::Set(int v)
{
    m160 = v;
    m168 = 1;
}
