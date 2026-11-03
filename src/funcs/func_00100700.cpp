typedef int qword __attribute__((mode(TI)));

struct Vec {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec& operator*=(float s)
    {
        x *= s; y *= s; z *= s; w *= s;
        return *this;
    }
};

extern "C" void func_003233B8(Vec* dst, Vec* src);
extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);

extern "C" float* func_00100700(float* m, const Vec* axisIn, float angle)
{
    Vec axis;
    axis.q = axisIn->q;
    func_003233B8(&axis, &axis);
    float omc = 1.0f - func_00340F60(angle);
    Vec d;
    Vec o;
    d.x = 1.0f - axis.x * axis.x;
    d.y = 1.0f - axis.y * axis.y;
    d.z = 1.0f - axis.z * axis.z;
    o.x = axis.y * axis.z;
    o.y = axis.z * axis.x;
    o.z = axis.x * axis.y;
    d *= omc;
    o *= omc;
    axis *= func_00341068(angle);
    m[0] = 1.0f - d.x;
    m[1] = o.z + axis.z;
    m[2] = o.y - axis.y;
    m[3] = 0.0f;
    m[4] = o.z - axis.z;
    m[5] = 1.0f - d.y;
    m[6] = o.x + axis.x;
    m[7] = 0.0f;
    m[8] = o.y + axis.y;
    m[9] = o.x - axis.x;
    m[10] = 1.0f - d.z;
    m[11] = 0.0f;
    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;
    return m;
}
