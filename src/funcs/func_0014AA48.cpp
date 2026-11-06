extern float D_0038C0FC;
extern float D_0038C100;
extern "C" void func_0017EF28(void* p, unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1);

class Obj_0014AA48 {
public:
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    char pad[8];
    void* m_18;
    void Apply();
};

void Obj_0014AA48::Apply()
{
    int x = (int)(m_x * D_0038C0FC);
    int y = (int)(m_y * D_0038C100);
    int w = (int)(m_w * D_0038C0FC);
    int h = (int)(m_h * D_0038C100);
    func_0017EF28(m_18, x, y, x + w - 1, y + h - 1);
}
