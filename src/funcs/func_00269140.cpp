extern "C" int func_001CB7B8(void* p, int a);

struct Entry_00269140 {
    char pad[0x5C];
    short m5C;
    char pad2[2];
};

struct Obj_00269140 {
    char pad[0x50];
    Entry_00269140* m50;
    char pad2[0x5C - 0x54];
    int m5C;
    int Run(int id);
};

int Obj_00269140::Run(int id)
{
    for (int i = 0; i < m5C; i++) {
        Entry_00269140* e = &m50[i];
        if (e->m5C == id)
            return func_001CB7B8(e, 2);
    }
    return 0;
}
