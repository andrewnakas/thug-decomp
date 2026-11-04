struct Vec_00298478 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Obj_00298478 {
    char pad[0x10];
    Vec_00298478 m10;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    Obj_00298478* Init();
};

Obj_00298478* Obj_00298478::Init()
{
    m10.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2C = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    return this;
}
