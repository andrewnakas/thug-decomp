struct P_00266158 {
    int m0;
    int m4;
};

struct C_00266158;
extern "C" int func_00265210(C_00266158* self, int v);

struct C_00266158 {
    int m0;
    void Add(P_00266158* p);
};

void C_00266158::Add(P_00266158* p)
{
    p->m0 += func_00265210(this, p->m4);
}
