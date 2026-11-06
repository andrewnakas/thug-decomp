/* sym: __12Obj_0011B5D0i = 0x0011AB88 */
/* sym: _vt$13Item_0011B5D0 = 0x0035C968 */
class Obj_0011B5D0 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    Obj_0011B5D0(int a);
    virtual ~Obj_0011B5D0();
};

class Item_0011B5D0 : public Obj_0011B5D0 {
public:
    int m18;
    int m1C;
    Item_0011B5D0(int a);
    virtual ~Item_0011B5D0();
};

Item_0011B5D0::Item_0011B5D0(int a)
    : Obj_0011B5D0(a)
{
    m18 = 0;
    m1C = 0;
}
