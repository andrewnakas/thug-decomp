/* fuzzy: 97.8 */
/* NM (wt2 r4): 3/90 words, only `daddu s3,sp` (p=&it) placement: game has it after the loop-entry beqz, ours (p=&it before while) before it. Diagnosis (gcse dump): with any explicit block between the entry test and the loop (if(d){p=&it; do/while}, if(!d)goto, while-inside-if) PRE inserts the post-loop exprs (Head/Base vtable %hi, this+0x34, in_chrg&1) at the end of BOTH bb3 and bb4 -> two sets, no REG_EQUIV, s4/s5 kept, size 0x178. The game's RTL had no bb4 at gcse time (single insertion in bb3, %hi rematerialised), so s3 must have been created by loop.c after gcse; but p set inside the loop is folded to sp by cse (it is at frame offset 0, so (plus p 4) -> (plus fp 4)), size 0x15c. `if (d) p = &it;` before the while becomes movn s3,sp,a2. Unsolved. */
/* NEAR MISS 3/90 (r2 wt2): only scheduling: game puts daddu s3,sp (p=&it) after the loop-entry beqz (s0=this+0x34 in its delay slot); ours before. if(d){p=&it;...} changes size. r3 wt2: if(d){p=&it; do/while} and while forms: size 0x178 (vtable hi parts hoisted into s4/s5); p inside loop / it.Advance / it.Next: size 0x15c. */
/* sym: _vt$12Obj_002D6440 = 0x0037C1F0 */
/* sym: _vt$13Base_002D6440 = 0x0037C220 */
/* sym: _vt$13Head_002D6440 = 0x0037C250 */
/* sym: _vt$11It_002D6440 = 0x0037C180 */
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Item_002D6440 {
    char pad[0x14];
    virtual ~Item_002D6440();
};

struct Node_002D6440 {
    int m0;
    Item_002D6440* data;
    int m8;
    Node_002D6440* next;
    Node_002D6440* prev;
    Item_002D6440* GetData() { return data; }
    Node_002D6440* Valid() { return (int)data != -1 ? this : 0; }
    void Unlink()
    {
        prev->next = next;
        next->prev = prev;
        next = this;
        prev = this;
    }
};

struct It_002D6440 {
    int m0;
    Node_002D6440* cur;
    virtual void f();
    It_002D6440() {}
    virtual ~It_002D6440() {}
    Item_002D6440* Next()
    {
        cur = cur->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Item_002D6440* Advance(Node_002D6440* c)
    {
        cur = c->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Item_002D6440* First(Node_002D6440* h)
    {
        cur = h;
        return Advance(h);
    }
};

struct Head_002D6440 : Node_002D6440 {
    virtual void f();
    virtual ~Head_002D6440() { Unlink(); }
};

struct Base_002D6440 : Node_002D6440 {
    virtual void f();
    virtual ~Base_002D6440() { Unlink(); }
};

struct Obj_002D6440 : Base_002D6440 {
    char pad18[0x34 - 0x18];
    Head_002D6440 m34;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    virtual void f();
    virtual ~Obj_002D6440();
};

Obj_002D6440::~Obj_002D6440()
{
    It_002D6440 it;
    Item_002D6440* d = it.First(&m34);
    It_002D6440* p = &it;
    while (d) {
        Item_002D6440* n = p->Advance(it.cur);
        delete d;
        d = n;
    }
}
