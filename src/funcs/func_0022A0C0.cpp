struct Vec_0022A0C0 {
    float x, y, z, w;
};

struct Mat_0022A0C0 {
    float m[4][4];
    void Ident()
    {
        m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
        m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
        m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
        m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
    }
};

struct Quat_0022A0C0 {
    float x, y, z, w;
    Quat_0022A0C0() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; }
    void ToMatrix(Mat_0022A0C0* out)
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
};

extern "C" float sqrtf(float);
extern "C" int func_001E7FA8(void* params, unsigned int id, Vec_0022A0C0* out, int req);

void Get_0022A0C0(void* params, Mat_0022A0C0* m)
{
    Vec_0022A0C0 v;
    if (func_001E7FA8(params, 0xC97F3AA9, &v, 0)) {
        Quat_0022A0C0 q;
        q.x = v.x;
        q.y = v.y;
        q.z = v.z;
        q.w = sqrtf(1.0f - (v.x * v.x + v.y * v.y + v.z * v.z));
        q.ToMatrix(m);
    } else {
        m->Ident();
    }
}
