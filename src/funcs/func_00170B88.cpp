/* sym: SetFlag2__13Node_00170B88i = 0x001705C8 */
extern char D_003E0FE0[];
extern char D_003E1030[];

class Node_00170B88 {
public:
    void SetFlag2(int on);
    void Fn(unsigned int flags);
};

extern "C" void func_0016DAF0(Node_00170B88* n, void* mat);

void Node_00170B88::Fn(unsigned int flags)
{
    func_0016DAF0(this, (flags & 1) ? D_003E0FE0 : D_003E1030);
    if (flags & 2)
        SetFlag2(1);
}
