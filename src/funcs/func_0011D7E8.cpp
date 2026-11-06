struct Mat_0011D7E8 {
    float m[4][4];
};

struct Elem_0011D7E8 {
    int m0;
    int m4;
    Mat_0011D7E8* m_parentMat;
    int mC;
    int m_link;
    char pad14[0x30 - 0x14];
};

extern "C" int func_0011F4A8(void* sk);
extern "C" int func_0011F4F8(void* sk, int i);
extern "C" int func_0011F508(void* sk, int id);

class Pose_0011D7E8 {
public:
    unsigned int m_flags;
    Mat_0011D7E8* m_mats;
    void* m_skel;
    int pad0C;
    int m_10;
    int m_numBones;
    Elem_0011D7E8* m_elems;
    void LinkParents(void* sk);
};

void Pose_0011D7E8::LinkParents(void* sk)
{
    for (int i = 0; i < func_0011F4A8(sk); i++) {
        if (func_0011F4F8(sk, i)) {
            int p = func_0011F508(sk, func_0011F4F8(sk, i));
            m_elems[i].m_parentMat = &m_mats[p];
            m_elems[i].m_link = p;
            m_elems[p].m_link = i;
        }
    }
}
