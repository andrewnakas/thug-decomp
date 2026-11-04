struct Obj_002CBDC0;
extern Obj_002CBDC0* D_00392940;

struct Obj_002CBDC0 {
    int m0;
    int m4[32];
    char pad84[0x104 - 0x84];
    int m104;
    Obj_002CBDC0* Init(int v);
};

Obj_002CBDC0* Obj_002CBDC0::Init(int v)
{
    m0 = 2000;
    for (int i = 0; i < 32; i++)
        m4[i] = 0;
    m104 = v;
    D_00392940 = this;
    return this;
}
