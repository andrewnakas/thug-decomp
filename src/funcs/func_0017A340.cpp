struct Entry_0017A340 {
    char pad0[0x3C];
    unsigned int* m3C;
    int m40;
    unsigned int m44;
};

struct List_0017A340 {
    char pad0[0x18];
    int m18;
    char pad1C[8];
    Entry_0017A340* m24;
};

struct Obj_0017A340 {
    char pad0[0x84];
    void* m84;
};

extern "C" Obj_0017A340* func_00131E48();
extern "C" List_0017A340* func_00149BC8(void* p);

extern "C" void func_0017A340()
{
    Obj_0017A340* obj = func_00131E48();
    if (!obj || !obj->m84) {
        return;
    }
    List_0017A340* list = func_00149BC8(obj->m84);
    Entry_0017A340* e = list->m24;
    int n = list->m18;
    for (int i = 0; i < n; i++) {
        unsigned int* p = e[i].m3C;
        if (e[i].m40) {
            e[i].m40 = 0;
            if (*p == 0) {
                *p = e[i].m44;
                *(unsigned int*)(((unsigned int)p + 0x13) & 0xFFFFFFF0) = e[i].m44 | 0x30000000;
            }
        } else if (*p) {
            *p = 0;
            *(unsigned int*)(((unsigned int)p + 0x13) & 0xFFFFFFF0) = 0x30000000;
        }
    }
}
