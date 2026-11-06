struct Mat_0026B350 {
    float m[4][4];
};

struct Quat_0026B350 {
    float x, y, z, w;
    void ToMatrix(Mat_0026B350* out);
};

void Quat_0026B350::ToMatrix(Mat_0026B350* out)
{
    float s = x * x + y * y + z * z + w * w;
    s = (s > 0.0f) ? 2.0f / s : 0.0f;
    float xs = x * s;
    float ys = y * s;
    float zs = z * s;
    float wx = w * xs;
    float wy = w * ys;
    float wz = w * zs;
    float xx = x * xs;
    float xy = x * ys;
    float xz = x * zs;
    float yy = y * ys;
    float yz = y * zs;
    float zz = z * zs;
    out->m[0][0] = 1.0f - (yy + zz);
    out->m[1][0] = xy + wz;
    out->m[2][0] = xz - wy;
    out->m[0][1] = xy - wz;
    out->m[1][1] = 1.0f - (xx + zz);
    out->m[2][1] = yz + wx;
    out->m[0][2] = xz + wy;
    out->m[1][2] = yz - wx;
    out->m[2][2] = 1.0f - (xx + yy);
}
