typedef int qword_00290238 __attribute__((mode(TI)));

union Vec_00290238 {
    qword_00290238 q;
    float c[4];
    Vec_00290238() {}
    Vec_00290238(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
};

struct Node_00290238 {
    int m0;
    int m4;
    int m8;
    Node_00290238* mC;
    Node_00290238* Valid() { return m4 != -1 ? this : 0; }
};

struct List_00290238 {
    char pad[0xC];
    Node_00290238* mC;
    int Count()
    {
        int n = 0;
        for (Node_00290238* x = mC->Valid(); x; x = x->mC->Valid())
            n++;
        return n;
    }
};

struct Mgr_00290238 {
    char pad[0x30];
    List_00290238 m30;
};

struct Body_00290238 {
    char pad[0x50];
    Vec_00290238 m50;
};

extern Mgr_00290238* D_0038FC78;
extern "C" Body_00290238* func_0022DE70(Mgr_00290238* m, int i);

struct Obj_00290238 {
    char pad[0xC];
    Body_00290238* mC;
    float Nearest();
};

float Obj_00290238::Nearest()
{
    float best = 2.8330837e13f;
    int n = D_0038FC78->m30.Count();
    for (int i = 0; i < n; i++) {
        Body_00290238* o = func_0022DE70(D_0038FC78, i);
        if (!o)
            continue;
        if (o == mC)
            continue;
        Vec_00290238 d(o->m50.c[0] - mC->m50.c[0], o->m50.c[1] - mC->m50.c[1], o->m50.c[2] - mC->m50.c[2], o->m50.c[3] - mC->m50.c[3]);
        float dd = d.c[0] * d.c[0] + d.c[1] * d.c[1] + d.c[2] * d.c[2];
        if (dd < best)
            best = dd;
    }
    return best;
}
