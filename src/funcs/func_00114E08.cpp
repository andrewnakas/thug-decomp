typedef int qword __attribute__((mode(TI)));

union Vec114E08 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Obj114E08 {
    char pad[0x60];
    Vec114E08 m60;
    void Set60(const Vec114E08& v);
};

void Obj114E08::Set60(const Vec114E08& v)
{
    m60 = v;
}
