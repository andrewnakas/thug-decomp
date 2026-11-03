extern char D_00371C78[];

struct Iter_002A56E0 {
    int m0;
    int m4;
    void* m8;
    Iter_002A56E0() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A56E0() { m8 = D_00371C78; }
};

extern "C" void* func_002A53F8(void* self, Iter_002A56E0* it, int a);
extern "C" void* func_002A5490(void* self, Iter_002A56E0* it, int a);
extern "C" int func_002B1FC8(void* item);

struct Table_002A56E0 {
    int m0;
    void* Find();
};

void* Table_002A56E0::Find() {
    Iter_002A56E0 it;
    for (void* p = func_002A53F8(this, &it, 1); p; p = func_002A5490(this, &it, 1)) {
        if (func_002B1FC8(p)) {
            return p;
        }
    }
    return 0;
}
