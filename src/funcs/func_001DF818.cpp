/* sym: __15Params_001DF818 = 0x001DC540 */
/* sym: _$_15Params_001DF818 = 0x001DC578 */

class Params_001DF818 {
public:
    int m_data[8];
    Params_001DF818();
    ~Params_001DF818();
};

struct Entry_001DF818 {
    int m0;
    int m_id;
    float m_volume;
    float m_pitch;
    char m_pad[0x28 - 0x10];
};

extern Entry_001DF818 D_003EE8E0[];

extern "C" bool func_001DED40(int id);
extern "C" void func_001DC6D0(Params_001DF818* p);
extern "C" int func_001DF1C8(int id, Params_001DF818* p, int a, int owner, int flags, float f);

extern "C" int func_001DF818(int id, int a)
{
    if (func_001DED40(id))
        return 0;
    Params_001DF818 params;
    func_001DC6D0(&params);
    int index = func_001DF1C8(id, &params, a, id, 1, 0.0f);
    if (index != -1) {
        D_003EE8E0[index].m_pitch = 1020.0f;
        D_003EE8E0[index].m_volume = 100.0f;
        return D_003EE8E0[index].m_id;
    }
    return 0;
}
