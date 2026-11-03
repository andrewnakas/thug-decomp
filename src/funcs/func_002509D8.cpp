extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Item_002509D8 {
public:
    int m0;
    virtual ~Item_002509D8() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Item_002509D8::~Item_002509D8()
{
}
