/* sym: Detach__13Node_00170DB0P13Node_00170DB0 = 0x0016DB28 */
/* sym: DetachDeep__13Node_00170DB0P13Node_00170DB0 = 0x0016DB90 */
extern void* D_00388A70;
extern char D_003E0FE0[];
extern "C" void func_0010A8D8(void* heap, void* p);

struct Node_00170DB0 {
    bool Detach(Node_00170DB0* parent);
    bool DetachDeep(Node_00170DB0* parent);
};

void func_00170DB0(Node_00170DB0* n)
{
    if (!n->Detach((Node_00170DB0*)D_003E0FE0))
        n->DetachDeep((Node_00170DB0*)D_003E0FE0);
    if (n)
        func_0010A8D8(D_00388A70, n);
}
