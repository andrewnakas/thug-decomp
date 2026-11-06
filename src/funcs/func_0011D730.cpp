extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Elem_0011D730 {
public:
    char m_data[0x30];
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

class Mat_0011D730 {
public:
    float m[4][4];
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

class Pose_0011D730 {
public:
    unsigned int m_flags;
    Mat_0011D730* m_mats;
    void* m_skel;
    int pad0C;
    int m_10;
    int m_numBones;
    Elem_0011D730* m_elems;
    ~Pose_0011D730();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Pose_0011D730::~Pose_0011D730()
{
    if (m_elems) {
        delete[] m_elems;
    }
    if (m_mats) {
        delete[] m_mats;
    }
}
