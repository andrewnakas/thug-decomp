/* sym: __13Base_001D1AD0 = 0x001D0FB0 */
/* sym: _vt$12Obj_001D1AD0 = 0x00363D80 */

struct Owner_001D1AD0;

class Base_001D1AD0 {
public:
    char pad[0xC];
    unsigned char mC;
    char padD[3];
    int m10;
    Base_001D1AD0* m14;
    char pad18[8];
    Base_001D1AD0();
    virtual void Update();
};

class Obj_001D1AD0 : public Base_001D1AD0 {
public:
    Owner_001D1AD0* m24;
    Obj_001D1AD0* m28;
    Obj_001D1AD0(Owner_001D1AD0* o);
    virtual void Update();
};

struct Owner_001D1AD0 {
    char pad[0xC];
    unsigned char mC;
    char padD[7];
    Obj_001D1AD0* m14;
};

Obj_001D1AD0::Obj_001D1AD0(Owner_001D1AD0* o)
{
    m24 = o;
    m28 = 0;
    if (!o->m14) {
        o->m14 = this;
    } else {
        Obj_001D1AD0* head = o->m14;
        o->m14 = this;
        m28 = head;
    }
    m10 = 0;
    mC = o->mC;
}
