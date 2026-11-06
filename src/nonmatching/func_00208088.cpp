/* fuzzy: 53.2 */
/* sym: _vt$13Node_00208088 = 0x0035D5C8 */
/* sym: _vt$13Head_00208088 = 0x0035D5B0 */
struct Vec_00208088 {
    float x, y, z, w;
};

struct Box_00208088 {
    Vec_00208088 mn;
    Vec_00208088 mx;
    bool Intersects(const Box_00208088& b) const
    {
        if (mn.x > b.mx.x || b.mn.x > mx.x || mn.z > b.mx.z || b.mn.z > mx.z || mn.y > b.mx.y || b.mn.y > mx.y)
            return false;
        return true;
    }
};

struct Heap_00208088 {
    char pad0[0xD8];
    int mD8;
};

extern Heap_00208088* D_00388A70;
extern "C" void func_0010A950(Heap_00208088* heap, int ctx);
extern "C" void func_0010A9B0(Heap_00208088* heap);
extern "C" void* func_001046B0(int size);
extern "C" void* func_0010BDE0(int size);

struct Obj_00208088 {
    char pad0[0x8];
    unsigned short m8;
    char padA[0x6];
    Box_00208088 m_box;
};

struct Item_00208088 {
    int m0;
    int m4;
    Obj_00208088* m_obj;
    int mC;
    int m10;
};

class Node_00208088 {
public:
    int m0;
    void* m_data;
    int m8;
    Node_00208088* m_next;
    Node_00208088* m_prev;
    Node_00208088(void* data)
    {
        m_next = this;
        m_prev = this;
        m_data = data;
        m8 = 0;
    }
    virtual ~Node_00208088()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
    virtual void Key();
    Node_00208088* Valid() { return ~(int)m_data ? this : 0; }
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Head_00208088 : public Node_00208088 {
public:
    Head_00208088() : Node_00208088((void*)-1) {}
    virtual void Key();
    void Append(Node_00208088* n)
    {
        n->m_next = this;
        n->m_prev = m_prev;
        m_prev->m_next = n;
        m_prev = n;
    }
    int Count()
    {
        int n = 0;
        Node_00208088* p = m_next->Valid();
        while (p) {
            p = p->m_next->Valid();
            n++;
        }
        return n;
    }
};

struct Cell_00208088 {
    Box_00208088 m_box;
    int m20;
    int m_count;
    int m28;
    void** m_items;
};

struct Grid_00208088 {
    char pad0[0x30];
    Cell_00208088 m_cells[20][20];
    void Build(Item_00208088* items, int count);
};

void Grid_00208088::Build(Item_00208088* items, int count)
{
    Head_00208088 head;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            Cell_00208088* cell = &m_cells[i][j];
            func_0010A950(D_00388A70, D_00388A70->mD8);
            for (int k = 0; k < count; k++) {
                Item_00208088* it = &items[k];
                Obj_00208088* o = it->m_obj;
                if (o->m8 > 0 && o->m_box.Intersects(cell->m_box)) {
                    head.Append(new Node_00208088(it));
                }
            }
            func_0010A9B0(D_00388A70);
            if (head.Count()) {
                cell->m_items = (void**)func_0010BDE0(head.Count() * 4);
                cell->m_count = head.Count();
                int k = 0;
                Node_00208088* n = head.m_next->Valid();
                while (n) {
                    Node_00208088* next = n->m_next->Valid();
                    cell->m_items[k] = n->m_data;
                    delete n;
                    n = next;
                    k++;
                }
            }
        }
    }
}
