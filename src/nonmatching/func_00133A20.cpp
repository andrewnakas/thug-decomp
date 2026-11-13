/* fuzzy: 88.0 */
extern "C" void* func_001046B0(int size);
extern char D_0035D5F8[];

struct Box_00133A20 {
    float min[4];
    float max[4];
};

struct Elem_00133A20 {
    int m_key;
    int m4[4];
};

struct Mesh_00133A20;

/* Self-linked list node (vtable D_0035D5F8) holding a mesh. */
struct Link_00133A20 {
    int m0;
    Mesh_00133A20* m_data;
    int m8;
    Link_00133A20* m_next;
    Link_00133A20* m_prev;
    void* m_vt;
    void Init(Mesh_00133A20* data)
    {
        m_next = this;
        m_prev = this;
        m_vt = D_0035D5F8;
        m_data = data;
        m8 = 0;
    }
    void AddTail(Link_00133A20* node)
    {
        node->m_next = this;
        node->m_prev = m_prev;
        m_prev->m_next = node;
        m_prev = node;
    }
};

extern "C" Box_00133A20* func_001022D8(Box_00133A20* self);
extern "C" void func_00134F10(Mesh_00133A20* m, int key);
extern "C" void func_00135048(Mesh_00133A20* m, int a);
extern "C" void func_001354B8(Mesh_00133A20* m, Elem_00133A20* e);
extern "C" void func_00135580(Mesh_00133A20* m, int flags);

class Scene_00133A20 {
public:
    char pad0[0xB0];
    float m_B0[4];
    float m_C0[4];
    char padD0[0x15C - 0xD0];
    int m_15C;
    char pad160[0x1E8 - 0x160];
    char m_1E8[0x80];
    int m_268;
    Elem_00133A20* m_26C;
    int m_270;
    char pad274[4];
    int m_278;
    Link_00133A20* m_27C;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual int V5(void* data);
    int Load(void* data);
};

extern "C" int func_00133550(Scene_00133A20* self, void* data, void* buf, int* count, Elem_00133A20** elems,
                              int* m270, Box_00133A20* box, int b);
extern "C" Mesh_00133A20* func_00132FD0(Scene_00133A20* self, int key);
extern "C" Mesh_00133A20* func_00134660(Scene_00133A20* self);
extern "C" void func_00132FF8(Scene_00133A20* self, Mesh_00133A20* m);
extern "C" void func_00133D48(Scene_00133A20* self, int a);

int Scene_00133A20::Load(void* data)
{
    Box_00133A20 box;
    func_001022D8(&box);
    if (!m_15C)
        return 0;
    func_00133550(this, data, m_1E8, &m_268, &m_26C, &m_270, &box, 0);
    if (m_268 > 0) {
        for (int i = 0; i < m_268; i++) {
            Mesh_00133A20* m = func_00132FD0(this, m_26C[i].m_key);
            if (!m) {
                m = func_00134660(this);
                func_00134F10(m, m_26C[i].m_key);
                func_00135048(m, 1);
                func_00135580(m, 4);
                func_00132FF8(this, m);
                Link_00133A20* node = (Link_00133A20*)func_001046B0(0x18);
                node->Init(m);
                m_27C->AddTail(node);
            }
            func_001354B8(m, &m_26C[i]);
        }
        func_00133D48(this, m_278);
    }
    return V5(data);
}
