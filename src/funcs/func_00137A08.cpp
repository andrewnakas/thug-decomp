/* sym: _vt$13Item_00137A08 = 0x0035DAC0 */
struct Vec_00137A08 {
    float x, y, z;
};

class Item_00137A08 {
public:
    Vec_00137A08 m_pos;
    float m_scale[2];
    int m14;
    Item_00137A08();
    virtual void V0();
};

Item_00137A08::Item_00137A08()
{
    m_pos.x = m_pos.y = 0.0f;
    m_pos.z = 1.0f;
    for (int i = 1; i >= 0; i--)
        m_scale[i] = 1.0f;
    m14 = 0;
}
