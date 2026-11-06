struct Obj_001B0E60 {
    char pad[0x9AC];
    float m9AC[22];
    int mA04[8];
    void Set(int i, float v);
};

void Obj_001B0E60::Set(int i, float v)
{
    mA04[i] = 0;
    m9AC[i] = v;
}
