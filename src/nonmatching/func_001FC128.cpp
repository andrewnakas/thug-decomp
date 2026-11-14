/* fuzzy: 92.6 */
/* blocked: only a $s3/$s4 swap and which of q/&it the First store and the Advance load use remain; directed
   search: no match. */
/* sym: _vt$11It_001FC128 = 0x00366A48 */
class Handler_001FC128 {
public:
    char pad0[0x14];
    virtual ~Handler_001FC128();
};

struct Node_001FC128 {
    int m0;
    Handler_001FC128* m4;
    int m8;
    Node_001FC128* mC;
    int m10;
    int m14;
    Node_001FC128* Valid() { if (~(int)m4 == 0) return 0; return this; }
    Handler_001FC128* GetData() { return m4; }
};

class It_001FC128 {
public:
    int m0;
    Node_001FC128* cur;
    It_001FC128() {}
    virtual ~It_001FC128() {}
    virtual void Run();
    Handler_001FC128* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Handler_001FC128* Advance(Node_001FC128* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Handler_001FC128* First(Node_001FC128* h)
    {
        cur = h;
        return Next();
    }
};

void func_001FC128(Node_001FC128* table)
{
    for (int i = 0; i < 255; i++) {
        It_001FC128 it;
        It_001FC128* q = &it;
        Handler_001FC128* h = q->First(&table[i]);
        if (h) {
            It_001FC128* p = &it;
            do {
                Handler_001FC128* next = p->Advance(q->cur);
                delete h;
                h = next;
            } while (h);
        }
    }
}
