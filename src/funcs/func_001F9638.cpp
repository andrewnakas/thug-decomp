struct Obj_001F9638 {
    char pad[0xC08];
    int mC08[256];
    int m1008[256];
    void Add(int i, int v);
};

void Obj_001F9638::Add(int i, int v)
{
    mC08[i]++;
    m1008[i] += v;
}
