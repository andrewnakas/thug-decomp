struct Rec_0029A3B8 {
    short x, y, z;
    unsigned short t;
    unsigned short flag;
};

struct Node_0029A3B8 {
    char pad[0x10];
    float x, y, z;
    char pad2[0x20 - 0x1C];
    int on;
    int pad3;
    float t;
};

struct Obj_0029A3B8;
extern "C" void func_0029B290(Obj_0029A3B8* o);
extern "C" void* func_0029B378(Obj_0029A3B8* o);
extern "C" Node_0029A3B8* func_00299830(void* g);

struct Obj_0029A3B8 {
    char pad[0x38];
    unsigned short count;
    unsigned short sizes[(0x1CA - 0x3A) / 2];
    Rec_0029A3B8 recs[1];
    void Load();
};

void Obj_0029A3B8::Load()
{
    unsigned short* sz = sizes;
    Rec_0029A3B8* r = recs;
    func_0029B290(this);
    unsigned int n = count;
    for (unsigned int i = 0; i < n; i++) {
        unsigned int m = *sz;
        void* g = func_0029B378(this);
        sz++;
        for (unsigned int j = 0; j < m; j++, r++) {
            Node_0029A3B8* nd = func_00299830(g);
            if (nd) {
                nd->on = r->flag != 0;
                nd->t = r->t * 0.0625f;
                nd->x = r->x * 0.125f;
                nd->y = r->y * 0.125f;
                nd->z = r->z * 0.125f;
            }
        }
    }
}
