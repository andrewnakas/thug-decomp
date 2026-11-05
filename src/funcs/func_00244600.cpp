struct Obj_00244600 {
    char pad0[0x54];
    int m54;
    void Add(int s);
};

void Obj_00244600::Add(int s)
{
    int t = m54 + 20;
    m54 = t + s * 1000;
}
