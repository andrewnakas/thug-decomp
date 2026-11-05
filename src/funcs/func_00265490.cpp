/* sym: _vt$14Store_00265490 = 0x00376000 */
/* sym: _$_12Mem_00265490 = 0x00266848 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_00266100(void* self);
extern void* D_00388A70;

struct Mem_00265490 {
    int m[6];
    ~Mem_00265490();
};

class Store_00265490 {
public:
    int m0;
    int m4;
    Mem_00265490 m8;
    Mem_00265490 m20;
    int m38;
    virtual void Update();
    virtual ~Store_00265490();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Store_00265490::~Store_00265490()
{
    func_00266100(this);
}
