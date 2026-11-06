extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_0010BEB8(void* p);
extern "C" void func_0010DBF8(void* p);
extern "C" void func_0010ECF8(void* p);
extern void* D_00388A70;

class Child_00115D58 {
public:
    int m0[5];
    virtual ~Child_00115D58();
};

class Node_00115D58 {
public:
    int m0[3];
    void* m_data;
    void* m_file;
    char pad14[0x2C - 0x14];
    void* m_extData;
    Child_00115D58** m_children;
    char pad34[0x40 - 0x34];
    int m_count : 16;
    unsigned int m_b16 : 1;
    unsigned int m_b17 : 1;
    unsigned int m_ext : 1;
    ~Node_00115D58();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Node_00115D58::~Node_00115D58()
{
    for (int i = 0; i < m_count; i++) {
        if (m_children[i]) {
            delete m_children[i];
        }
    }
    if (m_children) {
        func_0010BEB8(m_children);
    }
    if (m_ext) {
        func_0010DBF8(m_extData);
    } else if (m_data) {
        func_0010BEB8(m_data);
    }
    if (m_file) {
        func_0010ECF8(m_file);
    }
}
