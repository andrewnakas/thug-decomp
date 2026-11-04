extern "C" void* func_002BC5A0(void* n);
extern "C" void func_002C44D0(void* p);

struct Node_002C2588 {
    char pad0[0xC];
    Node_002C2588* mC;
};

struct Obj_002C2588 {
    void Remove(void* key, Node_002C2588** head);
};

void Obj_002C2588::Remove(void* key, Node_002C2588** head)
{
    Node_002C2588* prev = 0;
    for (Node_002C2588* n = *head; n; n = n->mC) {
        if (func_002BC5A0(n) == key) {
            if (prev) prev->mC = n->mC;
            else *head = n->mC;
            func_002C44D0(n);
            return;
        }
        prev = n;
    }
}
