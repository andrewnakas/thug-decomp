/* sym: _vt$13Node_00138E28 = 0x0035DE98 */
/* sym: _$_13List_00138E28 = 0x00139788 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct List_00138E28 {
    char pad[0x18];
    ~List_00138E28();
};

class Node_00138E28 {
public:
    int m0;
    short m4;
    List_00138E28* m8;
    int mC;
    virtual ~Node_00138E28() = 0;
    virtual void V1();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" void func_00138E90(Node_00138E28* self, int all);

Node_00138E28::~Node_00138E28()
{
    func_00138E90(this, 1);
    delete m8;
}
