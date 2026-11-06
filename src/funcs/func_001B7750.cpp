typedef int qword __attribute__((mode(TI)));
union Vec_001B7750 { qword q; float c[4];
    Vec_001B7750& operator=(const Vec_001B7750& o) { q = o.q; return *this; } };
struct Mat_001B7750 { Vec_001B7750 r[4];
    Mat_001B7750& operator=(const Mat_001B7750& o) { r[0] = o.r[0]; r[1] = o.r[1]; r[2] = o.r[2]; r[3] = o.r[3]; return *this; } };
struct Node_001B7750 { char pad[0x50]; Vec_001B7750 m_pos; char pad2[0x10]; Mat_001B7750 m_rot; };
struct Src_001B7750 { char pad[0xC]; Node_001B7750* m_C; char pad2[0xC]; void* m_1C; };
extern "C" void func_002695B8(void* p, Mat_001B7750* m);

Mat_001B7750 GetXform_001B7750(Src_001B7750* s)
{
    Node_001B7750* n = s->m_C;
    Mat_001B7750 m;
    m = n->m_rot;
    m.r[0].c[3] = 0.0f;
    m.r[1].c[3] = 0.0f;
    m.r[2].c[3] = 0.0f;
    m.r[3] = n->m_pos;
    m.r[3].c[3] = 1.0f;
    func_002695B8(s->m_1C, &m);
    return m;
}
