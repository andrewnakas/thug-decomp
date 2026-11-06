extern "C" int func_0013DA40(void* scene);

class Comp_0018C1C0 {
public:
    char pad0[0x260];
    void* m_scene;
    char pad264[0xC];
    float m_values[4];
    int m_count;

    bool Push(float v);
};

bool Comp_0018C1C0::Push(float v)
{
    if (m_count < 4 && func_0013DA40(m_scene)) {
        m_values[m_count] = v;
        m_count++;
        return true;
    }
    return false;
}
