/* fuzzy: 90.0 */
struct Node_002BC5E0 {
    char pad[0xC];
    Node_002BC5E0* mC;
};

extern "C" void func_002BC5E0(Node_002BC5E0* list)
{
    if (!list)
        return;
    for (Node_002BC5E0* a = list->mC; a; a = a->mC) {
        for (Node_002BC5E0* b = a->mC; b; b = b->mC) {
        }
    }
}
