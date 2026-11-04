extern float D_0038757C;

struct Obj12B6F8 {
    char pad[0x1BC];
    float m1BC;
    bool Get(float* out);
};

bool Obj12B6F8::Get(float* out)
{
    float t = D_0038757C;
    *out = m1BC;
    return t < m1BC;
}
