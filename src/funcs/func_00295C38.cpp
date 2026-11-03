struct Entry_00295C38 {
    int m0;
    char pad[0x2A1];
    unsigned char m2A5;
    char pad2[0x350 - 0x2A6];
};
extern "C" int func_00291EC0();
extern "C" int func_00292748(Entry_00295C38*);

struct Obj_00295C38 {
    char pad0[0x20];
    Entry_00295C38 m20[50];
    Entry_00295C38* Find(int id);
};

Entry_00295C38* Obj_00295C38::Find(int id)
{
    int key = func_00291EC0();
    Entry_00295C38* e = m20;
    for (int i = 0; i < 50; i++, e++) {
        if (e->m2A5 && e->m0 == key && func_00292748(e) == id) return e;
    }
    return 0;
}
