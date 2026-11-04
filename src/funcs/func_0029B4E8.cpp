struct Node_0029B4E8 {
    char pad[0x10];
    float x, y, z;
    char pad2[0x2C - 0x1C];
    Node_0029B4E8* next;
};

struct Grp_0029B4E8 {
    int m0;
    Grp_0029B4E8* next;
    int m8;
    Node_0029B4E8* head;
};

extern char D_003775C8[];
extern "C" void* func_001E9378(void* a, int i);
extern "C" void func_001E7410(void* s, unsigned int name, float x, float y, float z);
extern "C" void func_001E7360(void* s, unsigned int name, int v);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E90A8(void* arr, int i, int v);
extern "C" void func_001E7720(void* s, unsigned int name, void* arr);

struct Obj_0029B4E8 {
    char pad[0x24];
    Grp_0029B4E8* m24;
    void Export(void* arr, int* index, int id);
};

void Obj_0029B4E8::Export(void* arr, int* index, int id)
{
    int i = *index;
    int gi = 0;
    for (Grp_0029B4E8* g = m24; g; g = g->next, gi++) {
        for (Node_0029B4E8* n = g->head; n; n = n->next) {
            void* s = func_001E9378(arr, i++);
            func_001E7410(s, 0x7F261953, n->x, n->y, n->z);
            func_001E7410(s, 0x9D2D0915, 0.0f, 0.0f, 0.0f);
            func_001E7360(s, 0xA1DC81F9, id++);
            func_001E7360(s, 0x12B4E660, 0x8E6B02AD);
            func_001E7360(s, 0, 0x7C2552B9);
            func_001E7360(s, 0, 0x1645B830);
            char buf[64];
            func_003331D0(buf, D_003775C8, gi);
            func_001E7360(s, 0x1A3A966B, func_001F0D78(buf));
            func_001E7360(s, 0x54CF8532, 0xA9ECF4E9);
            if (n->next) {
                void* a = func_001E8DD0(func_00122CF8(0x10));
                func_001E8E98(a, 1, 1);
                func_001E90A8(a, 0, i);
                func_001E7720(s, 0x2E7D5EE7, a);
            }
        }
    }
    *index = i;
}
