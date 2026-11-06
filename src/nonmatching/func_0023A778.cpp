/* fuzzy: 98.6 */
/* near miss: 7 of 244 words: only count/trailing register swap (game count s0, trailing s3) */
struct Arr_0023A778 {
    char pad[0xC];
    int m_count;
};

struct Item_0023A778 {
    char pad[8];
    int m_8;
    int m_C;
    unsigned int m_10;
    char pad14[4];
    unsigned int m_18;
};

struct Slot_0023A778 {
    void* m_0;
};

struct Mgr_0023A778 {
    char pad[0x248];
    Slot_0023A778* m_248[8];
};

extern void* D_0038FC78;
extern "C" void* func_0022E368(void* mgr, int a);
extern "C" void* func_00262330(void* self, unsigned int name);
extern "C" void* func_00262358(void* self);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8248(void* params, unsigned int name, Arr_0023A778** out, int required);
extern "C" void* func_001E9378(void* arr, int i);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" void* func_001E55B8(unsigned int name, int a);
extern "C" bool func_001E7D70(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" Mgr_0023A778* func_0022DD38(void* self);
extern "C" Item_0023A778* func_0023AFE8(void* list, int index);

static inline unsigned int Resolve_0023A778(unsigned int v, int depth)
{
    if (!v) {
        return 0;
    }
    void* x;
    func_001E8180(func_001E5548(v, 1), 0x7031F10C, &x, 1);
    int n = depth;
    while (n >= 2) {
        unsigned int y;
        func_001E8398(x, 0x6E855102, &y, 0);
        n--;
        func_001E8180(func_001E9378(func_001E55B8(y, 1), 0), 0x7031F10C, &x, 1);
    }
    const char* s;
    func_001E7D70(x, 0xA1DC81F9, &s, 1);
    return func_001F0D78(s);
}

static inline int FindIdx_0023A778(unsigned int name)
{
    void* g2 = func_0022E368(D_0038FC78, 0);
    void* p = func_00262330(g2, 0xD544AA2D);
    int idx = -1;
    if (!func_001E7DE8(p, name, &idx, 0)) {
        Arr_0023A778* list;
        func_001E8248(func_00262358(g2), 0, &list, 1);
        int n = list->m_count;
        for (int i = 0; i < n; i++) {
            void* e = func_001E9378(list, i);
            int has = 0;
            func_001E7DE8(e, 0xB56A8816, &has, 0);
            if (has) {
                unsigned int k;
                func_001E8398(e, 0xA92A2280, &k, 1);
                if (k == name) {
                    unsigned int w;
                    func_001E8398(e, 0x5B077CE1, &w, 1);
                    idx = w;
                    break;
                }
            }
        }
    }
    return idx;
}

static inline unsigned int FindV_0023A778(unsigned int name)
{
    void* g = func_0022E368(D_0038FC78, 0);
    void* p = func_00262330(g, 0xD544AA2D);
    unsigned int v = 0;
    if (!func_001E8398(p, name, &v, 0)) {
        Arr_0023A778* list;
        func_001E8248(func_00262358(g), 0, &list, 1);
        int n = list->m_count;
        for (int i = 0; i < n; i++) {
            void* e = func_001E9378(list, i);
            unsigned int k;
            func_001E8398(e, 0xA92A2280, &k, 1);
            if (k == name) {
                func_001E8398(e, 0x5B077CE1, &v, 1);
                break;
            }
        }
    }
    return v;
}

struct Obj_0023A778 {
    char pad[0x44];
    char m_44[0x14];
    int m_58;
    int Count(unsigned int name, int ref, int depth);
};

int Obj_0023A778::Count(unsigned int name, int ref, int depth)
{
    unsigned int v = FindV_0023A778(name);
    unsigned int id = Resolve_0023A778(v, depth);
    if (!id) {
        int idx = FindIdx_0023A778(name);
        if (idx == -1) {
            return 0;
        }
        Mgr_0023A778* m = func_0022DD38(D_0038FC78);
        if (m) {
            const char* s;
            func_001E7C80(m->m_248[idx]->m_0, 0xA1DC81F9, &s, 1);
            id = func_001F0D78(s);
        }
    }
    int trailing = 0;
    int count = 0;
    for (int i = 0; i < m_58; i++) {
        if (func_0023AFE8(m_44, i)->m_10 == id) {
            if (!ref || ref == func_0023AFE8(m_44, i)->m_8) {
                count++;
                trailing = 1;
            }
        } else {
            if (!((func_0023AFE8(m_44, i)->m_18 & 0x10) && trailing)) {
                trailing = 0;
            }
        }
    }
    return count - trailing;
}
