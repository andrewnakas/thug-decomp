extern "C" const float D_00388300[];
extern "C" float func_003414F0(float y, float x);

extern "C" float func_00100348(float y, float x)
{
    if (__builtin_fabsf(y) > __builtin_fabsf(x)) {
        return func_003414F0(y, x);
    }
    int xneg = 0;
    int yneg = 0;
    if (x < 0.0f) {
        x = -x;
        xneg = 1;
    }
    if (y <= D_00388300[0]) {
        y = -y;
        yneg = 1;
    }
    y = y / x;
    float z = (y - 1.0f) / (y + 1.0f);
    float z2 = z * z;
    float r = z * -0.004054057878f;
    r = r * z2 + z * 0.02186122909f;
    r = r * z2 + z * -0.05590988696f;
    r = r * z2 + z * 0.09642004222f;
    r = r * z2 + z * -0.1390853375f;
    r = r * z2 + z * 0.1994653642f;
    r = r * z2 + z * -0.333298564f;
    r = r * z2 + z * 0.9999993443f;
    if (xneg) {
        if (yneg) {
            return (r + 0.7853981853f) - 3.141592741f;
        }
        return 2.356194496f - r;
    }
    if (yneg) {
        return -0.7853981853f - r;
    }
    return r + 0.7853981853f;
}
