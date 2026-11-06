extern void* D_00391360;
extern "C" void func_0026C878(void* p);
extern "C" void* func_0026C888(void* p, int a);

struct Node_0026C408 {
    int m0;
    int m4;
    char pad[0x30 - 0x8];
    bool m30;
};

void Set_0026C408(int id, int on)
{
    func_0026C878(D_00391360);
    Node_0026C408* p = (Node_0026C408*)func_0026C888(D_00391360, 0);
    while (p) {
        if (p->m4 == id) {
            p->m30 = on;
            return;
        }
        p = (Node_0026C408*)func_0026C888(D_00391360, 0);
    }
}
