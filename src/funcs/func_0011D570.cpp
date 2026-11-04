extern int D_00388A70;
extern "C" void* func_0010A638(int heap, unsigned int size, int, int);

class Elem_0011D570 {
public:
    Elem_0011D570();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    char m_data[0x30];
};

class Mat_0011D570 {
public:
    Mat_0011D570() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    void Ident()
    {
        m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
        m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
        m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
        m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
    }
    float m[4][4];
};

struct Skel_0011D570 {
    char pad0[0x490];
    unsigned int m_flags;
};

struct Pose_0011D570 {
    unsigned int m_flags;
    Mat_0011D570* m_mats;
    Skel_0011D570* m_skel;
    int pad0C;
    int m_10;
    int m_numBones;
    Elem_0011D570* m_elems;
};

extern "C" int func_0011F4A8(Skel_0011D570* sk);
extern "C" void func_0011D960(Pose_0011D570* self, Skel_0011D570* sk);
extern "C" void func_0011D8B8(Pose_0011D570* self, Skel_0011D570* sk);
extern "C" void func_0011D7E8(Pose_0011D570* self, Skel_0011D570* sk);

extern "C" Pose_0011D570* func_0011D570(Pose_0011D570* self, Skel_0011D570* sk)
{
    self->m_flags = 0;
    if (sk->m_flags & 1) {
        self->m_flags = 0x10000000;
    }
    self->m_elems = new Elem_0011D570[func_0011F4A8(sk)];
    Mat_0011D570* mats = new Mat_0011D570[func_0011F4A8(sk)];
    self->m_mats = mats;
    for (int i = 0; i < func_0011F4A8(sk); i++) {
        mats[i].Ident();
    }
    self->m_numBones = func_0011F4A8(sk);
    func_0011D960(self, sk);
    func_0011D8B8(self, sk);
    func_0011D7E8(self, sk);
    self->m_skel = sk;
    self->m_10 = 0x1F;
    return self;
}
