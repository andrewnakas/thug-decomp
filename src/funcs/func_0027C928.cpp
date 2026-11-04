typedef int qword_0027C928 __attribute__((mode(TI)));

struct Vec_0027C928 {
    union {
        qword_0027C928 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec_0027C928() {}
    Vec_0027C928(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

struct Mat_0027C928 {
    Vec_0027C928 row[4];
    const Vec_0027C928& operator[](int i) const { return row[i]; }
    Mat_0027C928& operator=(const Mat_0027C928& o)
    {
        row[0] = o[0];
        row[1] = o[1];
        row[2] = o[2];
        row[3] = o[3];
        return *this;
    }
};

struct Body_0027C928 {
    char pad0[0x70];
    Mat_0027C928 m_mat;
};

struct Obj_0027C928 {
    char pad0[0xC];
    Body_0027C928* m_body;
    char pad10[0x10];
    Mat_0027C928 m_mat;
    char pad60[0x350];
    bool m_flipped;

    void Flip();
};

void Obj_0027C928::Flip()
{
    m_body->m_mat.row[2] = Vec_0027C928(-m_body->m_mat.row[2].f.x, -m_body->m_mat.row[2].f.y, -m_body->m_mat.row[2].f.z,
                                        -m_body->m_mat.row[2].f.w);
    m_body->m_mat.row[0] = Vec_0027C928(-m_body->m_mat.row[0].f.x, -m_body->m_mat.row[0].f.y, -m_body->m_mat.row[0].f.z,
                                        -m_body->m_mat.row[0].f.w);
    m_mat = m_body->m_mat;
    m_flipped = !m_flipped;
}
