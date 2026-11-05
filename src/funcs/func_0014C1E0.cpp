/* sym: __13Elem_0014C1E0 = 0x001467C8 */
/* sym: __13Data_0014C1E0 = 0x0014D048 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_001046B0(int size);
extern void* D_00388A70;

struct Node_0014C1E0;

class Data_0014C1E0 {
public:
    char pad[0x20];
    Node_0014C1E0* m20;
    char pad24[0x5C];
    Data_0014C1E0();
    static void* operator new(unsigned int n) { return func_001046B0(n); }
};

class Elem_0014C1E0 {
public:
    char pad[0x30];
    int m30;
    char pad34[0x5C];
    Elem_0014C1E0();
    static void* operator new(unsigned int n) { return func_0010A638(D_00388A70, n, 1, 0); }
};

struct Scrn_0014C1E0;

extern "C" int func_00170528(Node_0014C1E0* n);
extern "C" int func_00170630(Node_0014C1E0* n);
extern "C" Node_0014C1E0* func_00170680(Node_0014C1E0* n);
extern "C" Node_0014C1E0* func_00170718(Node_0014C1E0* n);
extern "C" Elem_0014C1E0* func_00132FD0(Scrn_0014C1E0* s, int id);
extern "C" void func_00132FF8(Scrn_0014C1E0* s, Elem_0014C1E0* e);
extern "C" void func_00134F10(Elem_0014C1E0* e, int id);
extern "C" void func_00134F20(Elem_0014C1E0* e, Data_0014C1E0* d);

extern "C" void func_0014C1E0(Scrn_0014C1E0* self, Node_0014C1E0* n)
{
    while (n) {
        if (func_00170528(n)) {
            Elem_0014C1E0* e = func_00132FD0(self, func_00170630(n));
            if (!e) {
                e = new Elem_0014C1E0;
                func_00134F10(e, func_00170630(n));
                Data_0014C1E0* d = new Data_0014C1E0;
                d->m20 = n;
                func_00134F20(e, d);
                func_00132FF8(self, e);
            }
            e->m30 = 0;
        } else {
            func_0014C1E0(self, func_00170680(n));
        }
        n = func_00170718(n);
    }
}
