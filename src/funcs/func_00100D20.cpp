typedef int qword __attribute__((mode(TI)));

struct Vec_00100D20 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00100D20() {}
    Vec_00100D20(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

extern "C" Vec_00100D20* func_00100D20(Vec_00100D20* m, float w, float h, float zn, float zf)
{
    float d = zf - zn;
    m[0] = Vec_00100D20(2.0f / w, 0.0f, 0.0f, 0.0f);
    m[1] = Vec_00100D20(0.0f, 2.0f / h, 0.0f, 0.0f);
    m[2] = Vec_00100D20(0.0f, 0.0f, 2.0f / d, 0.0f);
    m[3] = Vec_00100D20(0.0f, 0.0f, -(zf + zn) / d, 1.0f);
    return m;
}
