/* sym: _$_11Base_2604C8 = 0x00104870 */
/* sym: _vt$11Derv_2604C8 = 0x003631E8 */
class Base_2604C8 {
public:
    int m00[6];
    virtual void Update();
    virtual ~Base_2604C8();
};

class Derv_2604C8 : public Base_2604C8 {
public:
    virtual void Update();
    virtual ~Derv_2604C8();
};

Derv_2604C8::~Derv_2604C8()
{
}
