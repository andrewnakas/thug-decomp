struct Node_001EE370 {
    char pad0[8];
    void* m_owner;
};

extern "C" Node_001EE370* func_001E5258(Node_001EE370* prev);
extern "C" void func_001ED8D0(Node_001EE370* n);
extern "C" void* func_001EE410(void* prev);
extern "C" bool func_001F0030(void* s);
extern "C" void func_001EE9E0(void* s);
extern "C" void func_001EEB60(void* s);

extern "C" void func_001EE370(void* owner)
{
    if (!owner)
        return;
    Node_001EE370* n = 0;
    while ((n = func_001E5258(n)) != 0) {
        if (n->m_owner == owner) {
            func_001ED8D0(n);
            n = 0;
        }
    }
    void* s = func_001EE410(0);
    while (s) {
        if (!func_001F0030(s)) {
            func_001EE9E0(s);
            func_001EEB60(s);
        }
        s = func_001EE410(s);
    }
}
