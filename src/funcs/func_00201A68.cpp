/* sym: _vt$14NodeA_00201A68 = 0x00366970 */
/* sym: _vt$14NodeB_00201A68 = 0x00366958 */
/* sym: _vt$18ListNodeC_00201A68 = 0x00366940 */
/* sym: _vt$14NodeD_00201A68 = 0x00366988 */
/* sym: _vt$14NodeE_00201A68 = 0x00366C68 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_00201D98(void* self);

#define NODE_00201A68(N)                    \
    struct N {                              \
        int m_0;                            \
        int m_4;                            \
        int m_8;                            \
        N* m_next;                          \
        N* m_prev;                          \
        virtual void Run();                 \
        virtual ~N()                        \
        {                                   \
            m_prev->m_next = m_next;        \
            m_next->m_prev = m_prev;        \
            m_next = this;                  \
            m_prev = this;                  \
        }                                   \
    };

NODE_00201A68(NodeA_00201A68)
NODE_00201A68(NodeB_00201A68)
NODE_00201A68(ListNodeC_00201A68)
NODE_00201A68(NodeD_00201A68)
NODE_00201A68(NodeE_00201A68)

struct Elem_00201A68 {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
    int m_10;
    virtual ~Elem_00201A68();
};

struct Mgr_00201A68 {
    NodeA_00201A68 m_a;
    NodeB_00201A68 m_b;
    ListNodeC_00201A68 m_c;
    char pad48[0x54 - 0x48];
    void* m_54;
    int m_58;
    void* m_5C;
    char pad60[0x884 - 0x60];
    Elem_00201A68 m_elems[256];
    NodeD_00201A68 m_d;
    NodeD_00201A68 m_e;
    char pad20B4[0x4910 - 0x20B4];
    NodeE_00201A68 m_f;

    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Mgr_00201A68();
};

Mgr_00201A68::~Mgr_00201A68()
{
    func_00201D98(this);
    if (m_5C) {
        func_0010A8D8(D_00388A70, m_5C);
    }
    if (m_54) {
        func_0010A8D8(D_00388A70, m_54);
    }
}
