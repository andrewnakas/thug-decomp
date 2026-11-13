/* fuzzy: 87.9 */
/* sym: _vt$14NodeA_00133D48 = 0x0035D5C8 */
/* sym: _vt$14HeadA_00133D48 = 0x0035D5B0 */
/* sym: _vt$14NodeB_00133D48 = 0x0035D5F8 */
/* sym: _vt$14HeadB_00133D48 = 0x0035D5E0 */
extern "C" void* func_001046B0(int size);
extern "C" void func_0010A950(void* heap, void* ctx);
extern "C" void func_0010A9B0(void* heap);
extern "C" void func_00208400(void* p, void* l0, void* l1, void* l2);
extern "C" void func_00114EB8(void* table, int* key);
extern "C" void func_00132A80(void* table);
extern "C" void* func_00132A90(void* table, int* key);

struct Heap_00133D48 {
    char pad[0xD8];
    void* m_D8;
};
extern Heap_00133D48* D_00388A70;

class Item_00133D48 {
public:
    char pad[0x28];
    virtual ~Item_00133D48();
};

extern "C" int func_00134F08(Item_00133D48* p);
extern "C" unsigned int func_001354F8(Item_00133D48* p);
extern "C" int func_00135500(Item_00133D48* p);
extern "C" void func_00135580(Item_00133D48* p, unsigned int f);
extern "C" void func_00135590(Item_00133D48* p, unsigned int f);

class NodeA_00133D48 {
public:
    int m0;
    unsigned int m_data;
    int m_pri;
    NodeA_00133D48* m_next;
    NodeA_00133D48* m_prev;
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    NodeA_00133D48(unsigned int data)
    {
        m_data = data;
        m_pri = 0;
        m_next = this;
        m_prev = this;
    }
    virtual ~NodeA_00133D48()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
    virtual void Run();
    NodeA_00133D48* Valid() { return ~m_data ? this : 0; }
    NodeA_00133D48* Next() { return m_next->Valid(); }
};

class HeadA_00133D48 : public NodeA_00133D48 {
public:
    HeadA_00133D48() : NodeA_00133D48(0xFFFFFFFF) {}
    virtual ~HeadA_00133D48() {}
    virtual void Run();
    void AddToTail(NodeA_00133D48* n)
    {
        n->m_prev = m_prev;
        n->m_next = this;
        m_prev->m_next = n;
        m_prev = n;
    }
    int CountItems()
    {
        int c = 0;
        for (NodeA_00133D48* n = Next(); n; n = n->Next())
            c++;
        return c;
    }
};

class NodeB_00133D48 {
public:
    int m0;
    Item_00133D48* m_data;
    int m_pri;
    NodeB_00133D48* m_next;
    NodeB_00133D48* m_prev;
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    NodeB_00133D48(Item_00133D48* data)
    {
        m_data = data;
        m_pri = 0;
        m_next = this;
        m_prev = this;
    }
    virtual ~NodeB_00133D48()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
    virtual void Run();
    NodeB_00133D48* Valid(unsigned int k = 0) { return k < ~(unsigned int)m_data ? this : 0; }
    NodeB_00133D48* Next() { return m_next->Valid(); }
};

class HeadB_00133D48 : public NodeB_00133D48 {
public:
    HeadB_00133D48() : NodeB_00133D48((Item_00133D48*)-1) {}
    virtual ~HeadB_00133D48() {}
    virtual void Run();
    void AddToTail(NodeB_00133D48* n)
    {
        n->m_prev = m_prev;
        n->m_next = this;
        m_prev->m_next = n;
        m_prev = n;
    }
    int CountItems()
    {
        int c = 0;
        for (NodeB_00133D48* n = Next(); n; n = n->Next())
            c++;
        return c;
    }
};

class Obj_00133D48 {
public:
    char pad[0xD0];
    void* m_D0;
    void* m_D4;
    void Update(HeadB_00133D48* list);
};

void Obj_00133D48::Update(HeadB_00133D48* list)
{
    if (!m_D4)
        return;

    HeadA_00133D48 l0;
    HeadA_00133D48 l1;
    HeadA_00133D48 l2;
    HeadB_00133D48 l3;
    NodeA_00133D48* n;

    func_0010A950(D_00388A70, D_00388A70->m_D8);
    func_00132A80(m_D0);
    Item_00133D48* it;
    while ((it = (Item_00133D48*)func_00132A90(m_D0, 0))) {
        if (func_00135500(it) & 4) {
            n = new NodeA_00133D48(func_001354F8(it));
            l0.AddToTail(n);
            func_00135590(it, 4);
            func_00135580(it, 0x40);
        }
        if (func_00135500(it) & 0x18) {
            n = new NodeA_00133D48(func_001354F8(it));
            l1.AddToTail(n);
            if (func_00135500(it) & 8) {
                l3.AddToTail(new NodeB_00133D48(it));
            } else {
                func_00135590(it, 0x10);
            }
        }
        if (func_00135500(it) & 0x20) {
            n = new NodeA_00133D48(func_001354F8(it));
            l2.AddToTail(n);
            func_00135590(it, 0x20);
        }
    }

    if (list) {
        NodeB_00133D48* next;
        for (NodeB_00133D48* ln = list->Next(); ln; ln = next) {
            next = ln->Next();
            int add = 1;
            it = ln->m_data;
            if (l1.CountItems()) {
                NodeA_00133D48* next2;
                for (NodeA_00133D48* m = l1.Next(); m; m = next2) {
                    next2 = m->Next();
                    unsigned int d = m->m_data;
                    if (d == func_001354F8(it)) {
                        add = 0;
                        break;
                    }
                }
            }
            if (add) {
                n = new NodeA_00133D48(func_001354F8(it));
                l1.AddToTail(n);
                func_00135590(it, 0x10);
            }
        }
    }

    func_0010A9B0(D_00388A70);
    func_00208400(m_D4, &l0, &l1, &l2);

    if (l0.CountItems()) {
        NodeA_00133D48* next;
        for (NodeA_00133D48* n = l0.Next(); n; n = next) {
            next = n->Next();
            delete n;
        }
    }
    if (l1.CountItems()) {
        NodeA_00133D48* next;
        for (NodeA_00133D48* n = l1.Next(); n; n = next) {
            next = n->Next();
            delete n;
        }
    }
    if (l2.CountItems()) {
        NodeA_00133D48* next;
        for (NodeA_00133D48* n = l2.Next(); n; n = next) {
            next = n->Next();
            delete n;
        }
    }
    if (l3.CountItems()) {
        NodeB_00133D48* next;
        for (NodeB_00133D48* n = l3.Next(); n; n = next) {
            next = n->Next();
            it = n->m_data;
            int key = func_00134F08(it);
            func_00114EB8(m_D0, &key);
            func_00135590(it, 0x40);
            delete it;
            delete n;
        }
    }
}
