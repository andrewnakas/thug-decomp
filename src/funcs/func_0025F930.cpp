class Node_0025F930 {
public:
    int m0;
    int m4;
    int m8;
    Node_0025F930* mC;
    Node_0025F930* m10;
    virtual ~Node_0025F930();
    void Remove()
    {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
};

struct List_0025F930 {
    bool PopFront();
};

extern "C" Node_0025F930* func_0025F1C8(List_0025F930* l);
extern "C" Node_0025F930* func_0025F128(List_0025F930* l, int i);
extern "C" void func_0025F620(List_0025F930* l, int i);

bool List_0025F930::PopFront()
{
    Node_0025F930* n = func_0025F1C8(this);
    if (n) {
        if (n == func_0025F128(this, 0)) {
            func_0025F620(this, 0);
            return true;
        }
        n->Remove();
        delete n;
        return true;
    }
    return false;
}
