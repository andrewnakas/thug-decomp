extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Item_00250A18 {
public:
    int m0;
    virtual ~Item_00250A18() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Item_00250A18::~Item_00250A18()
{
}
