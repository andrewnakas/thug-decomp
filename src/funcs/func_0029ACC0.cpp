struct Node_0029ACC0 {
    char pad[0x10];
    float x, y, z;
    char pad2[0x2C - 0x1C];
    Node_0029ACC0* next;
    char pad3[0x38 - 0x30];
    int m38;
};

struct Grp_0029ACC0 {
    int m0;
    Grp_0029ACC0* next;
    int m8;
    Node_0029ACC0* head;
};

struct Obj_0029ACC0;
extern "C" int func_0029B468(Obj_0029ACC0* o);
extern "C" int func_00299898(Grp_0029ACC0* g);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E7410(void* s, unsigned int name, float x, float y, float z);
extern "C" void func_001E7360(void* s, int a, unsigned int name);
extern "C" void func_001E9170(void* arr, int i, void* s);
extern "C" void func_001E7720(void* s, unsigned int name, void* arr);

struct Obj_0029ACC0 {
    char pad[0x24];
    Grp_0029ACC0* m24;
    void Save(void* out);
};

void Obj_0029ACC0::Save(void* out)
{
    int gi = 0;
    int cnt = func_0029B468(this);
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, cnt, 10);
    for (Grp_0029ACC0* g = m24; g; g = g->next) {
        int j = 0;
        void* gs = func_001E6978(func_001190D0(8));
        int n = func_00299898(g);
        void* narr = func_001E8DD0(func_00122CF8(0x10));
        func_001E8E98(narr, n, 10);
        for (Node_0029ACC0* nd = g->head; nd; nd = nd->next) {
            void* s = func_001E6978(func_001190D0(8));
            func_001E7410(s, 0x7F261953, nd->x, nd->y, nd->z);
            if (nd->m38)
                func_001E7360(s, 0, 0xDCDED772);
            func_001E9170(narr, j++, s);
        }
        func_001E7720(gs, 0xD84571D6, narr);
        func_001E9170(arr, gi++, gs);
    }
    func_001E7720(out, 0x244550A6, arr);
}
