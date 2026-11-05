struct Node_0026D618 {
    int m_0;
    int m_key;
    int m_8;
    Node_0026D618* m_next;
    bool Valid() const { return ~m_key != 0; }
};

struct Script_0026D618 {
    char pad0[0x18];
    void* m_params;
};

extern char D_003762F8[];
extern char D_00376308[];

extern "C" bool func_0026CB68(Node_0026D618* n);
extern "C" void func_001E7268(void* params, const char* name, int value);

struct List_0026D618 {
    char pad0[0x10];
    Node_0026D618* m_head;

    bool Count(void* params, Script_0026D618* script);
};

bool List_0026D618::Count(void* params, Script_0026D618* script)
{
    int done = 0;
    int total = 0;
    Node_0026D618* n = m_head->Valid() ? m_head : 0;
    while (n) {
        Node_0026D618* next = n->m_next;
        total++;
        if (!next->Valid())
            next = 0;
        if (func_0026CB68(n))
            done++;
        n = next;
    }
    func_001E7268(script->m_params, D_003762F8, total);
    func_001E7268(script->m_params, D_00376308, done);
    return true;
}
