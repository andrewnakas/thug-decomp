struct Node_001E6B30 {
    char pad[0xC];
    Node_001E6B30* mC;
};
struct List_001E6B30 {
    int m0;
    Node_001E6B30* m4;
    void Clear();
};
extern "C" void func_001E6250(Node_001E6B30* n);
extern "C" void func_001E8D20(Node_001E6B30* n);

void List_001E6B30::Clear()
{
    Node_001E6B30* n = m4;
    while (n) {
        Node_001E6B30* next = n->mC;
        func_001E6250(n);
        func_001E8D20(n);
        n = next;
    }
    m4 = 0;
}
