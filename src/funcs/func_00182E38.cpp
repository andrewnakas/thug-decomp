struct Link_00182E38 {
    char pad[0xC];
    Link_00182E38* mC;
    Link_00182E38* m10;
};
struct Obj_00182E38 {
    char pad[8];
    Link_00182E38 m8;
    void Add(Link_00182E38* o);
};

void Obj_00182E38::Add(Link_00182E38* o)
{
    Link_00182E38* n = o->m10;
    Link_00182E38* h = &m8;
    n->m10 = h->m10;
    n->mC = h;
    h->m10->mC = n;
    h->m10 = n;
}
