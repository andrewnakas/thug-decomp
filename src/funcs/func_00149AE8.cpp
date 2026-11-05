/* sym: __13Node_00149AE8PCci = 0x00138DA8 */
/* sym: _vt$13Tree_00149AE8 = 0x0035F148 */
class Node_00149AE8 {
public:
    int m0;
    short m4;
    void* m8;
    int mC;
    Node_00149AE8(const char* name, int withList);
    virtual ~Node_00149AE8();
};

class Tree_00149AE8;
extern "C" void func_00149D10(Tree_00149AE8* t, const char* name, int a, int b, bool flag, int c, int d, int e);

class Tree_00149AE8 : public Node_00149AE8 {
public:
    Tree_00149AE8(const char* name, bool flag, int c, int d, int e);
    virtual ~Tree_00149AE8();
};

Tree_00149AE8::Tree_00149AE8(const char* name, bool flag, int c, int d, int e)
    : Node_00149AE8(name, !flag)
{
    func_00149D10(this, name, 0, 0, flag, c, d, e);
}
