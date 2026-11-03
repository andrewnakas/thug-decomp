struct Arr_002A6150 {
    char pad[0xC];
    int mC;
};

extern char D_00378328[];
extern "C" Arr_002A6150* func_001E55F8(void* p, int f);
extern "C" void* func_001E9378(Arr_002A6150* a, int i);
extern "C" int func_001E8A50(void* s, char* name, int* out, int f);
extern "C" int func_001E88D8(void* s, unsigned int name, int* out, int f);

struct Obj_002A6150 {
    int Find(void* list, int key, unsigned int name);
};

int Obj_002A6150::Find(void* list, int key, unsigned int name)
{
    int id;
    int out;
    Arr_002A6150* a = func_001E55F8(list, 0);
    out = 0;
    for (int i = 0; i < a->mC; i++) {
        void* s = func_001E9378(a, i);
        func_001E8A50(s, D_00378328, &id, 1);
        if (id == key)
            func_001E88D8(s, name, &out, 1);
    }
    return out;
}
