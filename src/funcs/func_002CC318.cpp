struct Ent_002CC318 {
    char pad[0x14];
    int m14[2];
    int Get(int k) { return m14[k]; }
};

struct Mgr_002CC318 {
    int m0;
    Ent_002CC318* m4[32];
    int m84[32];
    bool Find(int id, int* out);
};

bool Mgr_002CC318::Find(int id, int* out)
{
    for (int i = 0; i < 32; i++) {
        Ent_002CC318* e = m4[i];
        if (e && e->Get(!m84[i]) == id) {
            if (out)
                *out = i;
            return true;
        }
    }
    return false;
}
