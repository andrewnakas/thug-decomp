/* sym: __13Base_0010D0B0Pvii = 0x0010C3A8 */
/* sym: _vt$13Heap_0010D0B0 = 0x0035B628 */
class Base_0010D0B0 {
public:
    int m[32];
    Base_0010D0B0(void* region, int dir, int name);
    virtual void Key();
};

class Heap_0010D0B0 : public Base_0010D0B0 {
public:
    Heap_0010D0B0(void* region, int dir, int name);
    virtual void Key();
};

Heap_0010D0B0::Heap_0010D0B0(void* region, int dir, int name)
    : Base_0010D0B0(region, dir, name)
{
}
