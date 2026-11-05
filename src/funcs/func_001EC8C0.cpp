extern int D_0038E6E4;

struct Obj_001EC8C0 {
    char pad0[0x5C];
    int m5C;
    int m60;
    Obj_001EC8C0* Init();
};

Obj_001EC8C0* Obj_001EC8C0::Init()
{
    m5C = 0;
    m60 = 0;
    D_0038E6E4++;
    return this;
}
