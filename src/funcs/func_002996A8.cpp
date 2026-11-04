struct Node_002996A8 {
    char pad[0x2C];
    Node_002996A8* next;
    Node_002996A8* prev;
};

extern "C" void func_00298508(Node_002996A8* n, int a, int b, float f);

struct Obj_002996A8 {
    char pad[0xC];
    Node_002996A8* head;
    void Run(int a, int b, float f);
};

void Obj_002996A8::Run(int a, int b, float f)
{
    Node_002996A8* last = 0;
    Node_002996A8* n;
    for (n = head; n; n = n->next)
        last = n;
    for (n = last; n; n = n->prev)
        func_00298508(n, a, b, f);
}
