extern char D_003940B0[8];

struct Obj_0017F1A8 {
    int m0[4];
    void* m_10;
    void Set(void* p);
};

void Obj_0017F1A8::Set(void* p)
{
    if (p)
        m_10 = p;
    else
        m_10 = D_003940B0;
}
