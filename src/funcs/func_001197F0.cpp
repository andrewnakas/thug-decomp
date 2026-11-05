extern "C" float func_001194A8(void* self);

struct Obj_001197F0 {
    int m0[7];
    float m_1C;
    void Update();
};

void Obj_001197F0::Update()
{
    m_1C = func_001194A8(this);
}
