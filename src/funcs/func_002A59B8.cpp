extern char D_00371C78[];
extern void* D_0038FC78;

struct Iter_002A59B8 {
    int m0;
    int m4;
    void* m8;
    Iter_002A59B8() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A59B8() { m8 = D_00371C78; }
};

struct Elem_002A59B8 {
    char pad[0x18];
    int m18;
};

struct Obj_002A59B8;
extern "C" Elem_002A59B8* func_002A53F8(Obj_002A59B8* o, Iter_002A59B8* it, int f);
extern "C" Elem_002A59B8* func_002A5490(Obj_002A59B8* o, Iter_002A59B8* it, int f);
extern "C" int func_002B2280(Elem_002A59B8* e);
extern "C" void func_002A5A88(Obj_002A59B8* o, Elem_002A59B8* e, int k);
extern "C" void func_0022CF98(void* g, int id);

struct Obj_002A59B8 {
    void RemoveAll();
};

void Obj_002A59B8::RemoveAll()
{
    void* g = D_0038FC78;
    Iter_002A59B8 it;
    Elem_002A59B8* e = func_002A53F8(this, &it, 0);
    while (e) {
        Elem_002A59B8* nx = func_002A5490(this, &it, 0);
        if (!func_002B2280(e)) {
            int id = e->m18;
            func_002A5A88(this, e, 6);
            func_0022CF98(g, id);
        }
        e = nx;
    }
}
