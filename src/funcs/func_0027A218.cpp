typedef int qword_0027A218 __attribute__((mode(TI)));

struct Vec_0027A218 {
    union {
        qword_0027A218 q;
        struct {
            float x, y, z, w;
        } f;
    };
    void Set(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

struct Mat_0027A218 {
    Vec_0027A218 row[4];
    void Identity()
    {
        row[0].f.x = 1.0f;
        row[0].f.y = 0.0f;
        row[0].f.z = 0.0f;
        row[0].f.w = 0.0f;
        row[1].f.x = 0.0f;
        row[1].f.y = 1.0f;
        row[1].f.z = 0.0f;
        row[1].f.w = 0.0f;
        row[2].f.x = 0.0f;
        row[2].f.y = 0.0f;
        row[2].f.z = 1.0f;
        row[2].f.w = 0.0f;
        row[3].f.x = 0.0f;
        row[3].f.y = 0.0f;
        row[3].f.z = 0.0f;
        row[3].f.w = 1.0f;
    }
    const Vec_0027A218& operator[](int i) const { return row[i]; }
    Mat_0027A218& operator=(const Mat_0027A218& o)
    {
        row[0] = o[0];
        row[1] = o[1];
        row[2] = o[2];
        row[3] = o[3];
        return *this;
    }
};

struct Body_0027A218 {
    char pad0[0x50];
    Vec_0027A218 m_vel;
    char pad60[0x10];
    Mat_0027A218 m_mat;
};

extern "C" float func_002032A0(unsigned int name, int a);

struct Obj_0027A218 {
    char pad0[0xC];
    Body_0027A218* m_body;
    char pad10[0x10];
    Mat_0027A218 m_mat;
    Vec_0027A218 m_up;
    Vec_0027A218 m_lastUp;
    Vec_0027A218 m_targetUp;
    char pad90[0x2E8];
    float m_378;

    void Reset();
};

void Obj_0027A218::Reset()
{
    m_378 = func_002032A0(0x78F80EC4, 0);
    m_body->m_vel.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m_body->m_mat.Identity();
    m_mat = m_body->m_mat;
    m_up.Set(0.0f, 1.0f, 0.0f, 1.0f);
    m_lastUp = m_up;
    m_targetUp = m_up;
}
