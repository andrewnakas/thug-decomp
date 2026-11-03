extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);
extern "C" int func_001D7F30(void* self);

struct Mesh_001D7610 {
    int m0;
    int m4;
    unsigned char m8;
    unsigned char m9;
    unsigned char m_shared;
    unsigned char mB;
    void* mC;
    char m_pad[0x30 - 0x10];
    void* m30;
    int m34;
    void* m38;
    ~Mesh_001D7610();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Mesh_001D7610::~Mesh_001D7610()
{
    if (m30) {
        func_0010A8D8(D_00388A70, m30);
    }
    if (m38) {
        func_0010A8D8(D_00388A70, m38);
    }
    if (mC) {
        if (m_shared) {
            func_0010A8D8(D_00388A70, mC);
        } else {
            func_0010A8D8(D_00388A70, mC);
        }
    }
    func_001D7F30(this);
}
