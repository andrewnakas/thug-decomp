struct Node_00299748 {
    char pad[0x2C];
    Node_00299748* m2C;
};

extern "C" void func_002987C8(Node_00299748* n, void* a, void* b, float t);

struct Obj_00299748 {
    char pad[0xC];
    Node_00299748* mC;
    void UpdateAll(void* a, void* b, float t);
};

void Obj_00299748::UpdateAll(void* a, void* b, float t)
{
    for (Node_00299748* n = mC; n; n = n->m2C)
        func_002987C8(n, a, b, t);
}
