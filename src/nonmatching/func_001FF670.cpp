/* fuzzy: 93.8 */
extern "C" void func_001FA8C0(void* self, int chrg);
extern "C" void func_001FA9B0(void* self, int chrg);
extern char D_00366AA8[];
extern char D_00366AC0[];
extern char D_00366AF8[];

struct Count_001FF670 {
    int m0;
    int m_count;
    int Release() { return --m_count; }
};

struct RefA_001FF670 {
    unsigned char m_id;
    char pad1[7];
    Count_001FF670 m_ref;
};

struct RefB_001FF670 {
    unsigned char m_id;
    char pad1[0xB];
    Count_001FF670 m_ref;
};

struct Base_001FF670 {
    char pad[0x14];
    virtual ~Base_001FF670();
};

struct Item0_001FF670 : Base_001FF670 {
    RefA_001FF670* m_ref;
};

struct Item1_001FF670 : Base_001FF670 {
    int m18;
    RefA_001FF670* m_ref;
};

struct Item2_001FF670 : Base_001FF670 {
    char pad18[0x2C - 0x18];
    RefB_001FF670* m_ref;
};

template <class T>
struct Node_001FF670 {
    int m0;
    T* data;
    int m8;
    Node_001FF670* next;
    int m10;
    int m14;
    T* GetData() { return data; }
    Node_001FF670* Valid() { return (int)data != -1 ? this : 0; }
};

template <class T, char* VT>
struct It_001FF670 {
    int m0;
    Node_001FF670<T>* cur;
    void* vt;
    It_001FF670() { vt = VT; cur = 0; }
    ~It_001FF670() { vt = VT; }
    T* Next() {
        cur = cur->next->Valid();
        if (cur) return cur->GetData();
        return 0;
    }
    T* Advance(Node_001FF670<T>* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    T* First(Node_001FF670<T>* h) {
        cur = h;
        return Next();
    }
};

struct Owner_001FF670 {
    Node_001FF670<Item0_001FF670> m_list0;
    Node_001FF670<Item1_001FF670> m_list1;
    Node_001FF670<Item2_001FF670> m_list2;
};

typedef It_001FF670<Item0_001FF670, D_00366AF8> It0;
typedef It_001FF670<Item1_001FF670, D_00366AC0> It1;
typedef It_001FF670<Item2_001FF670, D_00366AA8> It2;

struct Mgr_001FF670 {
    void Remove(Owner_001FF670* o, int which, unsigned char id);
};

void Mgr_001FF670::Remove(Owner_001FF670* o, int which, unsigned char id)
{
    switch (which) {
    case 0: {
        It0 it;
        Item0_001FF670* d = it.First(&o->m_list0);
        if (d) {
            It0* p = &it;
            do {
                Item0_001FF670* nx = p->Advance(it.cur);
                RefA_001FF670* r = d->m_ref;
                if (r->m_id == id) {
                    if (r->m_ref.Release() == 0 && r) {
                        func_001FA8C0(r, 3);
                    }
                    delete d;
                }
                d = nx;
            } while (d);
        }
        break;
    }
    case 1: {
        It1 it;
        Item1_001FF670* d = it.First(&o->m_list1);
        if (d) {
            It1* p = &it;
            do {
                Item1_001FF670* nx = p->Advance(it.cur);
                RefA_001FF670* r = d->m_ref;
                if (r->m_id == id) {
                    if (r->m_ref.Release() == 0 && r) {
                        func_001FA8C0(r, 3);
                    }
                    delete d;
                }
                d = nx;
            } while (d);
        }
        break;
    }
    case 2: {
        It2 it;
        Item2_001FF670* d = it.First(&o->m_list2);
        if (d) {
            It2* p = &it;
            do {
                Item2_001FF670* nx = p->Advance(it.cur);
                RefB_001FF670* r = d->m_ref;
                if (r->m_id == id) {
                    if (r->m_ref.Release() == 0 && r) {
                        func_001FA9B0(r, 3);
                    }
                    delete d;
                }
                d = nx;
            } while (d);
        }
        break;
    }
    }
}
