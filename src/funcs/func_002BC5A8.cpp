struct Node_002BC5A8 {
    char pad[0xC];
    Node_002BC5A8* mC;
};

extern "C" void func_002C44D0(Node_002BC5A8* n);

void FreeAll_002BC5A8(Node_002BC5A8* n)
{
    while (n) {
        Node_002BC5A8* next = n->mC;
        func_002C44D0(n);
        n = next;
    }
}
