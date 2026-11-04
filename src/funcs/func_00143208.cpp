struct Vec_00143208 {
    float x, y, z, w;
    Vec_00143208() {}
    Vec_00143208(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
    Vec_00143208& operator+=(const Vec_00143208& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }
};

static inline Vec_00143208 operator*(const Vec_00143208& v, float s)
{
    return Vec_00143208(v.x * s, v.y * s, v.z * s, v.w * s);
}

struct Mat_00143208;
extern "C" void func_00323318(Mat_00143208* d, const Mat_00143208* a, Mat_00143208* b);

struct Mat_00143208 {
    float m[4][4];
    Mat_00143208(const Vec_00143208& axis, float angle);
    Mat_00143208& operator*=(const Mat_00143208& o)
    {
        func_00323318(this, &o, this);
        return *this;
    }
    void Rotate(const Vec_00143208& axis, float angle)
    {
        Mat_00143208 r(axis, angle);
        *this *= r;
    }
    void Ident()
    {
        m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
        m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
        m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
        m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
    }
};

struct Sys_00143208 {
    Vec_00143208* m_pos;
    Vec_00143208* m_vel;
    int m8;
    Mat_00143208* m_mat;
    int m10;
    float m_gravity;
    float m_floor;
    float m_bounce;
    void Update(int i, float dt);
};

extern "C" int func_00335048();
extern "C" void func_003233B8(Vec_00143208* d, Vec_00143208* s);
extern float D_003875D8;

void Sys_00143208::Update(int i, float dt)
{
    m_pos[i] += m_vel[i] * dt;
    if (m_pos[i].y < m_floor) {
        if (m_vel[i].y < 0.0f) {
            m_pos[i].y = m_floor + (m_floor - m_pos[i].y);
            m_vel[i].y *= -m_bounce;
            float ax = (float)func_00335048() * 2.0f * 4.656613e-10f + -1.0f;
            float ay = (float)func_00335048() * 2.0f * 4.656613e-10f + -1.0f;
            float az = (float)func_00335048() * 2.0f * 4.656613e-10f + -1.0f;
            Vec_00143208 axis(ax, ay, az, 1.0f);
            func_003233B8(&axis, &axis);
            m_mat[i].Ident();
            m_mat[i].Rotate(axis, (float)func_00335048() * D_003875D8);
        }
    }
    m_vel[i].y -= m_gravity * dt;
}
