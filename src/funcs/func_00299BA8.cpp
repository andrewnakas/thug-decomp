struct Node_00299BA8 {
    char pad[0x2C];
    Node_00299BA8* next;
    Node_00299BA8* prev;
};

extern "C" void func_002984B8(Node_00299BA8* n, int flags);
extern "C" int func_0029C580();
extern "C" void func_00298BF8(Node_00299BA8* n);

struct Obj_00299BA8 {
    char pad[0xC];
    Node_00299BA8* head;

    Node_00299BA8* Remove(Node_00299BA8* n);
};

Node_00299BA8* Obj_00299BA8::Remove(Node_00299BA8* n)
{
    if (!n)
        return 0;
    if (n->prev && n->next && func_0029C580() == 200)
        return 0;
    if (n == head) {
        head = n->next;
        if (n->next)
            n->next->prev = 0;
        if (n)
            func_002984B8(n, 3);
        return 0;
    }
    func_00298BF8(n->prev);
    n->prev->next = 0;
    Node_00299BA8* next = n->next;
    if (n)
        func_002984B8(n, 3);
    if (next)
        next->prev = 0;
    return next;
}
