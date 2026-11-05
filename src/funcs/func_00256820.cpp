struct Vec_00256820 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

extern Vec_00256820 D_00452120;

void Fn_00256820(int ok, int id)
{
    if (id == 0xFFFF && ok) {
        D_00452120.Set(0.0f, 0.0f, 0.0f, 1.0f);
    }
}
