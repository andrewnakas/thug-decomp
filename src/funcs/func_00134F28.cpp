struct Rgba_00134F28 {
    unsigned char r, g, b, a;
    Rgba_00134F28(const Rgba_00134F28& o) { *this = o; }
};

struct Target_00134F28;
extern "C" void func_0013C438(Target_00134F28* t, Rgba_00134F28 c);

class Obj_00134F28 {
public:
    int m[8];
    Target_00134F28* m20;
    void SetColor(Rgba_00134F28 c);
};

void Obj_00134F28::SetColor(Rgba_00134F28 c)
{
    if (m20) {
        func_0013C438(m20, c);
    }
}
