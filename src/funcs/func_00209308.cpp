struct Vec_00209308 {
    float x, y, z, w;
    void Set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};
struct Obj_00209308 {
    char pad[0x20];
    int m20;
    char pad24[0x30 - 0x24];
    Vec_00209308 m30;
    Vec_00209308 m40;
    char pad50[0x64 - 0x50];
    short m64;
    short m66;
    char pad68[0xD4 - 0x68];
    int mD4;
    void Init();
};

void Obj_00209308::Init()
{
    m64 = 16;
    m66 = 0;
    m20 = 0;
    mD4 = 0;
    m30.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m40.Set(0.0f, 0.0f, 0.0f, 1.0f);
}
