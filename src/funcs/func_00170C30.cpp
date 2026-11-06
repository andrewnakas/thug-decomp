/* sym: SetA__13Node_00170C30i = 0x00170730 */
/* sym: SetB__13Node_00170C30i = 0x00170578 */
extern void* D_00388A70;
extern char D_003E0FE0[];
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

class Node_00170C30 {
public:
    char pad0[0x1C];
    unsigned int m1C;
    void SetA(int v);
    void SetB(int on);
};

extern "C" Node_00170C30* func_0016DC80(void* mem, void* src);
extern "C" void func_0016DAF0(Node_00170C30* n, void* mat);

Node_00170C30* func_00170C30(void* src, int v, void* mat)
{
    Node_00170C30* n = func_0016DC80(func_0010A638(D_00388A70, 0x50, 1, 0), src);
    n->m1C |= 0x1000;
    n->SetA(v);
    if (mat)
        func_0016DAF0(n, mat);
    else
        func_0016DAF0(n, D_003E0FE0);
    n->SetB(1);
    return n;
}
