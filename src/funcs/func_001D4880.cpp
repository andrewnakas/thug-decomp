typedef int qword_001D4880 __attribute__((mode(TI)));

struct Vec_001D4880 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001D4880 q;
    };
    Vec_001D4880() {}
    Vec_001D4880(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
};

struct Box_001D4880 {
    Vec_001D4880 mn;
    Vec_001D4880 mx;
};

class Child_001D4880 {
public:
    char m_pad[0xC];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual Box_001D4880* GetBox();
};

struct Node_001D4880 {
    int m_0;
    Child_001D4880* m_data;
    int m_8;
    Node_001D4880* m_next;
    Node_001D4880* Valid()
    {
        if (m_data != (Child_001D4880*)-1) {
            return this;
        }
        return 0;
    }
};

struct It_001D4880 {
    Node_001D4880* cur;
    Child_001D4880* Next()
    {
        cur = cur->m_next->Valid();
        if (!cur)
            return 0;
        return cur->m_data;
    }
    Child_001D4880* First(Node_001D4880* h)
    {
        Node_001D4880* n = h->m_next;
        if (~(int)n->m_data == 0)
            cur = 0;
        else
            cur = n;
        if (!cur)
            return 0;
        return cur->m_data;
    }
};

struct Group_001D4880 {
    char m_pad0[0x10];
    Node_001D4880* m_head;
    char m_pad14[0xC];
    Box_001D4880 m_box;
    char m_pad40[4];
    int m_valid;
    void UpdateBounds();
};

extern "C" void func_00102358(Box_001D4880* box, Box_001D4880* b);

void Group_001D4880::UpdateBounds()
{
    m_valid = 1;
    m_box.mn.q = Vec_001D4880(10000000.0f, 10000000.0f, 10000000.0f).q;
    m_box.mx.q = Vec_001D4880(-10000000.0f, -10000000.0f, -10000000.0f).q;
    It_001D4880 it;
    for (it.First(m_head); it.cur; it.Next()) {
        Box_001D4880* b = it.cur->m_data->GetBox();
        if (!b) {
            m_valid = 0;
            return;
        }
        func_00102358(&m_box, b);
        func_00102358(&m_box, (Box_001D4880*)&b->mx);
    }
}
