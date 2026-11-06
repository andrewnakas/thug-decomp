struct Rect_00130780 {
    int m[6];
};

extern "C" int func_0010FC30();

class Fade_00130780 {
public:
    char pad0[0x500];
    Rect_00130780 m_target;
    Rect_00130780 m_start;
    int m_time;
    int m_done;
    void Start(int instant);
};

void Fade_00130780::Start(int instant)
{
    if (!instant) {
        m_start = m_target;
    }
    m_done = instant;
    m_time = func_0010FC30();
}
