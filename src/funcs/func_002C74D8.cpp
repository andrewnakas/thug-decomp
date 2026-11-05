struct Node_002C74D8 {
    char pad0[0x14];
    Node_002C74D8* m14;
};

extern "C" void func_002CE490(Node_002C74D8* n);

struct Obj_002C74D8 {
    char pad0[0x68];
    Node_002C74D8* m68;
    void UpdateAll();
};

void Obj_002C74D8::UpdateAll()
{
    for (Node_002C74D8* n = m68; n; n = n->m14)
        func_002CE490(n);
}
