struct Obj_0025AB18 {
    char pad[0x20];
    int m20;
    int m24;
    int Fn(int force);
};

int Obj_0025AB18::Fn(int force)
{
    if (!force) m24 = 1;
    if (m20) m24 = 1;
    return m24;
}
