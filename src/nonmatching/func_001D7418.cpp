/* fuzzy: 88.8 */
typedef int qword_001D7418 __attribute__((mode(TI)));

struct Vec_001D7418 {
    union {
        struct { float x, y, z, w; };
        qword_001D7418 q;
    };
};

struct Rot_001D7418 {
    Vec_001D7418 row[3];
};

struct Mat_001D7418 {
    union {
        Vec_001D7418 row[4];
        Rot_001D7418 rot;
    };
};

struct Obj_001D7418 {
    char m_pad[0x20];
    Mat_001D7418 m_mat;
    Mat_001D7418 m_inv;
    void SetRotation(const Mat_001D7418* m);
};

void Obj_001D7418::SetRotation(const Mat_001D7418* m)
{
    m_mat.row[0] = m->row[0];
    m_mat.row[1] = m->row[1];
    m_mat.row[2] = m->row[2];
    Mat_001D7418* t = &m_inv;
    t->row[0].x = m_mat.row[0].x; t->row[0].y = m_mat.row[1].x; t->row[0].z = m_mat.row[2].x; t->row[0].w = m_mat.row[3].x;
    t->row[1].x = m_mat.row[0].y; t->row[1].y = m_mat.row[1].y; t->row[1].z = m_mat.row[2].y; t->row[1].w = m_mat.row[3].y;
    t->row[2].x = m_mat.row[0].z; t->row[2].y = m_mat.row[1].z; t->row[2].z = m_mat.row[2].z; t->row[2].w = m_mat.row[3].z;
    t->row[3].x = m_mat.row[0].w; t->row[3].y = m_mat.row[1].w; t->row[3].z = m_mat.row[2].w; t->row[3].w = m_mat.row[3].w;
}
