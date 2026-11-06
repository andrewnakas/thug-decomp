struct Node_0016DCB8 {
    char pad0[0x20];
    Node_0016DCB8* m20;
    int m24;
    Node_0016DCB8* m28;
    void Fn(void* a, void* b);
};

extern "C" int func_00177A58(Node_0016DCB8* self);
extern "C" void func_0016DD28(Node_0016DCB8* self, void* a, void* b);

void Node_0016DCB8::Fn(void* a, void* b)
{
    if (!func_00177A58(this))
        return;
    for (Node_0016DCB8* c = m20; c; c = c->m28)
        func_0016DD28(c, a, b);
}
