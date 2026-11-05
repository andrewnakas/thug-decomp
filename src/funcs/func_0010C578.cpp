/* sym: _vt$11It_0010C578 = 0x0035B540 */
/* sym: _$_12Sub_0010C578 = 0x0010C2B0 */
struct Sub_0010C578 {
    char pad[0x20];
    ~Sub_0010C578();
};

struct Node_0010C578 {
    int m0;
    Sub_0010C578* m4;
    int m8;
    Node_0010C578* mC;
    Node_0010C578* Valid() { if (~(int)m4 == 0) return 0; return this; }
    Sub_0010C578* GetData() { return m4; }
};

class It_0010C578 {
public:
    int m0;
    Node_0010C578* cur;
    It_0010C578() {}
    virtual ~It_0010C578() {}
    virtual void Run();
    Sub_0010C578* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Sub_0010C578* First(Node_0010C578* h)
    {
        cur = h;
        return Next();
    }
};

struct Obj_0010C578 {
    char pad[0x40];
    Sub_0010C578* m40;
    int m44;
    Node_0010C578 m48;
    void Reset();
};

void Obj_0010C578::Reset()
{
    delete m40;
    It_0010C578 it;
    m40 = it.First(&m48);
}
