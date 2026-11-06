/* sym: _$_13Quad_0014A1C8 = 0x0013B8B8 */
/* sym: _vt$12Spr_0014A1C8 = 0x0035F270 */
class Anim_0014A1C8 {
public:
    char pad[0x18];
    virtual ~Anim_0014A1C8();
};

class Quad_0014A1C8 {
public:
    char pad[0x3C];
    virtual ~Quad_0014A1C8();
};

class Spr_0014A1C8 : public Quad_0014A1C8 {
public:
    Anim_0014A1C8* m40;
    virtual void V1();
    virtual ~Spr_0014A1C8();
};

Spr_0014A1C8::~Spr_0014A1C8()
{
    delete m40;
}
