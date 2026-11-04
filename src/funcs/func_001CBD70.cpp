extern "C" float sqrtf(float);

struct Vec_001CBD70 {
    float x, y, z, w;
};

struct Node_001CBD70 {
    char m_pad[0x50];
    Node_001CBD70* m50;
    Node_001CBD70* m54;
};

struct Obj_001CBD70 {
    char m_pad[0xA1C];
    Node_001CBD70* mA1C;
    int m_padA20;
    void* mA24;
    char m_padA28[0xBF0 - 0xA28];
    float mBF0;
    void StartRailEnd();
};

extern "C" void func_0026B1B0(Vec_001CBD70* out, void* rails, Node_001CBD70* node);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void func_001BF130(Obj_001CBD70* self, int state);

void Obj_001CBD70::StartRailEnd()
{
    Node_001CBD70* next = mA1C->m50;
    if (!next)
        next = mA1C->m54;
    Vec_001CBD70 d;
    Vec_001CBD70 a;
    func_0026B1B0(&a, mA24, next);
    Vec_001CBD70 b;
    func_0026B1B0(&b, mA24, mA1C);
    d.x = a.x - b.x;
    d.y = a.y - b.y;
    d.z = a.z - b.z;
    d.w = a.w - b.w;
    float len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
    float dist;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0x76BF49E0, &dist, 1);
    mBF0 = (len - dist) / len;
    func_001BF130(this, 3);
}
