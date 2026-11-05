typedef int qword_002691A8 __attribute__((mode(TI)));

union Vec_002691A8 {
    qword_002691A8 q;
    struct {
        float x, y, z, w;
    } f;
};

struct Bone_002691A8 {
    char m_pad[0x10];
    Vec_002691A8 m10;
    Vec_002691A8 m20;
    Vec_002691A8 m_pos;
    char m_pad40[0x10];
    Bone_002691A8* m_parent;
    int m54;
    int m58;
    short m_id;
    char m_pad5E[0x60 - 0x5E];
};

extern "C" void func_002682E0(Vec_002691A8* a, Vec_002691A8* b, Vec_002691A8* c, Vec_002691A8* d);

struct Skel_002691A8 {
    char m_pad[0x50];
    Bone_002691A8* m_bones;
    char m_pad54[0x5C - 0x54];
    int m_numBones;
    void SetPos(int id, const Vec_002691A8* pos);
};

void Skel_002691A8::SetPos(int id, const Vec_002691A8* pos)
{
    for (int i = 0; i < m_numBones; i++) {
        Bone_002691A8* b = &m_bones[i];
        if (b->m_id == id) {
            b->m_pos = *pos;
            if (b->m_parent) {
                Vec_002691A8 a = b->m_pos;
                Vec_002691A8 p = b->m_parent->m_pos;
                func_002682E0(&a, &p, &b->m10, &b->m20);
            }
            if (b->m54) {
                for (int j = 0; j < m_numBones; j++) {
                    Bone_002691A8* c = &m_bones[i];
                    if (c->m_parent == b)
                        func_002682E0(&c->m_pos, &b->m_pos, &c->m10, &c->m20);
                }
            }
            return;
        }
    }
}
