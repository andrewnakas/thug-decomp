struct Rect_00130730 {
    int m[6];
};

class Fade_00130730;
extern "C" void func_00130780(Fade_00130730* self, int instant);

class Fade_00130730 {
public:
    char pad0[0x500];
    Rect_00130730 m_target;
    void SetTarget(const Rect_00130730* r, int instant);
};

void Fade_00130730::SetTarget(const Rect_00130730* r, int instant)
{
    m_target = *r;
    func_00130780(this, instant);
}
