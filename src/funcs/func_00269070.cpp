extern "C" void func_0026B448(void* p, int a);
extern "C" void func_0026B460(void* p, int a);

struct Entry_00269070 {
    char pad[0x50];
    Entry_00269070* m50;
    char pad2[0x5C - 0x54];
    short m5C;
    char pad3[2];
};

static inline void Set_00269070(Entry_00269070* e, bool on)
{
    if (on)
        func_0026B448(e, 2);
    else
        func_0026B460(e, 2);
}

struct Obj_00269070 {
    char pad[0x50];
    Entry_00269070* m50;
    char pad2[0x5C - 0x54];
    int m5C;
    void Set(int id, int on, int chain);
};

void Obj_00269070::Set(int id, int on, int chain)
{
    for (int i = 0; i < m5C; i++) {
        Entry_00269070* e = &m50[i];
        if (e->m5C == id) {
            if (chain) {
                for (; e; e = e->m50)
                    Set_00269070(e, on);
            } else {
                Set_00269070(e, on);
            }
            return;
        }
    }
}
