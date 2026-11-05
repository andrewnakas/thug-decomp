struct Node_002B62C0 {
    char pad0[0x28];
    Node_002B62C0* m28;
};

extern "C" void func_002B6860(void* p, Node_002B62C0* n);

struct List_002B62C0 {
    int m0;
    int m4;
    Node_002B62C0* m8;
    Node_002B62C0* mC;
    short m10;
    char pad12[0x18 - 0x12];
    void* m18;
    void Clear();
};

void List_002B62C0::Clear()
{
    Node_002B62C0* n = m8;
    while (n) {
        Node_002B62C0* next = n->m28;
        func_002B6860(m18, n);
        n = next;
    }
    m8 = 0;
    mC = 0;
    m10 = 0;
}
