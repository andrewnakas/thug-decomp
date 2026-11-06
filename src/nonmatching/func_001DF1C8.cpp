/* fuzzy: 95.9 */
struct Pos_001DF1C8 {
    float x;
    float y;
};

struct Chan_001DF1C8 {
    int m_id;
    int m_handle;
    char pad8[8];
    int m_voice;
    int m_priority;
    unsigned int m_time;
    char pad1C[8];
    int m_24;
};

extern Chan_001DF1C8 D_003EE8E0[3];

extern "C" bool func_001DED40();
extern "C" int func_001E3C58(int voice);
extern "C" bool func_001E39E8(void* snd, int voice);
extern "C" bool func_001E3868(void* snd, int voice, float x, float y, float vol);
extern "C" int func_001DEEA0(int id);
extern "C" long func_0010FA80();
extern "C" int func_001E13A0(void* snd);
extern "C" void func_001E3978(int voice, int a);

int Audio_001DF1C8_Play(void* snd, Pos_001DF1C8* pos, int priority, int id, int stream, float vol)
{
    if (func_001DED40()) {
        return -1;
    }
    int best = 0;
    int bestPriority = D_003EE8E0[0].m_priority;
    unsigned int bestTime = D_003EE8E0[0].m_time;
    for (int i = 0; i < 3; i++) {
        if (func_001E3C58(i) == 1) {
            bool ok;
            if (stream) {
                ok = func_001E39E8(snd, i);
            } else {
                ok = func_001E3868(snd, i, pos->x, pos->y, vol);
            }
            if (!ok) {
                return -1;
            }
            D_003EE8E0[i].m_id = id;
            D_003EE8E0[i].m_handle = func_001DEEA0(id);
            D_003EE8E0[i].m_voice = i;
            D_003EE8E0[i].m_priority = priority;
            D_003EE8E0[i].m_time = func_0010FA80();
            D_003EE8E0[i].m_24 = func_001E13A0(snd);
            return i;
        }
        if (D_003EE8E0[i].m_priority <= bestPriority) {
            if (D_003EE8E0[i].m_priority != bestPriority || D_003EE8E0[i].m_time < bestTime) {
                bestPriority = D_003EE8E0[i].m_priority;
                bestTime = D_003EE8E0[i].m_time;
                best = i;
            }
        }
    }
    if (priority < bestPriority) {
        return -1;
    }
    func_001E3978(best, 1);
    bool ok;
    if (stream) {
        ok = func_001E39E8(snd, best);
    } else {
        ok = func_001E3868(snd, best, pos->x, pos->y, vol);
    }
    if (!ok) {
        return -1;
    }
    D_003EE8E0[best].m_id = id;
    D_003EE8E0[best].m_handle = func_001DEEA0(id);
    D_003EE8E0[best].m_voice = best;
    D_003EE8E0[best].m_priority = priority;
    D_003EE8E0[best].m_time = func_0010FA80();
    D_003EE8E0[best].m_24 = func_001E13A0(snd);
    return best;
}
