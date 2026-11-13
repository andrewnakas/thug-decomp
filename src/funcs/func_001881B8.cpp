/* sym: __nw__15Params_001881B8Ui = 0x001190D0 */
/* sym: __15Params_001881B8RC15Params_001881B8 = 0x001E69A0 */
/* sym: _$_15Params_001881B8 = 0x001E6AE8 */
struct Params_001881B8 {
    int m0;
    int m4;
    Params_001881B8(const Params_001881B8& o);
    ~Params_001881B8();
    static void* operator new(unsigned int size);
};

extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_0010A950(void* p, int v);
extern "C" void* func_001E9378(void* a, int i);
extern "C" bool func_001E8180(void* params, unsigned int name, void* out, int req);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);

struct Heap_001881B8 {
    char pad0[0xE4];
    int mE4;
};

extern Heap_001881B8* D_00388A70;

struct Node_001881B8 {
    char pad0[0x8];
    int m8;
};

extern "C" Node_001881B8* func_001E6E90(void* list, Node_001881B8* prev);

struct Array_001881B8 {
    char pad0[0xC];
    int mC;
};

struct E_001881B8 {
    int m_key;
    int m_id;
    unsigned int m8;
    int m_used;
    int m10;
    int m14;
    Params_001881B8* m_obj;
};

struct L_001881B8 {
    E_001881B8* m_items;
    int m_count;
    int m_alive;
    int m_changed;
    void Set(Array_001881B8* arr, int replace);
};

extern "C" void func_00188498(L_001881B8* l, int key);

void L_001881B8::Set(Array_001881B8* arr, int replace)
{
    int count = arr->mC;
    if (replace && count == 0) {
        if (!m_items) {
            return;
        }
        for (int i = 0; i < m_count; i++) {
            delete m_items[i].m_obj;
        }
        if (m_items) {
            func_0010A8D8(D_00388A70, m_items);
        }
        m_count = 0;
        m_changed = 1;
        m_items = 0;
        return;
    }
    func_0010A950(D_00388A70, D_00388A70->mE4);
    E_001881B8* items = (E_001881B8*)func_0010A638(D_00388A70, (m_count + count) * sizeof(E_001881B8), 1, 0);
    int n = 0;
    for (int i = 0; i < count; i++) {
        void* s = func_001E9378(arr, i);
        Node_001881B8* a = func_001E6E90(s, 0);
        Node_001881B8* b = func_001E6E90(s, a);
        if (replace) {
            func_00188498(this, a->m8);
        }
        E_001881B8* cur = &items[n++];
        Params_001881B8* p;
        if (func_001E8180(s, 0x7031F10C, &p, 0)) {
            cur->m_obj = new Params_001881B8(*p);
        } else {
            cur->m_obj = 0;
        }
        if (!func_001E8398(s, 0x923FBB3A, &cur->m8, 0)) {
            cur->m8 = 0x1CA1FF20;
        }
        cur->m10 = func_001E8708(s, 0x80367192);
        cur->m_key = a->m8;
        cur->m_id = b->m8;
        cur->m_used = 1;
        m_changed = 1;
    }
    if (m_items) {
        for (int i = 0; i < m_count; i++) {
            items[n] = m_items[i];
            n++;
        }
        if (m_items) {
            func_0010A8D8(D_00388A70, m_items);
        }
    }
    m_items = items;
    m_count = n;
    func_0010A9B0(D_00388A70);
}
