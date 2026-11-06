/* sym: _$_13Item_0014A4A0 = 0x00135780 */
/* sym: _vt$12Snd_0014A4A0 = 0x0035F2F0 */
class Item_0014A4A0 {
public:
    int m0;
    virtual ~Item_0014A4A0();
    virtual void Run();
};

class Snd_0014A4A0;
extern "C" void func_0014A598(Snd_0014A4A0* self);

class Snd_0014A4A0 : public Item_0014A4A0 {
public:
    void* m8;
    virtual void Run();
    virtual ~Snd_0014A4A0();
};

Snd_0014A4A0::~Snd_0014A4A0()
{
    if (m8)
        func_0014A598(this);
}
