/* sym: SetA__13Node_00170CE0i = 0x00170730 */
/* sym: SetB__13Node_00170CE0i = 0x00170578 */
extern void* D_00388A70;
extern char D_003E0FE0[];
extern "C" void* func_0010A638(void* heap, int size, int a, int b);

class Node_00170CE0 {
public:
    char pad0[0x1C];
    unsigned int m1C;
    char pad20[0x40 - 0x20];
    char m40;
    char m41;
    unsigned short m42;
    void* m44;
    void SetA(int v);
    void SetB(int on);
};

extern "C" Node_00170CE0* func_0016DC80(void* mem, void* src);
extern "C" void func_0016DAF0(Node_00170CE0* n, void* mat);

Node_00170CE0* func_00170CE0(void* src, int v, int count, void* mats, void* mat)
{
    Node_00170CE0* n = func_0016DC80(func_0010A638(D_00388A70, 0x50, 1, 0), src);
    n->m1C |= 0x1800;
    n->SetA(v);
    n->m40 = count;
    n->m44 = mats;
    n->m42 = 0;
    if (mat)
        func_0016DAF0(n, mat);
    else
        func_0016DAF0(n, D_003E0FE0);
    n->SetB(1);
    return n;
}
