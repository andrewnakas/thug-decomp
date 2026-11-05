struct Arr_00259F80 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern "C" Arr_00259F80* func_001E55B8(unsigned int id, int v);
extern "C" void* func_001E9378(Arr_00259F80* a, int i);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8618(void* params, unsigned int name);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" int func_00229E70(void* node);
extern "C" int func_00229F00(void* node, int i);

struct Obj_00259F80;
extern "C" void func_00259F30(Obj_00259F80* self);

struct Obj_00259F80 {
    void* m0;
    char pad4[0x258];
    int m25C;
    void Fn();
};

void Obj_00259F80::Fn()
{
    if (!m0) return;
    Arr_00259F80* arr = func_001E55B8(0xC472ECC5, 1);
    func_00259F30(this);
    m25C = 0;
    int n = arr->mC;
    for (unsigned short i = 0; i < n; i++) {
        void* node = func_001E9378(arr, i);
        unsigned int type = 0;
        func_001E8398(node, 0x12B4E660, &type, 0);
        if (type == 0x8E6B02AD) continue;
        if (type == 0x30C19600) continue;
        if (type == 0x4C23A77E) {
            unsigned int sub;
            if (func_001E8398(node, 0x7321A8D6, &sub, 0) && sub == 0xCBA10FFA) continue;
        }
        int linked = func_00229E70(node);
        int link = 0;
        if (!linked && type != 0x4C23A77E) continue;
        if (func_001E8618(node, 0x9C91C3CA)) continue;
        int id = m25C;
        void* cur = node;
        for (;;) {
            if (func_001E7DE8(cur, 0x9C91C3CA, &link, 0)) {
                if (link == id) break;
                id = link;
                cur = node;
            }
            func_001E7200(cur, 0x9C91C3CA, id);
            if (!func_00229E70(cur)) break;
            cur = func_001E9378(arr, func_00229F00(cur, 0));
        }
        if (id == m25C) m25C = id + 1;
    }
}
