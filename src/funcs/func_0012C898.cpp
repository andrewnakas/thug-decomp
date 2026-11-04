struct Src12C898 {
    char pad[0x18];
    int m18;
};

struct Obj12C898 {
    char pad[0x1C0];
    int m1C0;
    char pad2[0xC];
    int m1D0;
    void Attach(Src12C898** src);
};

void Obj12C898::Attach(Src12C898** src)
{
    m1C0 = (*src)->m18;
    m1D0 = 1;
}
