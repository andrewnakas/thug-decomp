struct Obj_00291DE8 {
    char pad0[0x188];
    int m188[1];
    void Clear();
};

void Obj_00291DE8::Clear()
{
    for (int i = 0; i < 1; i++)
        m188[i] = 0;
}
