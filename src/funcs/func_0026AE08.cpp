extern void* D_0038FC78;
extern char D_003761E8[];
extern char D_003761F8[];
extern char D_00391218[];
extern char D_00391220[];
extern "C" void* func_001E9378(void* a, int i);
extern "C" int func_0022EEC0(void* mgr, void* p);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_0010BDE0(int size);
extern "C" void func_0010BEB8(void* p);
extern "C" void func_002684B8(void* self, int index, void* params);
extern "C" bool func_001E86D0(void* params, const char* name);
extern "C" int func_001E5648(char* name, int a);
extern "C" bool func_001E8A50(void* params, const char* name, unsigned int* out, int required);
extern "C" void* func_0022E048(void* p);
extern "C" void func_00265F58(void* self, unsigned int a);
extern "C" void func_00266070(void* self, unsigned int a, unsigned int b);
extern "C" void func_00268420(void* self, void* a, void* b);

struct Array_0026AE08 {
    char pad[0xC];
    unsigned int mC;
};

struct Entry_0026AE08 {
    char pad[0x5C];
    short m5C;
    char pad2[2];
};

struct Links_0026AE08 {
    short m[4];
};

struct Obj_0026AE08 {
    char pad[0x50];
    Entry_0026AE08* m50;
    Links_0026AE08* m54;
    Array_0026AE08* m58;
    int m5C;
    int m60;
    void Init(Array_0026AE08* arr);
};

void Obj_0026AE08::Init(Array_0026AE08* arr)
{
    void* mgr = D_0038FC78;
    unsigned int i;
    int k;
    Entry_0026AE08* e;
    m58 = arr;
    m5C = 0;
    for (i = 0; i < arr->mC; i++) {
        void* p = func_001E9378(arr, i);
        if (func_0022EEC0(mgr, p))
            continue;
        unsigned int type = 0;
        func_001E8398(p, 0x12B4E660, &type, 0);
        if (type == 0x8E6B02AD || type == 0x30C19600)
            m5C++;
    }
    if (!m5C)
        return;
    m50 = (Entry_0026AE08*)func_0010BDE0(m5C * 0x60);
    m54 = (Links_0026AE08*)func_0010BDE0(m5C * 8);
    m60 = 0;
    for (i = 0; i < arr->mC; i++) {
        void* p = func_001E9378(arr, i);
        if (func_0022EEC0(mgr, p))
            continue;
        unsigned int type = 0;
        func_001E8398(p, 0x12B4E660, &type, 0);
        if (type == 0x8E6B02AD || type == 0x30C19600) {
            func_002684B8(this, i, p);
            int create = func_001E86D0(p, D_003761E8);
            if (func_001E5648(D_003761F8, 0))
                create = 1;
            if (create) {
                unsigned int name;
                func_001E8A50(p, D_00391218, &name, 1);
                unsigned int cluster = name;
                func_001E8A50(p, D_00391220, &cluster, 1);
                func_00265F58(func_0022E048(mgr), cluster);
                func_00266070(func_0022E048(mgr), name, cluster);
            }
        }
    }
    int n = arr->mC;
    Entry_0026AE08** table = (Entry_0026AE08**)func_0010BDE0(n * 4);
    for (k = 0; k < n; k++)
        table[k] = 0;
    for (k = 0; k < m5C; k++) {
        e = &m50[k];
        table[e->m5C] = e;
    }
    for (int k2 = 0; k2 < m5C; k2++) {
        e = &m50[k2];
        for (int j = 0; j < 4; j++) {
            short l = m54[k2].m[j];
            if (l != -1)
                func_00268420(this, e, table[l]);
        }
    }
    func_0010BEB8(table);
    func_0010BEB8(m54);
    m54 = 0;
}
