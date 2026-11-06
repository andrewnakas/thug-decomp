/* sym: _vt$13Node_0014AE70 = 0x0035F378 */
extern "C" void* func_001046B0(int size);

class Node_0014AE70 {
public:
    int m0;
    int m4;
    int m8;
    Node_0014AE70* mC;
    Node_0014AE70* m10;
    Node_0014AE70(int key)
    {
        m4 = key;
        m8 = 0;
        mC = this;
        m10 = this;
    }
    virtual ~Node_0014AE70();
    static void* operator new(unsigned int n) { return func_001046B0(n); }
};

extern Node_0014AE70 D_003CBDC8;

extern "C" bool func_0014AE70(int key)
{
    Node_0014AE70* n = new Node_0014AE70(key);
    if (n) {
        n->m10 = D_003CBDC8.m10;
        n->mC = &D_003CBDC8;
        D_003CBDC8.m10->mC = n;
        D_003CBDC8.m10 = n;
        return true;
    }
    return false;
}
