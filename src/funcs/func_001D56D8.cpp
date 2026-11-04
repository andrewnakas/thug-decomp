struct Vec_001D56D8 {
    float x, y, z, w;
    Vec_001D56D8() {}
    Vec_001D56D8(float nx, float ny, float nz, float nw)
    {
        x = nx;
        y = ny;
        z = nz;
        w = nw;
    }
};

class Base_001D56D8 {
public:
    char pad0[8];
    void* m_tree;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual const Vec_001D56D8* GetOrigin();

    void Query(const Vec_001D56D8* p);
};

extern "C" void func_001D83A0(void* tree, Vec_001D56D8* p);

void Base_001D56D8::Query(const Vec_001D56D8* p)
{
    const Vec_001D56D8* o = GetOrigin();
    Vec_001D56D8 d(p->x - o->x, p->y - o->y, p->z - o->z, p->w - o->w);
    func_001D83A0(m_tree, &d);
}
