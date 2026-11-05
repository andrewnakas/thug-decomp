struct Sub_00203360 {
    char pad0[0x1C];
    int m1C;
};
struct Obj_00203360 {
    char pad0[0x2D8];
    Sub_00203360* m2D8;
    int Get();
};

int Obj_00203360::Get()
{
    return m2D8->m1C;
}
