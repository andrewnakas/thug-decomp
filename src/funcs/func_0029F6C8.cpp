struct Item_0029F6C8 {
    char pad[0x14];
    void* m14;
};

struct Node_0029F6C8 {
    int m0;
    Item_0029F6C8* m4;
    int m8;
    Node_0029F6C8* mC;
    int m10;
    virtual ~Node_0029F6C8();
    Node_0029F6C8* Valid() { return (int)m4 != -1 ? this : 0; }
};

extern "C" void func_00200F28(void* a, void* b);
extern "C" void func_002B3168(Item_0029F6C8* it, int flags);

struct Obj_0029F6C8 {
    char pad[0x14];
    void* m14;
    char pad2[0x100 - 0x18];
    Node_0029F6C8* m100;
    void Clear();
};

void Obj_0029F6C8::Clear()
{
    Node_0029F6C8* nx;
    for (Node_0029F6C8* n = m100->Valid(); n; n = nx) {
        nx = n->mC->Valid();
        Item_0029F6C8* it = n->m4;
        if (m14)
            func_00200F28(m14, it->m14);
        delete n;
        if (it)
            func_002B3168(it, 3);
    }
}
