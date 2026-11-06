/* sym: _$_13Node_00149B80 = 0x00138E28 */
/* sym: _vt$13Tree_00149B80 = 0x0035F148 */
class Node_00149B80 {
public:
    int m0;
    short m4;
    void* m8;
    int mC;
    virtual ~Node_00149B80();
    virtual void V1();
};

class Tree_00149B80;
extern "C" int func_00149DD0(Tree_00149B80* t);

class Tree_00149B80 : public Node_00149B80 {
public:
    virtual void V1();
    virtual ~Tree_00149B80();
};

Tree_00149B80::~Tree_00149B80()
{
    func_00149DD0(this);
}
