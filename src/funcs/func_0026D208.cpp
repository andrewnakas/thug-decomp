typedef int qword_0026D208 __attribute__((mode(TI)));

struct Vec_0026D208 {
    union {
        struct { float x, y, z, w; };
        qword_0026D208 q;
    };
};

struct Node_0026D208 {
    int m0;
    int m_key;
    int m8;
    Node_0026D208* m_next;
    Node_0026D208* Valid()
    {
        Node_0026D208* r = 0;
        if (m_key != -1)
            r = this;
        return r;
    }
};

extern "C" char* func_0026CBB0(Node_0026D208* n);
extern "C" int func_00331950(const char* a, const char* b);
extern "C" void func_0026CBF0(Node_0026D208* n, Vec_0026D208 a, Vec_0026D208 b);

struct Obj_0026D208 {
    char m_pad[0x10];
    Node_0026D208* m_head;
    void Set(const char* name, const Vec_0026D208& a, const Vec_0026D208& b);
};

void Obj_0026D208::Set(const char* name, const Vec_0026D208& a, const Vec_0026D208& b)
{
    for (Node_0026D208* n = m_head->Valid(); n; n = n->m_next->Valid()) {
        if (func_00331950(func_0026CBB0(n), name))
            continue;
        func_0026CBF0(n, a, b);
        break;
    }
}
