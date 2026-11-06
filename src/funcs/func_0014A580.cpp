extern void* D_0038BDB8;

struct Obj_0014A580 {
    int m0[2];
    void* m_8;
    void Select(int on);
};

void Obj_0014A580::Select(int on)
{
    void* p = 0;
    if (on)
        p = m_8;
    D_0038BDB8 = p;
}
