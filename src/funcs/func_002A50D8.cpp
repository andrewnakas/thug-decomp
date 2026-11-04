extern char D_00371C78[];
extern char D_003714C0[];

struct Iter_002A50D8 {
    int m0;
    int m4;
    void* m8;
    Iter_002A50D8() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A50D8() { m8 = D_00371C78; }
};

struct Iter2_002A50D8 {
    int m0;
    int m4;
    void* m8;
    Iter2_002A50D8() { m8 = D_003714C0; m4 = 0; }
    ~Iter2_002A50D8() { m8 = D_003714C0; }
};

struct Info_002A50D8 {
    char pad[0x18];
    int m18;
};

struct Skater_002A50D8 {
    char pad[0x18];
    Info_002A50D8* m18;
};

struct Obs_002A50D8 {
    char pad[0x11];
    signed char m11;
    char pad2[0x20 - 0x12];
    int m20;
};

struct Obj_002A50D8 {
    int FreeId();
};

extern "C" Skater_002A50D8* func_002A53F8(Obj_002A50D8* self, Iter_002A50D8* it, int a);
extern "C" Skater_002A50D8* func_002A5490(Obj_002A50D8* self, Iter_002A50D8* it, int a);
extern "C" Obs_002A50D8* func_002A5520(Obj_002A50D8* self, Iter2_002A50D8* it);
extern "C" Obs_002A50D8* func_002A5558(Obj_002A50D8* self, Iter2_002A50D8* it);

int Obj_002A50D8::FreeId()
{
    Iter_002A50D8 it;
    Iter2_002A50D8 it2;
    for (int id = 0; id < 16; id++) {
        bool used = false;
        for (Skater_002A50D8* p = func_002A53F8(this, &it, 0); p; p = func_002A5490(this, &it, 0)) {
            if (p->m18->m18 == id) {
                used = true;
                break;
            }
        }
        if (used) continue;
        for (Obs_002A50D8* q = func_002A5520(this, &it2); q; q = func_002A5558(this, &it2)) {
            if ((q->m20 & 0xC) != 4 && q->m11 == id) {
                used = true;
                break;
            }
        }
        if (!used) return id;
    }
    return 16;
}
