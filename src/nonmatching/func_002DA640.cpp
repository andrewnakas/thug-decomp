/* fuzzy: 97.8 */
/* NM (wt2 r4): 3/90, same single-insn placement issue as func_002D6440 (see that file's first line for the PRE/loop.c diagnosis). */
/* sym: _vt$12Obj_002DA640 = 0x0037CAB8 */
/* sym: _vt$13Head_002DA640 = 0x0037CB18 */
/* sym: _vt$13Link_002DA640 = 0x0037CAE8 */
extern char D_0037C9E8[];
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Item_002DA640;

struct Node_002DA640 {
    int m0;
    Item_002DA640* m4;
    int m8;
    Node_002DA640* mC;
    Node_002DA640* m10;
    Item_002DA640* GetData() { return m4; }
    Node_002DA640* Valid(unsigned k = 0) { return k < ~(unsigned)m4 ? this : 0; }
};

struct Link_002DA640 : Node_002DA640 {
    virtual ~Link_002DA640() {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
    virtual void Key();
};

struct Item_002DA640 : Link_002DA640 {
    virtual void Key();
};

struct Head_002DA640 : Node_002DA640 {
    virtual ~Head_002DA640() {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
    virtual void Key();
};

struct Iter_002DA640 {
    int m0;
    Node_002DA640* m4;
    void* m8;
    Iter_002DA640() { m8 = D_0037C9E8; m4 = 0; }
    ~Iter_002DA640() { m8 = D_0037C9E8; }
    Item_002DA640* Next() {
        m4 = m4->mC->Valid();
        if (!m4) return 0;
        return m4->GetData();
    }
    Item_002DA640* Advance(Node_002DA640* c) {
        m4 = c->mC->Valid();
        if (!m4) return 0;
        return m4->GetData();
    }
    Item_002DA640* First(Node_002DA640* h) {
        m4 = h;
        return Next();
    }
};

struct Obj_002DA640 : Link_002DA640 {
    char pad18[4];
    Head_002DA640 m1C;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    virtual void Key();
    virtual ~Obj_002DA640();
};

Obj_002DA640::~Obj_002DA640()
{
    Iter_002DA640 it;
    Item_002DA640* d = it.First(&m1C);
    Iter_002DA640* q = &it;
    if (d) {
        do {
            Item_002DA640* nx = q->Advance(it.m4);
            delete d;
            d = nx;
        } while (d);
    }
}
