/* sym: _$_13Quad_0014A688 = 0x00135A38 */
/* sym: _vt$12Spr_0014A688 = 0x0035F2B0 */
class Anim_0014A688 {
public:
    char pad[0x18];
    virtual ~Anim_0014A688();
};

class Quad_0014A688 {
public:
    char pad[0x38];
    virtual ~Quad_0014A688();
};

class Spr_0014A688 : public Quad_0014A688 {
public:
    Anim_0014A688* m40;
    virtual void V1();
    virtual ~Spr_0014A688();
};

Spr_0014A688::~Spr_0014A688()
{
    delete m40;
}
