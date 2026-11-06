struct Mat_0011D8B8 {
    float m[4][4];
};

struct Elem_0011D8B8 {
    int m0;
    Mat_0011D8B8* m_mat;
    int m8;
    int mC;
    char pad10[0x30 - 0x10];
};

extern "C" int func_0011F4A8(void* sk);
extern "C" int func_0011F4C0(void* sk, int i);
extern "C" int func_0011F4D0(void* sk, int i);

class Pose_0011D8B8 {
public:
    unsigned int m_flags;
    Mat_0011D8B8* m_mats;
    void* m_skel;
    int pad0C;
    int m_10;
    int m_numBones;
    Elem_0011D8B8* m_elems;
    void LinkMats(void* sk);
};

void Pose_0011D8B8::LinkMats(void* sk)
{
    for (int i = 0; i < func_0011F4A8(sk); i++) {
        int b;
        if (!func_0011F4C0(sk, i)) {
            b = 0;
        } else {
            b = func_0011F4D0(sk, i);
        }
        Elem_0011D8B8* e = &m_elems[i];
        Mat_0011D8B8* m = &m_mats[b];
        e->mC = 0;
        e->m_mat = m;
    }
}
