extern char D_00361CE0[];
struct Obj_00187DA0 {
    int m0, m4, m8, mC, m10, m14;
    void* m18;
    Obj_00187DA0* Init();
};

Obj_00187DA0* Obj_00187DA0::Init()
{
    m4 = 0;
    m18 = D_00361CE0;
    m8 = 0;
    m0 = 0;
    m10 = 0;
    m14 = 0;
    return this;
}
