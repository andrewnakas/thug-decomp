struct Obj_001A9E98 {
    char pad[0x28];
    float m28;
    char pad2C[0x3C - 0x2C];
    float m3C;
    char pad40[0x4C - 0x40];
    int m4C;
    unsigned int m50;
    int Method(float* out);
};

int Obj_001A9E98::Method(float* out)
{
    float d = m28;
    if (out)
        *out = d;
    int r;
    if (m3C * m3C < d) {
        r = 0;
    } else {
        m50++;
        if (d > 640000.0f)
            r = (m50 % 4) == 0;
        else if ((d > 250000.0f) == false)
            r = 1;
        else
            r = m50 % 2;
    }
    if (m4C)
        return 1;
    return r;
}
