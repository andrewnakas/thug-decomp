struct Node_002BC5E0 {
    char pad[0xC];
    Node_002BC5E0* mC;
};

// Walks every pair (a, b) of the chain with b after a; the per-pair work is compiled out
// (the inner loop is an empty, short-loop-padded bnel loop in the game).
extern "C" void func_002BC5E0(Node_002BC5E0* list)
{
    for (Node_002BC5E0* a = list; a; a = a->mC) {
        for (Node_002BC5E0* b = a->mC; b; b = b->mC) {
        }
    }
}
