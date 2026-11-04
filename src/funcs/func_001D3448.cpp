struct Target {
    int m0;
};

struct Linked {
    int m0;
    int m4;
    Target* m8;
    void Set(int v);
};

void Linked::Set(int v)
{
    m0 = v;
    if (m8) {
        m8->m0 = v;
    }
}
