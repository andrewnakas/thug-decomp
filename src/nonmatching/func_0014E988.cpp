/* fuzzy: 92.9 */
/* blocked: the game keeps model+0x24 in $v0 (0x14EA28) and adds 4 for the data pointer; cse folds ours to +0x28. GetData/GetType, a reference and split locals all fold */
/* sym: __13Base_0014E988i = 0x00143030 */
/* sym: _vt$12Der_0014E988 = 0x0035F848 */
extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" int func_00170728(void* o);

struct Hdr_0014E988 {
    unsigned short m0;
    unsigned short m2;
    char* GetData() { return (char*)(this + 1); }
    int GetType() { return m2 & 0xF; }
};

struct Model_0014E988 {
    char pad0[0x24];
    Hdr_0014E988 m24;
    Hdr_0014E988* GetHdr() { return &m24; }
};

extern "C" Model_0014E988* func_00170650(void* o);

struct Elem_0014E988 {
    char m0[0x20];
    Elem_0014E988() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

class Base_0014E988 {
public:
    char pad0[0x24];
    Base_0014E988(int n);
    virtual ~Base_0014E988();
    virtual void F();
};

class Der_0014E988 : public Base_0014E988 {
public:
    void* m28;
    Elem_0014E988* m2C;
    char* m30;
    int m34;
    Der_0014E988(int n, void* p);
    virtual ~Der_0014E988();
    virtual void F();
};

Der_0014E988::Der_0014E988(int n, void* p) : Base_0014E988(n)
{
    m28 = p;
    m2C = new Elem_0014E988[n * 3];
    if (func_00170728(p)) {
        Hdr_0014E988* h = func_00170650(p)->GetHdr();
        m34 = h->m2 & 0xF;
        m30 = (char*)((int)h + 4);
    } else {
        m30 = 0;
        m34 = 0;
    }
}
