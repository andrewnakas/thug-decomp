struct Ent_00253E68 {
    char pad[0x20];
    void* m20;
};

extern "C" bool func_00107728(void* p);

struct Obj_00253E68 {
    char pad[0x28];
    Ent_00253E68* m28[2];
    bool Fn();
};

bool Obj_00253E68::Fn()
{
    for (int i = 0; i < 2; i++) {
        if (func_00107728(m28[i]->m20)) return true;
    }
    return false;
}
