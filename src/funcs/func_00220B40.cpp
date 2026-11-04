struct Node_00220B40 {
    int m0;
    int m4;
    int m8;
    Node_00220B40* mC;
    Node_00220B40* Valid() { if (~m4 == 0) return 0; return this; }
    unsigned int Count()
    {
        unsigned int c = 0;
        for (Node_00220B40* n = mC->Valid(); n; n = n->mC->Valid()) c++;
        return c;
    }
};

struct Mgr_00220B40 {
    char pad0[0x30];
    Node_00220B40 m30;
};

struct Obj_00220B40 {
    char pad0[0x31C];
    int m31C;
};

extern Mgr_00220B40* D_0038FC78;
extern "C" Obj_00220B40* func_0022DE70(Mgr_00220B40* m, unsigned int i);
extern "C" void* func_00203360(Obj_00220B40* o);
extern "C" int func_002392B8(void* x);
extern "C" void func_00239198(void* x, int v);

bool Cmd_00220B40(void* params, void* script)
{
    Mgr_00220B40* m = D_0038FC78;
    for (unsigned int i = 0; i < m->m30.Count(); i++) {
        Obj_00220B40* o = func_0022DE70(m, i);
        if (o->m31C) {
            void* x = func_00203360(o);
            func_00239198(x, func_002392B8(x));
        }
    }
    return true;
}
