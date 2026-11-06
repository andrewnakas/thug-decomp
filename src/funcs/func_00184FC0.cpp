/* sym: _vt$13Emit_00184FC0 = 0x00361A48 */
/* sym: _$_13Base_00184FC0 = 0x00183D80 */

extern void* D_0038C608;

class Item_00184FC0 {
public:
    char pad0[0x10];
    Item_00184FC0* m_next;
    int m14;
    virtual ~Item_00184FC0();
};

extern "C" void func_00187320(void* mgr, Item_00184FC0* item);

class Base_00184FC0 {
public:
    int m0;
    void* m4;
    virtual ~Base_00184FC0();
};

class Emit_00184FC0 : public Base_00184FC0 {
public:
    char padC[0xF4];
    Item_00184FC0* m_items;

    virtual void Key();
    virtual ~Emit_00184FC0();
};

Emit_00184FC0::~Emit_00184FC0()
{
    while (m_items) {
        Item_00184FC0* item = m_items;
        m_items = item->m_next;
        func_00187320(D_0038C608, item);
        delete item;
    }
}
