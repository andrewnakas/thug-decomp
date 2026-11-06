struct Ent_0013C380 {
    int m0;
    int m_mode;
    int m8;
    int mC;
};

class Pool_0013C380 {
public:
    int m0[5];
    virtual void V0();
    virtual void V1();
    virtual Ent_0013C380* Alloc(int fast, int size);
    Ent_0013C380* Get(int fast, int size);
};

Ent_0013C380* Pool_0013C380::Get(int fast, int size)
{
    Ent_0013C380* e = Alloc(fast, size);
    if (e) {
        e->mC = 0;
        e->m_mode = fast ? 1 : 2;
    }
    return e;
}
