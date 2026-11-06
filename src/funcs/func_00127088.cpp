/* sym: _$_13Menu_00127088 = 0x001304E0 */
/* sym: _$_13Base_00127088 = 0x001238D0 */
/* sym: _vt$13Elem_00127088 = 0x0035CCF8 */
class Menu_00127088 {
public:
    int m0;
    ~Menu_00127088();
};

class Base_00127088 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual ~Base_00127088();
};

class Elem_00127088 : public Base_00127088 {
public:
    char padC[0x1D4 - 0xC];
    Menu_00127088* m_menu;
    virtual void V0();
    virtual ~Elem_00127088();
};

Elem_00127088::~Elem_00127088()
{
    if (m_menu) {
        delete m_menu;
    }
}
