class Prim_0017F410 {
public:
    int m0;
    int m4;
    float m8;
    unsigned int mC;
    int* m10;
    Prim_0017F410* m_next;

    virtual ~Prim_0017F410();
    virtual void SetHidden(int hidden);
    virtual void Begin() = 0;
    virtual void Draw() = 0;
    virtual void End() = 0;
};

extern "C" void func_0017F410(Prim_0017F410* p)
{
    while (p) {
        if (!p->m0) {
            p->Begin();
            p->Draw();
            p->End();
        }
        p = p->m_next;
    }
}
