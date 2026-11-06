/* fuzzy: 85.0 */
typedef int qword_001D7350 __attribute__((mode(TI)));

struct Vec_001D7350 {
    union {
        struct { float x, y, z, w; };
        qword_001D7350 q;
    };
};

struct Mat_001D7350 {
    Vec_001D7350 row[4];
    void SetRot(const Mat_001D7350& m)
    {
        row[0] = m.row[0];
        row[1] = m.row[1];
        row[2] = m.row[2];
    }
    void Transpose(const Mat_001D7350& m)
    {
        row[0].x = m.row[0].x; row[0].y = m.row[1].x; row[0].z = m.row[2].x; row[0].w = m.row[3].x;
        row[1].x = m.row[0].y; row[1].y = m.row[1].y; row[1].z = m.row[2].y; row[1].w = m.row[3].y;
        row[2].x = m.row[0].z; row[2].y = m.row[1].z; row[2].z = m.row[2].z; row[2].w = m.row[3].z;
        row[3].x = m.row[0].w; row[3].y = m.row[1].w; row[3].z = m.row[2].w; row[3].w = m.row[3].w;
    }
};

struct Obj_001D7350 {
    char m_pad[0x20];
    Mat_001D7350 m_mat;
    Mat_001D7350 m_inv;
    void Set(const Mat_001D7350& m);
};

void Obj_001D7350::Set(const Mat_001D7350& m)
{
    m_mat.row[0] = m.row[0];
    m_mat.row[1] = m.row[1];
    m_mat.row[2] = m.row[2];
    Mat_001D7350* t = &m_inv;
    t->row[0].x = m_mat.row[0].x; t->row[0].y = m_mat.row[1].x; t->row[0].z = m_mat.row[2].x; t->row[0].w = m_mat.row[3].x;
    t->row[1].x = m_mat.row[0].y; t->row[1].y = m_mat.row[1].y; t->row[1].z = m_mat.row[2].y; t->row[1].w = m_mat.row[3].y;
    t->row[2].x = m_mat.row[0].z; t->row[2].y = m_mat.row[1].z; t->row[2].z = m_mat.row[2].z; t->row[2].w = m_mat.row[3].z;
    t->row[3].x = m_mat.row[0].w; t->row[3].y = m_mat.row[1].w; t->row[3].z = m_mat.row[2].w; t->row[3].w = m_mat.row[3].w;
}
