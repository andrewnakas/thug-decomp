extern void* D_0038FC78;

struct Array_0023A278 {
    char pad[0xC];
    int m_size;
};

struct Entry_0023A278 {
    void* m_params;
};

struct List_0023A278 {
    char pad[0x248];
    Entry_0023A278* m_entries[1];
};

extern "C" void* func_0022E368(void* game, int a);
extern "C" void* func_00262330(void* p, unsigned int name);
extern "C" void* func_00262358(void* p);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8248(void* params, unsigned int name, Array_0023A278** out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E7D70(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" void* func_001E9378(Array_0023A278* arr, int i);
extern "C" void* func_001E5548(unsigned int name, int create);
extern "C" Array_0023A278* func_001E55B8(unsigned int name, int create);
extern "C" void* func_001F0D78(const char* name);
extern "C" List_0023A278* func_0022DD38(void* game);
extern "C" int func_00239A18(void* self, void* obj, int a, int b);

static inline unsigned int FindId_0023A278(unsigned int key)
{
    void* info = func_0022E368(D_0038FC78, 0);
    void* params = func_00262330(info, 0xD544AA2D);
    unsigned int id = 0;
    if (!func_001E8398(params, key, &id, 0)) {
        Array_0023A278* arr;
        func_001E8248(func_00262358(info), 0, &arr, 1);
        int n = arr->m_size;
        for (int i = 0; i < n; i++) {
            void* entry = func_001E9378(arr, i);
            unsigned int k;
            func_001E8398(entry, 0xA92A2280, &k, 1);
            if (k == key) {
                func_001E8398(entry, 0x5B077CE1, &id, 1);
                break;
            }
        }
    }
    return id;
}

static inline int FindIndex_0023A278(unsigned int key)
{
    void* info = func_0022E368(D_0038FC78, 0);
    void* params = func_00262330(info, 0xD544AA2D);
    int index = -1;
    if (!func_001E7DE8(params, key, &index, 0)) {
        Array_0023A278* arr;
        func_001E8248(func_00262358(info), 0, &arr, 1);
        int n = arr->m_size;
        for (int i = 0; i < n; i++) {
            void* entry = func_001E9378(arr, i);
            int enabled = 0;
            func_001E7DE8(entry, 0xB56A8816, &enabled, 0);
            if (enabled) {
                unsigned int k;
                func_001E8398(entry, 0xA92A2280, &k, 1);
                if (k == key) {
                    int v;
                    func_001E8398(entry, 0x5B077CE1, (unsigned int*)&v, 1);
                    index = v;
                    break;
                }
            }
        }
    }
    return index;
}

int func_0023A278(void* self, unsigned int key, int a, int b, int depth)
{
    void* obj;
    unsigned int id = FindId_0023A278(key);
    if (!id) {
        obj = 0;
    } else {
        void* node;
        func_001E8180(func_001E5548(id, 1), 0x7031F10C, &node, 1);
        for (int d = depth; d >= 2; d--) {
            unsigned int link;
            func_001E8398(node, 0x6E855102, &link, 0);
            func_001E8180(func_001E9378(func_001E55B8(link, 1), 0), 0x7031F10C, &node, 1);
        }
        const char* name;
        func_001E7D70(node, 0xA1DC81F9, &name, 1);
        obj = func_001F0D78(name);
    }
    if (!obj) {
        int index = FindIndex_0023A278(key);
        if (index == -1)
            return 0;
        List_0023A278* list = func_0022DD38(D_0038FC78);
        if (list) {
            const char* name;
            func_001E7C80(list->m_entries[index]->m_params, 0xA1DC81F9, &name, 1);
            obj = func_001F0D78(name);
        }
    }
    return func_00239A18(self, obj, a, b);
}
