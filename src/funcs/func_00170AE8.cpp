/* sym: SetFlag2__13Node_00170AE8i = 0x001705C8 */
extern char D_003E0FE0[];
extern char D_003E1030[];

class Node_00170AE8 {
public:
    void SetFlag2(int on);
};

extern "C" int func_0016D828(Node_00170AE8* n, char* base);
extern "C" void func_0016DAF0(Node_00170AE8* n, void* mat);

Node_00170AE8* func_00170AE8(char* data, unsigned int flags)
{
    char* base = data + *(int*)data;
    Node_00170AE8* n = (Node_00170AE8*)(base + *(int*)base);
    func_0016D828(n, base);
    func_0016DAF0(n, (flags & 1) ? D_003E0FE0 : D_003E1030);
    if (flags & 2)
        n->SetFlag2(1);
    return n;
}
