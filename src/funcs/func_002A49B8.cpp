extern char D_00371C78[];

struct Iter_002A49B8 {
    int m0;
    int m4;
    void* m8;
    Iter_002A49B8() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A49B8() { m8 = D_00371C78; }
};

extern "C" void* func_002A53F8(void* self, Iter_002A49B8* it, int a);
extern "C" void* func_002A5490(void* self, Iter_002A49B8* it, int a);

struct Obj_002A49B8 {
    char pad[0x1A8];
    void* m1A8;
    void* GetNext();
};

void* Obj_002A49B8::GetNext()
{
    Iter_002A49B8 it;
    void* p;
    for (p = func_002A53F8(this, &it, 0); p; p = func_002A5490(this, &it, 0)) {
        if (!m1A8)
            break;
        if (p == m1A8) {
            p = func_002A5490(this, &it, 0);
            if (!p)
                p = func_002A53F8(this, &it, 0);
            break;
        }
    }
    return p;
}
