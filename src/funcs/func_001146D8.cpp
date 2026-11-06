extern unsigned int D_00388830;
extern "C" float func_0010FAB8();

struct Timer_001146D8 {
    char pad[0x20];
    int m_time;
};

class Obj_001146D8 {
public:
    char pad[0x20];
    Timer_001146D8* m_timer;
    void Tick();
};

void Obj_001146D8::Tick()
{
    Timer_001146D8* t = m_timer;
    float scale = func_0010FAB8();
    float ticks = (float)(1000 / D_00388830) * 60.0f;
    t->m_time += (int)(scale * ticks);
}
