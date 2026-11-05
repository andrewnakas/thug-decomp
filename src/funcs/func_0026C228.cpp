extern void* D_00391360;
extern void* D_00388A70;
extern "C" void func_0026C878(void* p);
extern "C" void* func_0026C888(void* p, int a);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_0026C938(void* p, int* key);

struct Node_0026C228 {
    char pad[0xC];
    int mC;
};

void Flush_0026C228()
{
    if (!D_00391360)
        return;
    func_0026C878(D_00391360);
    Node_0026C228* p = (Node_0026C228*)func_0026C888(D_00391360, 0);
    while (p) {
        Node_0026C228* next = (Node_0026C228*)func_0026C888(D_00391360, 0);
        int key = p->mC;
        func_0010A8D8(D_00388A70, p);
        func_0026C938(D_00391360, &key);
        p = next;
    }
}
