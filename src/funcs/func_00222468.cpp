struct Array_00222468 {
    int pad[3];
    int m_size;
};

struct Holder_00222468 {
    void* m_params;
};

struct Skater_00222468 {
    char pad[0x24C];
    Holder_00222468* m_holders[10];
};

struct Script_00222468 {
    char pad[0x18];
    void* m_params;
};

extern void* D_0038FC78;
extern char D_0038F8F8[];
extern char D_0038F8E8[];
extern char D_0038F900[];
extern char D_0038F908[];
extern char D_00371990[];
extern char D_003719A0[];
extern char D_003719B0[];
extern char D_003719C8[];
extern char D_003719D8[];
extern char D_003719E8[];
extern char D_003719F8[];

extern "C" bool func_001E84E8(void* self, const char* name, unsigned int* out, int assert_);
extern "C" bool func_001E87B8(void* self, const char* name);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" Array_00222468* func_001E55F8(const char* name, int assert_);
extern "C" unsigned int func_001E9300(void* self, int index);
extern "C" void* func_001E5548(unsigned int name, int assert_);
extern "C" bool func_001E81F0(void* self, const char* name, void** out, int assert_);
extern "C" Skater_00222468* func_0022DD38(void* self);
extern "C" bool func_001E7DE8(void* self, unsigned int name, int* out, int assert_);
extern "C" void* func_00122CF8(unsigned int size);
extern "C" void* func_001E8DD0(void* self);
extern "C" void func_001E8E98(void* self, int size, int type);
extern "C" void func_001E90F8(void* self, int index, unsigned int value);
extern "C" void func_001E90A8(void* self, int index, int value);
extern "C" void func_001E7788(void* self, const char* name, void* value);

bool func_00222468(void* params, Script_00222468* script)
{
    unsigned int tricks[128];
    int cats[128];
    unsigned int type;
    unsigned int trick_type;
    void* trick_params;
    int enabled;

    int ntricks = 0;
    int i = 0;
    int ncats = 0;
    type = 0;
    func_001E84E8(params, D_0038F8F8, &type, 0);
    bool special = func_001E87B8(params, D_0038F8E8);
    unsigned int grab = func_001F0D78(D_00371990);
    unsigned int flip = func_001F0D78(D_003719A0);
    Array_00222468* list = func_001E55F8(D_003719B0, 1);
    int n = list->m_size;
    for (; i < n; i++) {
        unsigned int id = func_001E9300(list, i);
        void* trick = func_001E5548(id, 0);
        if (trick) {
            if (!func_001E84E8(trick, D_003719C8, &trick_type, 0) && !func_001E84E8(trick, D_0038F900, &trick_type, 0))
                trick_type = func_001F0D78(D_003719D8);
            if ((special && type == 0) || trick_type == type) {
                func_001E81F0(trick, D_0038F908, &trick_params, 1);
                if (special) {
                    if (func_001E87B8(trick_params, D_003719E8))
                        tricks[ntricks++] = id;
                } else if (!func_001E87B8(trick_params, D_003719E8)) {
                    tricks[ntricks++] = id;
                }
            }
        }
    }
    if (type == grab || type == flip) {
        Skater_00222468* skater = func_0022DD38(D_0038FC78);
        if (skater) {
            for (int k = 1; k < 11; k++) {
                enabled = 0;
                if (func_001E7DE8(skater->m_holders[k - 1]->m_params, 0x1F802B5F, &enabled, 0) && enabled)
                    cats[ncats++] = k;
            }
        }
    }
    if (!ntricks)
        return false;
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, ntricks, 13);
    for (int j = 0; j < ntricks; j++)
        func_001E90F8(arr, j, tricks[j]);
    func_001E7788(script->m_params, D_003719B0, arr);
    if (ncats > 0) {
        void* arr2 = func_001E8DD0(func_00122CF8(0x10));
        func_001E8E98(arr2, ncats, 1);
        for (int j = 0; j < ncats; j++)
            func_001E90A8(arr2, j, cats[j]);
        func_001E7788(script->m_params, D_003719F8, arr2);
    }
    return true;
}
