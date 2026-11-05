/* sym: _vt$13Item_00135780 = 0x0035D848 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Item_00135780 {
public:
    int m0;
    virtual ~Item_00135780() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Item_00135780::~Item_00135780()
{
}
