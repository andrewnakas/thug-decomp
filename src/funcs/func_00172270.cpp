struct Obj_00172270 {
    char pad0[0x34];
    float* m34;
    void Fn(float a, float b, float c, float d, float e, float f, float g, float h);
};

void Obj_00172270::Fn(float a, float b, float c, float d, float e, float f, float g, float h)
{
    m34[0] = a;
    m34[1] = e;
    m34[2] = c;
    m34[3] = g;
    m34[4] = b;
    m34[5] = f;
    m34[6] = d;
    m34[7] = h;
}
