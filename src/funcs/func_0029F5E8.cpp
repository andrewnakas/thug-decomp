extern char D_00371C78[];
extern void* D_0038FC78;

struct Iter_0029F5E8 {
    int m0;
    int m4;
    void* m8;
    Iter_0029F5E8() { m8 = D_00371C78; m4 = 0; }
    ~Iter_0029F5E8() { m8 = D_00371C78; }
};

struct Elem_0029F5E8 {
    char pad[0x18];
    void* m18;
};

extern "C" Elem_0029F5E8* func_002A53F8(void* self, Iter_0029F5E8* it, int a);
extern "C" Elem_0029F5E8* func_002A5490(void* self, Iter_0029F5E8* it, int a);
extern "C" int func_002041F8(void* p);
extern "C" int func_002B1FC8(Elem_0029F5E8* e);
extern "C" void func_0022CF98(void* q, void* p);
extern "C" void func_002A47D8(void* self, Elem_0029F5E8* e);

struct Table_0029F5E8 {
    int m0;
    void Purge();
};

void Table_0029F5E8::Purge()
{
    void* q = D_0038FC78;
    Iter_0029F5E8 it;
    Elem_0029F5E8* e = func_002A53F8(this, &it, 1);
    while (e) {
        Elem_0029F5E8* next = func_002A5490(this, &it, 1);
        if (e->m18 && (func_002041F8(e->m18) || !func_002B1FC8(e)))
            func_0022CF98(q, e->m18);
        func_002A47D8(this, e);
        e = next;
    }
}
